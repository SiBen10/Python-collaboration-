#include "monty.h"

/**
* the_mod_opcode - Function that computes the rest of the 
* division of the second top element of the stack by the top
* element of the stack
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned int
* Return: void
*/
void the_mod_opcode(stack_t **stack, unsigned int line_number)
{
	int temp1, temp2, remainder;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;
	remainder = temp2 % temp1;

	the_pop_opcode(stack, line_number);
	(*stack)->n = remainder;
}
