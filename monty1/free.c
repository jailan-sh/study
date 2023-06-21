#include "main.h"

/**
 * free_monty - free buffer and close file
 *
 * Return: void
 */

void free_monty(void)
{
	free(glob.buff);
	fclose(glob.fp);
	free_dlist(glob.head);
}


/**
 * free_dlist - free double linked list
 *
 * Return: void
 */


void free_dlist(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

}
