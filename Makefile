# Name: Makefile
# Author: Martin Hans
# Copyright: 2015
# License: MIT license

# This is a prototype Makefile. Modify it according to your needs.
# You should at least check the settings for
# DEVICE ....... The AVR device you compile for
# CLOCK ........ Target AVR clock rate in Hertz
# OBJECTS ...... The object files created from your source files. This list is
#                usually the same as the list of source files with suffix ".o".
# PROGRAMMER ... Options to avrdude which define the hardware you use for
#                uploading to the AVR and the interface where this hardware
#                is connected. We recommend that you leave it undefined and
#                add settings like this to your ~/.avrduderc file:
#                   default_programmer = "stk500v2"
#                   default_serial = "avrdoper"
# FUSES ........ Parameters for avrdude to flash the fuses appropriately.

DEVICE     = attiny84
PROGDEVICE = t84
CLOCK      = 8000000
MASTER     = 0
PROGRAMMER = -c usbasp 
OBJECTS    = main.o schedule.o debounce.o irrecv/irrecv.o irsend/irsend.o

# Use the fuse bit calculator at http://www.engbedded.com/fusecalc/ to
# calculate these
# 4 or 8 MHz external crystal or resonator
FUSES       = -U lfuse:w:0x4c:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m

# Tune the lines below only if you know what you are doing:
AVRDUDE = sudo avrdude $(PROGRAMMER) -p $(PROGDEVICE)
COMPILE = avr-gcc -Wall -Os -std=c99 -DF_CPU=4000000 -DF_OSC=$(CLOCK) -DMASTER=$(MASTER) -mmcu=$(DEVICE) -Wl,-gc-sections -ffunction-sections -fdata-sections

CC = $(COMPILE)

# symbolic targets:
all:	main.hex

%.c.o: %.c
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

# Xcode uses the Makefile targets "", "clean" and "install"
install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID main.hex

clean:
	rm -f main.hex main.elf $(OBJECTS)

# file targets:
main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -d main.elf

cpp:
	$(COMPILE) -E main.c
