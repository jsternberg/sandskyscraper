#!/usr/bin/make -f
# vim: set noexpandtab:

CC=gcc
CFLAGS=-g -Wall -pedantic
OBJECTS=main.o str.o

myecho: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS) : %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
