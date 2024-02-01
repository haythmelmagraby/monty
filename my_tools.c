#include "monty.h"

/**
 * of - opens file
 * @file: file name
 */

void of(char *file)
{
	FILE *f = fopen(file, "r");

	if (file == NULL || f == NULL)
		my_error(2, file);

	rf(f);
	fclose(f);
}


/**
 * rf - reads a file
 * @f: file pointer
 */

void rf(FILE *f)
{
	int line, format = 0;
	char *buf = NULL;
	size_t legnth = 0;

	for (line = 1; getline(&buf, &legnth, f) != -1; line++)
	{
		format = pl(buf, line, format);
	}
	free(buf);
}


/**
 * pl- seperate every line with delimeter
 * @buf: line from the file
 * @line: line number
 * @format: storage format
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int pl(char *buf, int line, int format)
{
	char *opcode, *v;
	const char *d = "\n ";

	if (buf == NULL)
		my_error(4);

	opcode = strtok(buf, d);
	if (opcode == NULL)
		return (format);
	v = strtok(NULL, d);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	ff(opcode, v, line, format);
	return (format);
}

/**
 * ff - find the appropriate function for the opcode
 * @opcode: opcode
 * @v: value argument of opcode
 * @format:  storage format
 * @line: line number
 */
void ff(char *opcode, char *v, int line, int format)
{
	int counter, f;

	instruction_t op_list[] = {
		{"push", add_node_to_stack},
		{"pall", print_all_stack},
		{"pint", print_the_top},
		{"pop", pop_node},
		{"nop", nop},
		{"swap", swap_top_nodes},
		{"add", add_top_nodes},
		{"sub", sub_top_nodes},
		{"div", div_top_nodes},
		{"mul", mul_top_nodes},
		{"mod", mod_top_nodes},
		{"pchar", print_char_ascii},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, counter = 0; op_list[counter].opcode != NULL; counter++)
	{
		if (strcmp(opcode, op_list[counter].opcode) == 0)
		{
			cf(op_list[counter].f, opcode, v, line, format);
			f = 0;
		}
	}
	if (f == 1)
		my_error(3, line, opcode);
}


/**
 * cf- Call function
 * @fun: Pointer to the function that called
 * @opcode: the opcode
 * @v: the value
 * @line: line numeber
 * @format: Format specifier
 */
void cf(op_func fun, char *opcode, char *v, int line, int format)
{
	stack_t *node;
	int f;
	int counter;

	f = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			f = -1;
		}
		if (v == NULL)
			my_error(5, line);
		for (counter = 0; v[counter] != '\0'; counter++)
		{
			if (isdigit(v[counter]) == 0)
				my_error(5, line);
		}
		node = create_new_node(atoi(v) * f);
		if (format == 0)
			fun(&node, line);
		if (format == 1)
			add_queue(&node, line);
	}
	else
		fun(&head, line);
}
