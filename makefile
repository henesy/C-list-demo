CC=gcc
CFLAGS=-fplan9-extensions

all: list.c list.h main.c
	$(CC) $(CFLAGS) list.c main.c

clean: a.out
	rm a.out
