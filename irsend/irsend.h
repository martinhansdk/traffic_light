#ifndef _IRSEND_H
#define _IRSEND_H

/*
* IRremote's send code for attiny44/attiny45 and similar.
*
* Based on https://github.com/shirriff/Arduino-IRremote
*
*/

void irsend_sendNEC(unsigned long data, int nbits);
void irsend_sendSony(unsigned long data, int nbits);
// Neither Sanyo nor Mitsubishi send is implemented yet
// void sendSanyo(unsigned long data, int nbits);
// void sendMitsubishi(unsigned long data, int nbits);
void irsend_sendRaw(unsigned int buf[], int len, int hz);
void irsend_sendRC5(unsigned long data, int nbits);
void irsend_sendRC6(unsigned long data, int nbits);
void irsend_sendDISH(unsigned long data, int nbits);
void irsend_sendSharp(unsigned int address, unsigned int command);
void irsend_sendSharpRaw(unsigned long data, int nbits);
void irsend_sendPanasonic(unsigned int address, unsigned long data);
void irsend_sendJVC(unsigned long data, int nbits, int repeat); // *Note instead of sending the REPEAT constant if you want the JVC repeat signal sent, send the original code value and change the repeat argument from 0 to 1. JVC protocol repeats by skipping the header NOT by sending a separate code value like NEC does.
void irsend_sendSAMSUNG(unsigned long data, int nbits);
void enableIROut(int khz);
void mark(int usec);
void space(int usec);

// Some useful constants
#define USECPERTICK 50 // microseconds per clock interrupt tick

#endif
