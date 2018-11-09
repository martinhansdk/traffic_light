/******
 Implementation of a toy traffic light.

 timer 0: light scheduling and button debouncing
 timer 1: IR receive and transmit


 Pin assignments:

 PA0: IR activity indicator LED (debug)
 PA1: red LED
 PA2: yellow LED
 PA3: green LED
 PA4: ISP USCK
 PA5: ISP MISO
 PA6: ISP MOSI, IR TX
 PA7: IR RX

 PB0: XTAL1
 PB1: XTAL2
 PB2: NC
 PB3: ISP NRESET
*******/


#ifndef F_CPU
#error F_CPU not defined
#else

#if F_CPU == 4000000
#else
#error F_CPU must be 4000000
#endif

#endif

#ifndef F_OSC
#error F_OSC not defined
#endif


#include <stdbool.h>
#include <stdint.h>
#include <avr/eeprom.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "schedule.h"
#include "debounce.h"
#include "irrecv/irrecv.h"
#include "irsend/irsend.h"
#include "hal/pins.h"

#define BUTTON_PIN A,PA0
#define IR_SEND_PIN A,PA6
#define RED_PIN A,PA1
#define YELLOW_PIN A,PA2
#define GREEN_PIN A,PA3
#define IR_RECEIVE_PIN A,PA7


#define CMD_SHIFT 10
#define START_BIT      0x80
#define IR_SYNC_CMD    ((uint32_t)(START_BIT | 0x5a))
#define IR_PROGRAM_CMD ((uint32_t)(START_BIT | 0x45))
#define IR_ROLE_CMD    ((uint32_t)(START_BIT | 0x57))

// sync command message format
#define MODE_SHIFT 9

// program command message format
#define INDEX_SHIFT  10
#define RED_SHIFT    9
#define YELLOW_SHIFT 8
#define GREEN_SHIFT  7

volatile int timer_interrupt = 0;
#if MASTER == 1
bool is_master = true;
#else
bool is_master = false;
#endif
bool manual_mode = false;

/**
  light_time contains the global time which is shared by all traffic lights
  The correct state of the lights is computed from this.
  The unit is 1/2 seconds.
*/
#define TIME_UNIT_MS 500
uint16_t light_time = 0;
uint16_t cycle_time = 1;
Schedule schedule;

void set_lights(uint16_t light_time) {
  const LightPattern* pattern = currentPattern(&schedule, light_time);

  if(pattern->red) pin_high(RED_PIN); else pin_low(RED_PIN);
  if(pattern->yellow) pin_high(YELLOW_PIN); else pin_low(YELLOW_PIN);
  if(pattern->green) pin_high(GREEN_PIN); else pin_low(GREEN_PIN);
}

void handle_ir_commands(const decode_results *irdata) {

  unsigned long value = irdata->value;
  int command = (value >> CMD_SHIFT) & 0xff; // 7 bits of command + 1 start bit

  switch(command) {
  case IR_SYNC_CMD:
    manual_mode = (value >> MODE_SHIFT) & 0x1;  // 1 bit
    light_time = value & 0x1ffUL; // 9 bits of time
    break;
  case IR_PROGRAM_CMD:
    {
      int index = (value >> INDEX_SHIFT) & 0x7;  // 3 bit
      int red = (value >> RED_SHIFT) & 0x1; // 1 bit
      int yellow = (value >> YELLOW_SHIFT) & 0x1; // 1 bit
      int green = (value >> GREEN_SHIFT) & 0x1; // 1 bit
      int duration = value & 0x7f; // 7 bits of duration
      setPattern(&schedule, index, duration, red, yellow, green);
    }
    break;
  case IR_ROLE_CMD:
    is_master = value & 0x1;
    break;
  default:
    break;
  }
}

bool RawKeyPressed() {
    return get_input(BUTTON_PIN);
}

// timer compare interrupt service routine, called once every 1 ms
uint16_t timer_int_count = 0;

ISR(TIM0_COMPA_vect)
{
  bool button_changed, button_pressed;

  timer_int_count++;
  if(timer_int_count >= TIME_UNIT_MS) {
      timer_interrupt = 1;
      timer_int_count = 0;
  }

  DebounceSwitch(&button_changed, &button_pressed);
}

decode_results irdata = {
    .value = 0
};

int main() {
#if F_OSC == 4000000
  // system clock = oscillator/1 = 4 MHz
  clock_prescale_set(clock_div_1);
#elif F_OSC == 8000000
  // system clock = oscillator/2 = 4 MHz
  clock_prescale_set(clock_div_2);
#elif F_OSC == 16000000
  // system clock = oscillator/4 = 4 MHz
  clock_prescale_set(clock_div_4);
#else
#error Unsupported F_CPU
#endif

  // define schedule
  int i = 0;

  setPattern(&schedule, i++, 2*2, true, true, false); // yellow/red
  setPattern(&schedule, i++, 18*2, false, false, true); // green
  setPattern(&schedule, i++, 4*2, false, true, false); // yellow
  // the duration of the red signal must be just so long that the light pointing
  // in the other direction can cycle through yellow-green-yellow plus a
  // little margin where both are red
  setPattern(&schedule, i, 0, false, false, false); // temporary end marker, remove this when beginning to make intersections
  uint16_t red_duration = cycleTime(&schedule) + 1*2;
  setPattern(&schedule, i++, red_duration, true, false, false); // red
  setPattern(&schedule, i, 0, false, false, false); // end marker

/*
  setPattern(&schedule, i++, 1*2, false, true, false); // yellow
  setPattern(&schedule, i++, 1*2, false, false, false); // off
  setPattern(&schedule, i, 0, false, false, false); // end marker
*/

  cycle_time = cycleTime(&schedule);


  // Set LED ports to output
  set_dir_out(RED_PIN);
  set_dir_out(YELLOW_PIN);
  set_dir_out(GREEN_PIN);

  pin_high(RED_PIN);
  pin_high(GREEN_PIN);
  
  // initialize timer0, trigger compare interrupt once every 1 ms
  TCCR0A = 0x02;      // Clear Timer on Compare Match (CTC) mode
  TIFR0 |= 0x01;      // clear interrupt flag
  TIMSK0 = 0x02;      // TC0 compare match A interrupt enable
  TCCR0B = 0x03;      // clock source CLK/64, start timer

#if F_CPU == 4000000
  OCR0A  = 62;        // number to count up to
#elif F_CPU == 8000000
  OCR0A  = 125;       // number to count up to
#elif F_CPU == 16000000
  OCR0A  = 250;       // number to count up to
#else
#error Unsupported F_CPU
#endif

  setup_irrecv();

  sei();             // enable all interrupts

  while(1) {
      // wait until timer isr was run
      while(true) {
        if (irrecv_decode(&irdata)) {
          handle_ir_commands(&irdata);
          irrecv_resume();
        }
        if(timer_interrupt) break;
      }
      timer_interrupt = 0;

      light_time++;

      if(light_time >= cycle_time) {
        light_time %= cycle_time;
      }

      if(is_master) {
        irsend_sendRC5((IR_SYNC_CMD<<CMD_SHIFT) | (manual_mode << MODE_SHIFT) | light_time, 18);
      }

      set_lights(light_time);
  }
}
