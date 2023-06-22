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
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                free_monty();
                exit(EXIT_FAILURE);
        }
	sum = (*stack)->n;
	sum += (*stack)->next->n;
	pop_ord(stack, line_number);
	(*stack)->n = sum;
}
