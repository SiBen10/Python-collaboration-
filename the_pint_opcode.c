#include "monty.h"

/**
 * the_pint_opcode - Function that prints the value at the top of the stack, 
 * followed by a new line.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_pint_opcode(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
