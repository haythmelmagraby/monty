#include "monty.h"

/**
 * nop- suppress copiler warning
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void nop(stack_t **s, unsigned int line)
{
	(void)s;
	(void)line;
}


/**
 * swap_top_nodes - Swaps the top two elements of the stack
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void swap_top_nodes(stack_t **s, unsigned int line)
{
	stack_t *tmp_node;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err_extend(8, line, "swap");
	tmp_node = (*s)->next;
	(*s)->next = tmp_node->next;
	if (tmp_node->next != NULL)
		tmp_node->next->prev = *s;
	tmp_node->next = *s;
	(*s)->prev = tmp_node;
	tmp_node->prev = NULL;
	*s = tmp_node;
}

/**
 * add_top_nodes - Adds the top two elements of the stack
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void add_top_nodes(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err_extend(8, line, "add");

	(*s) = (*s)->next;
	result = (*s)->n + (*s)->prev->n;
	(*s)->n = result;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * sub_top_nodes- sub the first tow element
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void sub_top_nodes(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)

		err_extend(8, line, "sub");


	(*s) = (*s)->next;
	result = (*s)->n - (*s)->prev->n;
	(*s)->n = result;
	free((*s)->prev);
	(*s)->prev = NULL;
}


/**
 * div_top_nodes - devid first tow element
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void div_top_nodes(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		err_extend(8, line, "div");

	if ((*s)->n == 0)
		err_extend(9, line);
	(*s) = (*s)->next;
	result = (*s)->n / (*s)->prev->n;
	(*s)->n = result;
	free((*s)->prev);
	(*s)->prev = NULL;
}
