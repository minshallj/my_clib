CC=gcc
CFLAGS=-c

default: test

harness.o: harness.c stack.h
	$(CC) $(CFLAGS) harness.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

test: harness.o stack.o
	$(CC) harness.o stack.o -o test.out

