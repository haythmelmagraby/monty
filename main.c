#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	of(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_new_node - add new node
 * @number: The Number
 * Return: the node
 */
stack_t *create_new_node(int number)
{
	stack_t *n;

	n = malloc(sizeof(stack_t));
	if (n == NULL)
		my_error(4);
	n->next = NULL;
	n->prev = NULL;
	n->n = number;
	return (n);
}

/**
 * free_nodes - Frees nodes in memory
 */
void free_nodes(void)
{
	stack_t *tmp_node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp_node = head;
		head = head->next;
		free(tmp_node);
	}
}


/**
 * add_queue - Adds to queue
 * @nd: node pointer
 * @line: line number
 */
void add_queue(stack_t **nd, __attribute__((unused))unsigned int line)
{
	stack_t *tmp_node;

	if (nd == NULL || *nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nd;
		return;
	}
	tmp_node = head;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *nd;
	(*nd)->prev = tmp_node;

}
