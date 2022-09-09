#include "monty.h"

/**
 * free_stack - free memory in doubly linked list.
 * @stack: doubly linked list representation of a stack (or queue)
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;
	while (1)
	{
		tmp = *stack;
		if ((*stack)->next == NULL)
		{
			free(tmp);
			*stack = NULL;
			break;
		}
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
