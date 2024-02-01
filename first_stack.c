#include "monty.h"


/**
 * add_node_to_stack - Add node to the stack
 * @n: Pointer to the new node
 * @line: line of operation code integer - optional
 */
void add_node_to_stack(stack_t **n, __attribute__((unused))unsigned int line)
{
	stack_t *tmp_node;

	if (n == NULL || *n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n;
		return;
	}
	tmp_node = head;
	head = *n;
	head->next = tmp_node;
	tmp_node->prev = head;
}


/**
 * print_all_stack - print the stack
 * @s: the pointer of the stack
 * @line: line number of  the operation code
 */
void print_all_stack(stack_t **s, unsigned int line)
{
	stack_t *tmp_node;

	(void) line;
	if (s == NULL)
		exit(EXIT_FAILURE);
	tmp_node = *s;
	while (tmp_node != NULL)
	{
		printf("%d\n", tmp_node->n);
		tmp_node = tmp_node->next;
	}
}

/**
 * pop_node - remove last element of the stack
 * @s: the pointer of the stack
 * @line: line number of  the operation code
 */
void pop_node(stack_t **s, unsigned int line)
{
	stack_t *tmp_node;

	if (s == NULL || *s == NULL)
		err_extend(7, line);

	tmp_node = *s;
	*s = tmp_node->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	free(tmp_node);
}

/**
 * print_the_top - Prints the top node of the stack
 * @s: the pointer of the stack
 * @line: line number of  the operation code
 */
void print_the_top(stack_t **s, unsigned int line)
{
	if (s == NULL || *s == NULL)
		err_extend(6, line);
	printf("%d\n", (*s)->n);
}
