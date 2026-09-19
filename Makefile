
RAYLIB_PATH := /C/raylib/raylib/src

CC := gcc
CFLAGS  := -Wall -std=c99 -Wno-missing-braces -Wno-unused-variable 
LDLIBS := -lraylib  -lm

ARGS =

all: main.exe 

main.exe : renderer.o draw.o global.o util.o mathD.o logger.o objects.o main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

renderer.o: renderer.c renderer.h global.h
	$(CC) $(CFLAGS) -c $<  -o $@

draw.o: draw.c draw.h global.h
	$(CC) $(CFLAGS) -c $<  -o $@

global.o: global.c global.h
	$(CC) $(CFLAGS) -c $<  -o $@

util.o: util.c util.h global.h
	$(CC) $(CFLAGS) -c $<  -o $@

mathD.o: mathD.c mathD.h 
	$(CC) $(CFLAGS) -c $<  -o $@

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c $<  -o $@

objects.o: objects.c objects.h
	$(CC) $(CFLAGS) -c $<  -o $@

test.exe: test.o mathD.o
	$(CC) $(CFLAGS) $^ -o $@  -L$(LDFLAGS) $(LDLIBS)

test.o: test.c
	$(CC) $(CFLAGS) -c $<  -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $<  -o $@

run: main.exe
	./main.exe $(ARGS)

clean:
	rm -f *.o *.exe

