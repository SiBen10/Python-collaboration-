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
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
* the_pstr_opcode - Function that prints the string starting at the
* top of the stack, followed by a new line
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned integer
*/
void the_pstr_opcode(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
* the_rotl_opcode - Function that rotates the stack to the top
* @stack: doubly linked list representation of a stack (or queue)
* @line_number: unsigned integer
* Return: void
*/
void the_rotl_opcode(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
