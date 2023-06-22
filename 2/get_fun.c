#include "monty.h"

/**
 * get_function - toget the function according to order given
 * @s : the command
 *
 * Return: 0 always success
 */

void (*get_function(char *s))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t order[] = {
		 {"push", push_ord},
		 {"pall", pall_ord},
		 {"pop", pop_ord},
		 {"pint", pint_ord},
		 {"swap", swap_ord},
		 {"add", add_ord},
		 {"nop", nop_ord},
		 {NULL, NULL}
	};
	for (i = 0; order[i].opcode != NULL && s != NULL; i++)
	{
		if (strcmp(order[i].opcode, s) == 0)
		{
			return (order[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", glob.line_number, s);
		exit(EXIT_FAILURE);
}
