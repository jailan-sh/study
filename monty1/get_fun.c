#include "main.h"

/**
 * get_function - toget the function according to order given
 * @s : the command
 *
 */

void (*get_function(char *s))(stack_t **stack, unsigned int line_number)
{
	 instruction_t order[] = {
		 {"push",push_ord},
		 {"pall", pall_ord},
		 {"pop", pop_ord},
		 {"pint", pint_ord},
		 {"swap", swap_ord},
		 {"add", add_ord},
		 {"nop", nop_ord},
		 {NULL, NULL}};
	 int i = 0;
	 
	 while (order[i].opcode != NULL && *(order[i].opcode) != *s)
	 
		 i++;
		 if (order[i].opcode == NULL)
		 {
			 dprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
			 exit(EXIT_FAILURE);
		 }
		 return (order[i].f);
}
