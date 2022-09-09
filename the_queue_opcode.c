#include "monty.h"

/**
 * the_queue_opcode - Function that sets the format of the data to a queue (FIFO).
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_queue_opcode(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}