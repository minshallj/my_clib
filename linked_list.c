/*
 * something something dark side
 */
#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

void linked_list_init(LinkedList *l)
{
	l->head = NULL;
}

void *linked_list_index(LinkedList *l, int index)
{
	void *ret;
	int i = 1;
	LinkedNode *tmp = l->head;

	/* TODO: after adding size, have check for index > size */
	if (index < 1)
		return NULL;

	while (tmp != NULL) {
		if (i != index) {
			tmp = tmp->next;
			i++;
			continue;
		}
		/* we are at the proper index here */
		ret = malloc(tmp->data_size);
		if (ret == NULL)
			return NULL;
		memmove(ret, tmp->data, tmp->data_size);
		return ret;
	}
	return NULL;
}

void linked_list_remove_index(LinkedList *l, int index)
{
	LinkedNode *prev, *cur;
	int i;

	cur = l->head;
	/* no need to remove if it's null */
	if (cur == NULL)
		return;

	/* TODO: after adding size, have check for index > size */
	if (index == 1) {
		l->head = l->head->next;
		free(cur->data);
		free(cur);
		return;
	}

	i = 1;
	prev = cur;
	cur = prev->next;
	while (cur != NULL) {
		if (++i == index) {
			prev->next = cur->next;
			free(cur->data);
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	/* index must have been > size of the linked list, oh well */
	return;
}

void linked_list_append(LinkedList *l, void *data, int data_size)
{
	LinkedNode *cur, *prev, *new_node;

	/* set up the new node */
	new_node = (LinkedNode *)malloc(sizeof(LinkedNode));
	new_node->data_size = data_size;
	new_node->next = NULL;
	new_node->data = malloc(data_size);
	memmove(new_node->data, data, data_size);

	/* special case for null head */
	if (l->head == NULL) {
		l->head = new_node;
		return;
	}

	prev = l->head;
	cur = prev->next;
	while (cur != NULL) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = new_node;
}

void linked_list_prepend(LinkedList *l, void *data, int data_size)
{
	LinkedNode *ln = (LinkedNode *)malloc(sizeof(LinkedNode));

	ln->data_size = data_size;
	ln->data = malloc(data_size);
	memmove(ln->data, data, data_size);

	ln->next = l->head;
	l->head = ln;
}

void linked_list_free(LinkedList *l)
{
	LinkedNode *n = l->head, *tmp;

	while (n != NULL) {
		free(n->data);
		tmp = n;
		n = n->next;
		free(tmp);
	}
}
