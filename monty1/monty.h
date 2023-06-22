#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

/**liberaries*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>

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

/** the only global variable*/

/**
 * struct global - contains global variables
 * @gbuff: getline buffer;
 * @n: argument of command (intger data of stack)
 * @head: head of stack
 * @line_number: number of line
 * @fp: pointer to file descriptor
 *
 * Description: Struct for keeping global vars
 */
typedef struct global
{
	char *buff;
	stack_t *head;
	char *n;
	unsigned int line_number;
	FILE *fp;
} glob_v;

extern glob_v glob;

/**set global variables*/

void set_glob(void);

/**to get the order*/
int get_function(char *s);

/**stack functions*/

void push_ord(stack_t **stack, unsigned int line_number);
void pall_ord(stack_t **stack, unsigned int line_number);
void pop_ord(stack_t **stack, unsigned int line_number);
void pint_ord(stack_t **stack, unsigned int line_number);
void swap_ord(stack_t **stack, unsigned int line_number);
void add_ord(stack_t **stack, unsigned int line_number);
void nop_ord(stack_t **stack, unsigned int line_number);

/**add or delete node functions from double linked lists*/

stack_t *add_dnodeint(stack_t **head, const int n);
int number(char *s);

/**free functions*/

void free_monty(void);
void free_dlist(stack_t *head);


#endif
