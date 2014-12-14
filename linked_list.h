/*
 * always start with a comment
 */
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct linked_node {
	struct linked_node *next;
	void *data;
	int data_size;
};
typedef struct linked_node LinkedNode;

struct linked_list {
	LinkedNode *head;
};
typedef struct linked_list LinkedList;

void linked_list_init(LinkedList *l);
/* index is one based */
void *linked_list_index(LinkedList *l, int index);
/* index is one based */
void linked_list_remove_index(LinkedList *l, int index);
void linked_list_append(LinkedList *l, void *data, int data_size);
void linked_list_prepend(LinkedList *l, void *data, int data_size);
/* TODO: add a list_insert_sorted method */
#endif
