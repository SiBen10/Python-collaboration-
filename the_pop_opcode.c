#include "monty.h"

/**
 * the_pop_opcode - Function that removes the top element of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
	{
		free(tmp);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
