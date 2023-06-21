#include "main.h"

/**
 */

void (*get_function(char *s))(stack_t **stack, unsigned int line_number)
{
	 instruction_t order[] = {{"push", }, {"pall", }, {"pop", },
		 {"pint", }, {"swap", }, {"add", }, {"nop", }, {NULL, NULL}};
	 int i = 0;
	 
	 while (order[i].opcode != NULL && *(order[i].opcode) != *s)
	 
		 i++;
		 if (order[i].opcode == NULL)
		 {
			 return (NULL);
		 }
		 return (order[i].f);
}
