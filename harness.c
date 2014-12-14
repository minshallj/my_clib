#include "stack.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int test_stack()
{
	Stack s;
	int i, *tmp;

	printf("\n\ttest stack starting\n");
	stack_init(&s, sizeof(int));

	for (i = 0; i < 10; i++)
		stack_push(&s, (void *)&i);

	for (i = 0; i < 10; i++) {
		printf("%d,", *(tmp = (int *)stack_pop(&s)));
		free(tmp);
	}
	printf("\n\ttest stack finished\n");

	return 0;
}

int test_list(int prepend)
{
	LinkedList l;
	int i, *tmp;

	printf("\n\ttest list %s starting\n", prepend ? "prepend" : "append");
	linked_list_init(&l);

	for (i = 0; i < 10; i++)
		if (prepend)
			linked_list_prepend(&l, &i, sizeof(int));
		else
			linked_list_append(&l, &i, sizeof(int));

	for (i = 0; i < 10; i++) {
		tmp = linked_list_index(&l, i+1);
		if (tmp != NULL) {
			printf("%d,", *tmp);
			free(tmp);
		} else {
			printf("\tGot null on %d\n", i);
		}
	}
	/*
	for (i = 0; i < 5; i++)
		linked_list_remove_index(&l, 1);
	printf("\njust removed everything\n");

	for (i = 0; i < 10; i++) {
		tmp = linked_list_index(&l, i+1);
		if (tmp != NULL) {
			printf("%d,", *tmp);
			free(tmp);
		} else {
			printf("\tGot null on %d\n", i);
		}
	}
	*/
	printf("\n\ttest list finished\n");

	return 0;
}

int main()
{
	test_stack();
	test_list(1);
	test_list(0);
}
