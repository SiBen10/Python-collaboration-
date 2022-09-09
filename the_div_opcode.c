#include "monty.h"

/**
 *the_div_opcode - divedes the second to top elament of the stack by the top elament
 *@stack: doubly linked list representation of a stack (or queue)
 *@line_number: unsigned integer
 *Return: void
 */
void the_div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	current->n = current->n / (*stack)->n;
	current->prev = NULL;
	free(*stack);
	*stack = current;
}
