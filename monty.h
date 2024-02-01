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
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
int len_chars(FILE *);


/*my*/
void add_queue(stack_t **nd, __attribute__((unused))unsigned int line);
void free_nodes(void);
stack_t *create_new_node(int number);
void add_node_to_stack(stack_t **n, __attribute__((unused))unsigned int line);
void pop_node(stack_t **s, unsigned int line);
void print_the_top(stack_t **s, unsigned int line);
void print_all_stack(stack_t **s, unsigned int line);

void div_top_nodes(stack_t **s, unsigned int line);
void sub_top_nodes(stack_t **s, unsigned int line);
void add_top_nodes(stack_t **s, unsigned int line);
void swap_top_nodes(stack_t **s, unsigned int line);
void nop(stack_t **, unsigned int);
void my_error(int code, ...);
void err_extend(int code, ...);
void expand__err(int code, ...);

void print_char_ascii(stack_t **s, unsigned int line);
void print_string(stack_t **s, __attribute__((unused))unsigned int line);
void rotl(stack_t **s, __attribute__((unused))unsigned int line);
void rotr(stack_t **s, __attribute__((unused))unsigned int line);
void of(char *file);
void rf(FILE *f);
int pl(char *buf, int line, int format);
void ff(char *opcode, char *v, int line, int format);
void cf(op_func fun, char *opcode, char *v, int line, int format);
void mul_top_nodes(stack_t **s, unsigned int line);
void mod_top_nodes(stack_t **s, unsigned int line);



#endif
