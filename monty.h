#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO alx project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void file_check(char *userFile);
char **validateBuffer(char *buffer, int pointer, FILE *montyF);
void op_val(char **command, char *buffer, stack_t **list, int line, FILE *a);
void f_opcode(char **command, char *buffer, int line, stack_t **list, FILE *m);
int _memory(char *buffer);
void free_stack(stack_t **stack);
void the_push_opcode(stack_t **stack, unsigned int line_number);
void the_pall_opcode(stack_t **stack, unsigned int line_number);
void the_pint_opcode(stack_t **stack, unsigned int line_number);
void the_pop_opcode(stack_t **stack, unsigned int line_number);
void the_swap_opcode(stack_t **stack, unsigned int line_number);
void the_add_opcode(stack_t **stack, unsigned int line_number);
void the_nop_opcode(stack_t **stack, unsigned int line_number);
void the_sub_opcode(stack_t **stack, unsigned int line_number);
void the_div_opcode(stack_t **stack, unsigned int line_number);
void the_mul_opcode(stack_t **stack, unsigned int line_number);
void the_mod_opcode(stack_t **stack, unsigned int line_number);
void the_pchar_opcode(stack_t **stack, unsigned int line_number);
void the_pstr_opcode(stack_t **stack, unsigned int line_number);
void the_rotr_opcode(stack_t **stack, unsigned int line_number);
void the_rotl_opcode(stack_t **stack, unsigned int line_number);
void the_queue_opcode(stack_t **stack, unsigned int line_number);
void the_stack_opcode(stack_t **stack, unsigned int line_number);

#endif
