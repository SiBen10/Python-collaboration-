#include "monty.h"

/**
 * the_sub_opcode - Function that subtracts the top element of the
 * stack from the second top element of the stack
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_sub_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	value -= (*stack)->next->n;
	value *= -1;
	the_pop_opcode(stack, line_number);
	(*stack)->n = value;
}
