#include "monty.h"

/**
 * mod_ord - computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack : pointer to double linked list
 * @line_number : line number
 *
 * Return: void
 */

void mod_ord(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;
	int num1, num2;
	int mod;

        while (ptr)
        {
                count++;
                ptr = ptr->next;
        }
        if (count < 2)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                free_monty();
                exit(EXIT_FAILURE);
        }
	num1 = (*stack)->n;
	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
                free_monty();
                exit(EXIT_FAILURE);
	}
	num2 = (*stack)->next->n;
	mod = num2 % num1;
	pop_ord(stack, line_number);
	(*stack)->n = mod;
}

