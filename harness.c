#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int test_stack()
{
	Stack s;
	int i, *tmp;

	stack_init(&s, sizeof(int));

	for (i = 0; i < 10; i++)
		stack_push(&s, (void *)&i);

	for (i = 0; i < 10; i++) {
		printf("%d,", *(tmp = (int *)stack_pop(&s)));
		free(tmp);
	}

	return 0;
}

int main()
{
	test_stack();
}
