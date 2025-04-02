CC = gcc
CFLAGS = -lncurses -lm -I./include/
SOURCES = ./src/*.c

all: rogue run clean

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

debug:
	$(CC) $(SOURCES) $(CFLAGS) -g -o rogue
	gdb

run:
	./rogue

clean:
	rm rogue