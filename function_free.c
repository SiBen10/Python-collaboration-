#include "monty.h"

/**
 * free_stack - function that frees a stack
 * @head: doubly linked list represented as a stack
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	free_stack(head->next);
	free(head);
}
