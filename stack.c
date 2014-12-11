/*
 * I like my name, but I don't need it here
 */
#include "stack.h"
#include <stdlib.h>
#include <string.h>

/* "private" stack functions */
void grow(Stack *stack)
{
	stack->allocated *= 2;
	stack->data = realloc(stack->data, stack->allocated * stack->membsize);
}

void stack_init(Stack *stack, int membsize)
{
	stack->membsize = membsize;
	stack->allocated = 1;
	stack->nmemb = 0;
	stack->data = NULL;
	grow(stack);
}

void stack_push(Stack *stack, void *new_data)
{
	if (stack->nmemb >= stack->allocated)
		grow(stack);

	memmove((stack + stack->nmemb), new_data, stack->membsize);
	stack->nmemb += 1;
}

/* unfortunately this has to return malloc'd data, so it is the
 * user's responsibility to free it, sorry
 * oh gosh, they'll also have to check for error values... Like if
 * there isn't enough memory to malloc, or they have zero values to pop.
 */
void *stack_pop(Stack *stack)
{
	void *ret = malloc(stack->membsize);

	if (ret == NULL)
		return NULL;

	if (stack->nmemb <= 0) {
		free(ret);
		return NULL;
	}

	/* subtrack before memmove to line up the pointer */
	stack->nmemb -= 1;
	memmove(ret, (stack + stack->nmemb), stack->membsize);


	return ret;
}
