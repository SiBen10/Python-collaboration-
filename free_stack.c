#include "monty.h"

/**
 * free_stack - free a stack
 * @head: doubly linked list represented as a stack
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	free_stack(head->next);
	free(head);
}
