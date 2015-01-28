#include <avr/io.h>
#include <avr/interrupt.h>

volatile int timer_overflow_count = 0;

#define RED_PIN PB3
#define YELLOW_PIN PB4
#define GREEN_PIN PB5

/**
  The timing of a traffic light determines how the light_time is translated
  into light patterns. A and B timing are defined such that cars coming from
  A and B direction never have green light at the same time.
*/
typedef enum {A, B} LightTiming;
LightTiming timing = A;

/**
  light_time contains the global time which is shared by all traffic lights
  The correct state of the lights is computed from this.
  The unit is seconds.
*/
int light_time = 0;

/* define the schedule
*/
#define YELLOW_RED_DURATION 1
#define GREEN_DURATION 18
#define YELLOW_DURATION 4
#define BOTH_RED_DURATION 1
// the duration of the red signal must be just so long that the light pointing
// in the other direction can cycle through yellow-green-yellow plus a
// little margin where botgh are red
#define RED_DURATION (YELLOW_RED_DURATION + GREEN_DURATION + YELLOW_DURATION + BOTH_RED_DURATION)

// calculate the cycle time and the switch times based on this
#define CYCLE_TIME  (RED_DURATION + YELLOW_RED_DURATION + GREEN_DURATION + YELLOW_DURATION)
#define SWITCH_TO_YELLOW_RED_TIME (RED_DURATION)
#define SWITCH_TO_GREEN_TIME (SWITCH_TO_YELLOW_RED_TIME + YELLOW_RED_DURATION)
#define SWITCH_TO_YELLOW_TIME (SWITCH_TO_GREEN_TIME + GREEN_DURATION)

// the B timing switches to yellow/red shortly after the A timing
// has switched to red
#define B_OFFSET (SWITCH_TO_YELLOW_RED_TIME - BOTH_RED_DURATION)

void set_lights(int light_time) {
  if(timing == B) {
    light_time = (light_time + B_OFFSET) % CYCLE_TIME;
  }

  int red = 0;
  int yellow = 0;
  int green = 0;

  if(light_time < SWITCH_TO_YELLOW_RED_TIME) {
    red = 1;
  } else if(light_time < SWITCH_TO_GREEN_TIME) {
    red = 1;
    yellow = 1;
  } else if(light_time < SWITCH_TO_YELLOW_TIME) {
    green = 1;
  } else {
    yellow = 1;
  }

  // all off
  PORTB &= ~((1 << RED_PIN) | (1 << YELLOW_PIN) | (1 << GREEN_PIN));
  // turn only the right ones on
  PORTB |= (red << RED_PIN) | (yellow << YELLOW_PIN) | (green << GREEN_PIN);
}


ISR(TIM0_OVF_vect) {
   if (++timer_overflow_count > 5) {   // a timer overflow occurs 4.6 times per second
      light_time = (light_time+1) % CYCLE_TIME;
      set_lights(light_time);
      timer_overflow_count = 0;
   }
}

int main(void) {
   // Set LED ports to output
   DDRB = 1<<RED_PIN | 1<<YELLOW_PIN | 1<<GREEN_PIN;

   // prescale timer to 1/1024th the clock rate
   TCCR0B |= (1<<CS02) | (1<<CS00);

   // enable timer overflow interrupt
   TIMSK |=1<<TOIE0;
   sei();

   while(1) {
      // let ISR handle the LEDs forever
   }
}
