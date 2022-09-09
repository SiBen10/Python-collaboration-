#include "monty.h"

/**
* the_pchar_opcode - function that prints the char at the top of the 
* stack, followed by a new line
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned integer
* Return: void
*/
void the_pchar_opcode(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *copystack = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (!isascii(n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", copystack->n);
}
