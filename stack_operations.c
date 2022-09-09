#include "monty.h"

/**
 * the_push_opcode - Function that pushes an element to the stack
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_push_opcode(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * the_pop_opcode - Function that removes the top element of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
 * the_nop_opcode - Function with the opcode nop doesn’t do anything.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned integer
 * Return: void
 */
void the_nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * the_swap_opcode - Function that swaps the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: unsigned int
 * Return: new node at top
 */
void the_swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
