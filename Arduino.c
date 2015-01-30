#include "Arduino.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned long millis_timer_overflow_count = 0;
#define MillisTimer_Prescale_Value (64)
#define ToneTimer_Prescale_Value (64)

void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *reg, *out;

	reg = portModeRegister(port);
	out = portOutputRegister(port);

	if (mode == INPUT) {
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out &= ~bit;
		SREG = oldSREG;
	} else if (mode == INPUT_PULLUP) {
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out |= bit;
		SREG = oldSREG;
	} else {
		uint8_t oldSREG = SREG;
                cli();
		*reg |= bit;
		SREG = oldSREG;
	}
}


static void turnOffPWM(uint8_t timer)
{/*
	#if defined(TCCR0A) && defined(COM0A1)
	if( timer == TIMER0A){
		cbi(TCCR0A, COM0A1);
		cbi(TCCR0A, COM0A0);
	} else
	#endif

	#if defined(TCCR0A) && defined(COM0B1)
	if( timer == TIMER0B){
		cbi(TCCR0A, COM0B1);
		cbi(TCCR0A, COM0B0);
	} else
	#endif

	#if defined(TCCR1A) && defined(COM1A1)
	if( timer == TIMER1A){
		cbi(TCCR1A, COM1A1);
		cbi(TCCR1A, COM1A0);
	} else
	#endif

	#if defined(TCCR1) && defined(COM1A1)
	if(timer == TIMER1A){
		cbi(TCCR1, COM1A1);
		cbi(TCCR1, COM1A0);
	#ifdef OC1AX
		cbi(TCCR1D, OC1AX);
	#endif
	} else
	#endif

	#if defined(TCCR1A) && defined(COM1B1)
	if( timer == TIMER1B){
		cbi(TCCR1A, COM1B1);
		cbi(TCCR1A, COM1B0);
	#ifdef OC1BV
		cbi(TCCR1D, OC1BV);
	#endif
	} else
	#endif

	#if defined(TCCR1) && defined(COM1B1)
	if( timer == TIMER1B){
		cbi(GTCCR, COM1B1);
		cbi(GTCCR, COM1B0);
	} else
	#endif

    {
    }
*/
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;

	//if (port == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	//if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	out = portOutputRegister(port);

	if (val == LOW) {
		uint8_t oldSREG = SREG;
    cli();
		*out &= ~bit;
		SREG = oldSREG;
	} else {
		uint8_t oldSREG = SREG;
    cli();
		*out |= bit;
		SREG = oldSREG;
	}
}

int digitalRead(uint8_t pin)
{
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	//if (port == NOT_A_PIN) return LOW;

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	//if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}

unsigned long micros()
{
	unsigned long m;
	uint8_t oldSREG = SREG, t;
	cli();
	m = millis_timer_overflow_count;
#if defined(TCNT0) && (TIMER_TO_USE_FOR_MILLIS == 0) && !defined(TCW0)
	t = TCNT0;
#elif defined(TCNT0L) && (TIMER_TO_USE_FOR_MILLIS == 0)
	t = TCNT0L;
#elif defined(TCNT1) && (TIMER_TO_USE_FOR_MILLIS == 1)
	t = TCNT1;
#elif defined(TCNT1L) && (TIMER_TO_USE_FOR_MILLIS == 1)
	t = TCNT1L;
#else
#error Millis()/Micros() timer not defined
#endif
#if defined(TIFR0) && (TIMER_TO_USE_FOR_MILLIS == 0)
	if ((TIFR0 & _BV(TOV0)) && (t < 255))
		m++;
#elif defined(TIFR) && (TIMER_TO_USE_FOR_MILLIS == 0)
	if ((TIFR & _BV(TOV0)) && (t < 255))
		m++;
#elif defined(TIFR1) && (TIMER_TO_USE_FOR_MILLIS == 1)
	if ((TIFR1 & _BV(TOV1)) && (t < 255))
		m++;
#elif defined(TIFR) && (TIMER_TO_USE_FOR_MILLIS == 1)
	if ((TIFR & _BV(TOV1)) && (t < 255))
		m++;
#endif
	SREG = oldSREG;
	return ((m << 8) + t) * (MillisTimer_Prescale_Value / clockCyclesPerMicrosecond());
}

void delay(unsigned long ms)
{
	uint16_t start = (uint16_t)micros();
	while (ms > 0) {
		if (((uint16_t)micros() - start) >= 1000) {
			ms--;
			start += 1000;
		}
	}
}

/* Delay for the given number of microseconds. Assumes a 1, 8, 12, 16, 20 or 24 MHz clock. */
void delayMicroseconds(unsigned int us)
{
	// for the 8 MHz internal clock
	// for a 1 and 2 microsecond delay, simply return. the overhead
	// of the function call takes 14 (16) cycles, which is 2us
	if (us <= 2) return; // = 3 cycles, (4 when true)
		// the following loop takes 1/2 of a microsecond (4 cycles)
		// per iteration, so execute it twice for each microsecond of
		// delay requested.
		us <<= 1; //x2 us, = 2 cycles
		// account for the time taken in the preceeding commands.
		// we just burned 17 (19) cycles above, remove 4, (4*4=16)
		// us is at least 6 so we can substract 4
		us -= 4; // = 2 cycles

		// busy wait
		__asm__ __volatile__ (
		"1: sbiw %0,1" "\n\t" // 2 cycles
		"brne 1b" : "=w" (us) : "0" (us) // 2 cycles
		);
		// return = 4 cycles
}
