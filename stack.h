/*
 * something profound
 */

#ifndef __STACK_H_
#define __STACK_H_

typedef struct {
	int nmemb, membsize, allocated;
	void *data;
} Stack;

void stack_init(Stack *stack, int membsize);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void stack_free(Stack *stack);
#endif
