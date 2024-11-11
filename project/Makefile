#configure the makefile
COMMON_OBJECTS	= main.o led.o led_pattern.o switches.o
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU}
LDFLAGS		= -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: toy.elf


toy.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ timerLib/libTimer.a

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

main.o: led.h

wdInterruptHandler.o: led.h
led.o: led.h led.c
