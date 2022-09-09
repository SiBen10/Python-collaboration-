#include "monty.h"

/**
 * open_file - function that opens a file
 * @file_name: char
 * Return: void
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - function that reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parse_line - function that separates each line into tokens to determine
 * which function to call
 * @buffer: char
 * @line_number: int
 * @format:  int
 * Return: (0)
 */
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, format);
	return (format);
}

/**
 * find_function - function that finds the appropriate function for the opcode
 * @opcode: char
 * @value: char
 * @line_number: int
 * @format:  int
 * Return: void
 */
void find_function(char *opcode, char *value, int line_number, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", the_push_opcode},
		{"pall", the_pall_opcode},
		{"pint", the_pint_opcode},
		{"pop", the_pop_opcode},
		{"nop", the_nop_opcode},
		{"swap", the_swap_opcode},
		{"add", the_add_opcode},
		{"sub", the_sub_opcode},
		{"div", the_div_opcode},
		{"mul", the_mul_opcode},
		{"mod", the_mod_opcode},
		{"pchar", the_pchar_opcode},
		{"pstr", the_pstr_opcode},
		{"rotl", the_rotl_opcode},
		{"rotr", the_rotr_opcode},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line_number, opcode);
}

/**
 * call_function - function that calls the required function.
 * @func: pointer
 * @op: char
 * @value: char
 * @line_number: int
 * @format: int
 * Return: void
 */
void call_function(op_func func, char *op, char *value, int line_number, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, line_number);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, line_number);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, line_number);
		if (format == 1)
			add_to_queue(&node, line_number);
	}
	else
		func(&head, line_number);
}
