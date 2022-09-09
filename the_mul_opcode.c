#include "monty.h"

/**
 * the_mul_opcode - Function that multiplies the second top element
 * of the stack with the top element of the stack
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_mul_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
		return;
	}

	current = *stack;
	current = current->next;
	current->n = current->n * (*stack)->n;
	free(*stack);
	current->prev = NULL;
	*stack = current;
}
