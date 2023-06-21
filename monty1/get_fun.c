#include "main.h"

/**
 * get_function - toget the function according to order given
 * @s : the command
 *
 * Return: 0 always success
 */

int get_function(char *s)
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
			 dprintf(stderr, "L%d: unknown instruction %s\n", glob.line_number, s);
			 exit(EXIT_FAILURE);
		 }
		 order[i].f(&(glob.head), glob.line_number);
		 return (0);
}
