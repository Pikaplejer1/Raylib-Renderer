.PHONY: all clean run test

RAYLIB_PATH := /C/raylib/raylib/src

CC := gcc
CFLAGS  := -Wall -std=c99 -Wno-missing-braces -Wno-unused-variable -O2
LDLIBS := -lraylib  -lm

ARGS =

all: main.exe 
test: test.exe
	./test.exe


run: main.exe
	./main.exe $(ARGS)

clean:
	rm -f *.o *.exe


main.exe : renderer.o draw.o global.o util.o mathD.o logger.o objects.o main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

test.exe: test.o mathD.o objects.o global.o logger.o
	$(CC) $(CFLAGS) $^ -o $@  -L$(LDFLAGS) $(LDLIBS)




renderer.o: renderer.c renderer.h
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



test.o: test.c mathD.h objects.h
	$(CC) $(CFLAGS) -c $<  -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $<  -o $@


