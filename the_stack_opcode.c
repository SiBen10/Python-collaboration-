#include "monty.h"

/**
 * the_stack_opcode - Function that  sets the format of the data to a stack (LIFO). 
 * This is the default behavior of the program.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_stack_opcode(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
