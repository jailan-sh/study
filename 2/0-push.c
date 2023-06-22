#include "monty.h"

/**
 * push_ord -  pushes an element to the stack.
 * @stack: head pointer to dlist
 * @line_number : line number
 *
 * Return: void
 */

void push_ord(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!number(glob.n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_monty();
		free_dlist(stack)
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.n);
	add_dnodeint(stack, n);
}

/**
 * pall_ord -  prints all the values on the stack, starting from the top
 * @stack : head pointer to dlist
 * @line_number : line number
 *
 * Return: void
 */

void pall_ord(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (*stack == NULL)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * number - checkes if the second arg for push integer or not
 * @s : argument
 *
 * Return: 1 is integer 0 is not
 */

int number(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		return (0);
	}
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!isdigit(s[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
