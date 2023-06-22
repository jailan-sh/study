#include "monty.h"
/**
 * pop_ord-removes the top element of the stack.
 * @stack: head pointer to dlist
 * @line_number : line number
 * Return: void
 */

void pop_ord(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_monty();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next)
	{
	*stack = (*stack)-> next;
	(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}
