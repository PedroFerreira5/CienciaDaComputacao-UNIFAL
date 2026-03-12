CC = gcc
CFLAGS = -Wall -O2

all: main

main: main.o heap.o
	$(CC) $(CFLAGS) main.o heap.o -o heap

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

clean:
	rm -f *.o heap
