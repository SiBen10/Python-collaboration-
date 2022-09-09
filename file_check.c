#include "monty.h"

char *number;

/**
 * file_check - Function that validates the status of the file
 * @userFile: file to be opened
 * Return: void
 */
void file_check(char *userFile)
{
	FILE *readFile;
	char *buffer = NULL, **command;
	size_t size = 0;
	ssize_t ret;
	int pointer, line = 0, i = 0;
	stack_t *list = NULL;

	readFile = fopen(userFile, "r");
	if (readFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", userFile);
		exit(EXIT_FAILURE);
	}
	while ((ret = getline(&buffer, &size, readFile)) != EOF)
	{
		if (!buffer)
		{
			write(2, "Error: malloc failed\n", 21);
			fclose(readFile);
			exit(EXIT_FAILURE);
		} line += 1;
		if (ret == 1)
			continue;
		else
		{
			i = 0;
			while (buffer[i] == ' ' && buffer[i + 1] == ' ')
				i++;
			if (buffer[i + 1] == '\n')
				continue;
		}
		pointer = _memory(buffer);
		command = validateBuffer(buffer, pointer, readFile);
		op_val(command, buffer, &list, line, readFile);
		free(command);
	}
	free_stack(&list);
	free(buffer);
	fclose(readFile);
}

/**
 * validateBuffer - Function tokenized the variable buffer in command
 * @buffer: is the variable storage in getline
 * @pointer: is the amount of words in the buffer
¨* @montyF: File
 * Return: command
 */
char **validateBuffer(char *buffer, int pointer, FILE *montyF)
{
	char *delim = " \n\t";
	char *tok;
	size_t i;
	char **command;

	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free(buffer);
		fclose(montyF);
		exit(EXIT_FAILURE);
	}
	tok = strtok(buffer, delim);
	i = 0;
	while (tok)
	{
		command[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;
	return (command);
}

/**
 * op_val - Function that uses opcode validate the number of arguments in command
 * @command: is the tokenized of the string in getline
 * @buffer: is the string stored in getline
 * @list: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @a: File
 * Return: void
 */
void op_val(char **command, char *buffer, stack_t **list, int line, FILE *a)
{
	int i = 0;

	while (command[i] != NULL)
		i++;
	if (!(i == 2 || i == 1))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, command[0]);
		free(command);
		free(buffer);
		free_stack(list);
		fclose(a);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
		number = command[1];
	f_opcode(command, buffer, line, list, a);
}

/**
 * f_opcode - is the function that compare the word read in the file for
 * realize a function in the struct instruction_t
 * @command: is the tokenized of the string in getline
 * @buffer: is the string storared in getline
 * @list: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @m: File.
 * Return: void
 */
void f_opcode(char **command, char *buffer, int line, stack_t **list, FILE *m)
{
	int j = 0;
	instruction_t opcodeFunc[] = {
		{"push", the_push_opcode},
		{"pall", the_pall_opcode},
		{"pint", the_pint_opcode},
		{"pop", the_pop_opcode},
		{"swap", the_swap_opcode},
		{"add", the_add_opcode},
		{"nop", the_nop_opcode},
		{"sub", the_sub_opcode},
		{NULL, NULL},
	};

	while (opcodeFunc[j].opcode != NULL)
	{
		if (strcmp(opcodeFunc[j].opcode, command[0]) == 0)
		{
			opcodeFunc[j].f(list, line);
			return;
		}
		j++;
	}
	if (opcodeFunc[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, command[0]);
		free(command);
		free(buffer);
		free_stack(list);
		fclose(m);
		exit(EXIT_FAILURE);
	}
}
