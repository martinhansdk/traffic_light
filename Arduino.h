#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define INPUT_PULLUP 0x2
#define true 0x1
#define false 0x0

static inline unsigned long clockCyclesPerMicrosecond() __attribute__ ((always_inline));
static inline unsigned long clockCyclesPerMicrosecond()
{
  //Inline function will be optimised out.
  return 1;
}

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
//
// These perform slightly better as macros compared to inline functions
//
#define digitalPinToPort(P) ( P )
#define digitalPinToBitMask(P) ( P )
#define digitalPinToTimer(P) ( P )

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);

#define NULL 0

#define portOutputRegister(P) ( (volatile uint8_t *) NULL)
#define portInputRegister(P) ( (volatile uint8_t *) NULL)
#define portModeRegister(P) ( (volatile uint8_t *) NULL)


#ifdef __cplusplus
} // extern "C"
#endif

#endif
