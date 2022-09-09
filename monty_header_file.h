#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
stack_t *create_node(int n);
typedef void (*op_func)(stack_t **, unsigned int);
int parse_line(char *buffer, int line_number, int format);
int len_chars(FILE *);
void read_file(FILE *);
void find_function(char *, char *, int, int);
void call_function(op_func, char *, char *, int, int);
void open_file(char *file_name);
void free_nodes(void);
void the_pall_opcode(stack_t **, unsigned int);
void the_push_opcode(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void the_pint_opcode(stack_t **, unsigned int);
void the_pop_opcode(stack_t **, unsigned int);
void the_nop_opcode(stack_t **, unsigned int);
void the_swap_opcode(stack_t **, unsigned int);
void the_add_opcode(stack_t **, unsigned int);
void the_sub_opcode(stack_t **, unsigned int);
void the_div_opcode(stack_t **, unsigned int);
void the_mul_opcode(stack_t **, unsigned int);
void the_mod_opcode(stack_t **, unsigned int);
void the_pchar_opcode(stack_t **, unsigned int);
void the_pstr_opcode(stack_t **, unsigned int);
void the_rotl_opcode(stack_t **, unsigned int);
void error_handling(int error_code, ...);
void the_rotr_opcode(stack_t **, unsigned int);

#endif
