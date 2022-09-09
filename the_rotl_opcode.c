#include "monty.h"

/**
* the_rotl_opcode - Function that rotates the stack to the top
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned integer
* Return: void
*/
void the_rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *copystack = *stack;

	UNUSED(line_number);
	if ((*stack)->next == NULL || *stack == NULL)
		return;
	while (copystack->next != NULL)
	{
		copystack = copystack->next;
	}
	copystack->next = (*stack);
	(*stack)->prev = copystack;
	(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
