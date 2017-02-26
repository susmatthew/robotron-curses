#this is a makefile
CC = gcc
CFLAGS = -Wall -g -std=c99 -lncurses
DEPS = roboengine.h robocurse.h
OBJ = roboengine.o robocurse.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

robomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)