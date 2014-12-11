#include "stack.h"
#include <stdio.h>

int test_stack()
{
	Stack s;
	int i;

	stack_init(&s, sizeof(int));

	for (i = 0; i < 10; i++)
		stack_push(&s, (void *)&i);

	for (i = 0; i < 10; i++)
		printf("%d,", *(int *)stack_pop(&s));

	return 0;
}

int main()
{
	test_stack();
}
