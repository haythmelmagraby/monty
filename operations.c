#include "monty.h"

/**
 * mul_top_nodes - Adds the top two elements of the stack
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void mul_top_nodes(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err_extend(8, line, "mul");

	(*s) = (*s)->next;
	result = (*s)->n * (*s)->prev->n;
	(*s)->n = result;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * mod_top_nodes - the rest of the division of the second top element
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void mod_top_nodes(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		err_extend(8, line, "mod");


	if ((*s)->n == 0)
		err_extend(9, line);
	(*s) = (*s)->next;
	result = (*s)->n % (*s)->prev->n;
	(*s)->n = result;
	free((*s)->prev);
	(*s)->prev = NULL;
}
