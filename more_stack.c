#include "monty.h"

/**
 * print_char_ascii - Prints the Ascii value
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void print_char_ascii(stack_t **s, unsigned int line)
{
	int result;

	if (s == NULL || *s == NULL)
		expand__err(11, line);

	result = (*s)->n;
	if (result < 0 || result > 127)
		expand__err(10, line);
	printf("%c\n", result);
}

/**
 * print_string - Prints string
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void print_string(stack_t **s, __attribute__((unused))unsigned int line)
{
	int result;
	stack_t *tmp_node;

	if (s == NULL || *s == NULL)
	{
		printf("\n");
		return;
	}

	tmp_node = *s;
	while (tmp_node != NULL)
	{
		result = tmp_node->n;
		if (result <= 0 || result > 127)
			break;
		printf("%c", result);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to top
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void rotl(stack_t **s, __attribute__((unused))unsigned int line)
{
	stack_t *tmp_node;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp_node = *s;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *s;
	(*s)->prev = tmp_node;
	*s = (*s)->next;
	(*s)->prev->next = NULL;
	(*s)->prev = NULL;
}


/**
 * rotr - rotates the stack to the bottom
 * @s: pointer of the top of the stack
 * @line: the line number
 */
void rotr(stack_t **s, __attribute__((unused))unsigned int line)
{
	stack_t *tmp_node;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return;

	tmp_node = *s;

	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *s;
	tmp_node->prev->next = NULL;
	tmp_node->prev = NULL;
	(*s)->prev = tmp_node;
	(*s) = tmp_node;
}
