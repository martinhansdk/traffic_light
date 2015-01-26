#include <avr/interrupt.h>

volatile int timer_overflow_count = 0;

ISR(TIM0_OVF_vect) {
   if (++timer_overflow_count > 5) {   // a timer overflow occurs 4.6 times per second
      // Toggle Port B pin 4 output state
      PORTB ^= 1<<PB4;
      timer_overflow_count = 0;
   }
}

int main(void) {
   // Set up Port B pin 4 mode to output
    DDRB = 1<<DDB4;

   // prescale timer to 1/1024th the clock rate
   TCCR0B |= (1<<CS02) | (1<<CS00);

   // enable timer overflow interrupt
   TIMSK |=1<<TOIE0;
   sei();

   while(1) {
      // let ISR handle the LED forever
   }
}
