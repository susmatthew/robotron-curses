#this is a makefile

CFLAGS=-Wall -g -std=c99

all:
	gcc -Wall robocurse.c roboengine.c -o robocurse -lncurses

clean:
	rm -f robocurse
