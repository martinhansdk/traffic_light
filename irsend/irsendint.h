
#ifndef _IRSENDINT_H
#define _IRSENDINT_H

#include <avr/interrupt.h>


#define SYSCLOCK F_CPU	// CPU clock frequency

#define TOPBIT 0x80000000

// Pulse parms are *50-100 for the Mark and *50+100 for the space
// First MARK is the one after the long gap
// pulse parameters in usec
#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1600
#define NEC_ZERO_SPACE	560
#define NEC_RPT_SPACE	2250

#define SONY_HDR_MARK	2400
#define SONY_HDR_SPACE	600
#define SONY_ONE_MARK	1200
#define SONY_ZERO_MARK	600
#define SONY_RPT_LENGTH 45000
#define SONY_DOUBLE_SPACE_USECS  500  // usually ssee 713 - not using ticks as get number wrapround

// SA 8650B
#define SANYO_HDR_MARK	3500  // seen range 3500
#define SANYO_HDR_SPACE	950 //  seen 950
#define SANYO_ONE_MARK	2400 // seen 2400
#define SANYO_ZERO_MARK 700 //  seen 700
#define SANYO_DOUBLE_SPACE_USECS  800  // usually ssee 713 - not using ticks as get number wrapround
#define SANYO_RPT_LENGTH 45000

// Mitsubishi RM 75501
// 14200 7 41 7 42 7 42 7 17 7 17 7 18 7 41 7 18 7 17 7 17 7 18 7 41 8 17 7 17 7 18 7 17 7

// #define MITSUBISHI_HDR_MARK	250  // seen range 3500
#define MITSUBISHI_HDR_SPACE	350 //  7*50+100
#define MITSUBISHI_ONE_MARK	1950 // 41*50-100
#define MITSUBISHI_ZERO_MARK  750 // 17*50-100
// #define MITSUBISHI_DOUBLE_SPACE_USECS  800  // usually ssee 713 - not using ticks as get number wrapround
// #define MITSUBISHI_RPT_LENGTH 45000


#define RC5_T1		889
#define RC5_RPT_LENGTH	46000

#define RC6_HDR_MARK	2666
#define RC6_HDR_SPACE	889
#define RC6_T1		444
#define RC6_RPT_LENGTH	46000

#define SHARP_BIT_MARK 245
#define SHARP_ONE_SPACE 1805
#define SHARP_ZERO_SPACE 795
#define SHARP_GAP 600000
#define SHARP_TOGGLE_MASK 0x3FF
#define SHARP_RPT_SPACE 3000

#define DISH_HDR_MARK 400
#define DISH_HDR_SPACE 6100
#define DISH_BIT_MARK 400
#define DISH_ONE_SPACE 1700
#define DISH_ZERO_SPACE 2800
#define DISH_RPT_SPACE 6200
#define DISH_TOP_BIT 0x8000

#define PANASONIC_HDR_MARK 3502
#define PANASONIC_HDR_SPACE 1750
#define PANASONIC_BIT_MARK 502
#define PANASONIC_ONE_SPACE 1244
#define PANASONIC_ZERO_SPACE 400

#define JVC_HDR_MARK 8000
#define JVC_HDR_SPACE 4000
#define JVC_BIT_MARK 600
#define JVC_ONE_SPACE 1600
#define JVC_ZERO_SPACE 550
#define JVC_RPT_LENGTH 60000

#define LG_HDR_MARK 8000
#define LG_HDR_SPACE 4000
#define LG_BIT_MARK 600
#define LG_ONE_SPACE 1600
#define LG_ZERO_SPACE 550
#define LG_RPT_LENGTH 60000

#define SAMSUNG_HDR_MARK  5000
#define SAMSUNG_HDR_SPACE 5000
#define SAMSUNG_BIT_MARK  560
#define SAMSUNG_ONE_SPACE 1600
#define SAMSUNG_ZERO_SPACE  560
#define SAMSUNG_RPT_SPACE 2250


#define SHARP_BITS 15
#define DISH_BITS 16

#define TIMER_RESET
#define TIMER_ENABLE_PWM     (TCCR1A |= _BV(COM1A1))
#define TIMER_DISABLE_PWM    (TCCR1A &= ~(_BV(COM1A1)))
#if defined(__AVR_ATmega8P__) || defined(__AVR_ATmega8__)
  #define TIMER_ENABLE_INTR    (TIMSK = _BV(OCIE1A))
  #define TIMER_DISABLE_INTR   (TIMSK = 0)
#else
  #define TIMER_ENABLE_INTR    (TIMSK1 = _BV(OCIE1A))
  #define TIMER_DISABLE_INTR   (TIMSK1 = 0)
#endif
#define TIMER_INTR_NAME      TIMER1_COMPA_vect
#define TIMER_CONFIG_KHZ(val) ({ \
  const uint16_t pwmval = SYSCLOCK / 2000 / (val); \
  TCCR1A = _BV(WGM11); \
  TCCR1B = _BV(WGM13) | _BV(CS10); \
  ICR1 = pwmval; \
  OCR1A = pwmval / 3; \
})
#define TIMER_CONFIG_NORMAL() ({ \
  TCCR1A = 0; \
  TCCR1B = _BV(WGM12) | _BV(CS10); \
  OCR1A = SYSCLOCK * USECPERTICK / 1000000; \
  TCNT1 = 0; \
})
#if defined(CORE_OC1A_PIN)
#define TIMER_PWM_PIN        CORE_OC1A_PIN  /* Teensy */
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define TIMER_PWM_PIN        11  /* Arduino Mega */
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
#define TIMER_PWM_PIN        13 /* Sanguino */
#else
#define TIMER_PWM_PIN        9  /* Arduino Duemilanove, Diecimila, LilyPad, etc */
#endif

#endif