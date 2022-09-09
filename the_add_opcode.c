#include "monty.h"

/**
 * the_add_opcode - Function that adds the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_add_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	value += (*stack)->next->n;
	the_pop_opcode(stack, line_number);
	(*stack)->n = value;
}
