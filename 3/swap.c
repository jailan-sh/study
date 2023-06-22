#include "monty.h"
/**
 * swap_ord-swaps the top two elements of the stack.
 * @stack: head pointer to dlist
 * @line_number : line number
 * Return: void
 */
void swap_ord(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *temp = *stack;
	int val;

	while (temp)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_monty();
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = val;
	(*stack)->next->prev = NULL;
}
