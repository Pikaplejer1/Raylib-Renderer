
RAYLIB_PATH := /C/raylib/raylib/src

CC := gcc
CFLAGS  := -Wall -std=c99 -Wno-missing-braces -Wno-unused-variable 
CPPFLAGS := $(RAYLIB_PATH)
LDFLAGS := $(RAYLIB_PATH)
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

ARGS =

all: renderer.exe 

renderer.exe: renderer.o draw.o global.o util.o mathD.o logger.o
	$(CC) $(CFLAGS) $^ -o $@ -I$(CPPFLAGS) -L$(LDFLAGS) $(LDLIBS)

renderer.o: renderer.c renderer.h global.h
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

draw.o: draw.c draw.h global.h
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

global.o: global.c global.h
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

util.o: util.c util.h global.h
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

mathD.o: mathD.c mathD.h 
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@


test.exe: test.o mathD.o
	$(CC) $(CFLAGS) $^ -o $@ -I$(CPPFLAGS) -L$(LDFLAGS) $(LDLIBS)

test.o: test.c
	$(CC) $(CFLAGS) -c $< -I$(CPPFLAGS) -o $@

run: renderer.exe
	./renderer.exe $(ARGS)

clean:
	rm -f *.o *.exe

