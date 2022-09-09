#include "monty.h"

/**
* the_pstr_opcode - Function that prints the string starting at the
* top of the stack, followed by a new line
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned integer
*/
void the_pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *copystack = *stack;
	int n;

	UNUSED(line_number);

	if (*stack == NULL)
	{
		printf("\n");
	}
	while (copystack && copystack->n != '\0')
	{
		n = copystack->n;

		if (!isascii(n))
		{
			break;
		}
		printf("%c", n);

		copystack = copystack->next;
	}

	printf("\n");
}
