CC=gcc
CFLAGS=-c

default: test

harness.o: harness.c stack.h linked_list.h
	$(CC) $(CFLAGS) harness.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) linked_list.c

test: harness.o stack.o linked_list.o
	$(CC) harness.o stack.o linked_list.o -o test.out

clean:
	rm harness.o stack.o linked_list.o test.out
