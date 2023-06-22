#include "monty.h"

/**
 * add_ord - adds the top two elements of the stack
 * @stack : pointer to double linked list
 * @line_number : line number
 *
 * Return: void
 */

void add_ord(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = NULL;
	stack_t *tmp2 = NULL;
	stack_t *ptr = *stack;
	int sum = 0;
	int count = 0;

	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_monty();
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	sum = tmp1->n;
	sum += tmp2->n;
	(*stack) = tmp2;
	(*stack)->n = sum;
	tmp1->next = NULL;
	free(tmp1);
}






