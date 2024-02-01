#include "monty.h"

/**
 * my_error - Prints error
 * @code: The error code
 */
void my_error(int code, ...)
{
	va_list args;
	char *operation;
	int line;

	va_start(args, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line = va_arg(args, int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_extend - print error
 * @code: The error coes
 */
void err_extend(int code, ...)
{
	va_list args;
	char *operation;
	int line;

	va_start(args, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * expand__err - print error
 * @code: The error code
 */
void expand__err(int code, ...)
{
	va_list args;
	int line;

	va_start(args, code);
	line = va_arg(args, int);
	switch (code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
