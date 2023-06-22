#include "monty.h"
/**
 * pint_ord- prints the value at the top of the stack, followed by a new line
 * @stack: head pointer to dlist
 * @line_number : line number
 * Return: void
 */
void pint_ord(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
