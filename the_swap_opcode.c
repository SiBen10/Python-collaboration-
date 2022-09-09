#include "monty.h"

/**
 * the_swap_opcode - Function that swaps the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned int
 * Return: new node at top
 */
void the_swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->next->prev = *stack;
	*stack = tmp;
}
