#include "monty.h"

/**
 * free_monty - free buffer and close file
 *
 * Return: void
 */

void free_monty(void)
{
	if (glob.line != NULL)
		free(glob.line);
	fclose(glob.fp);
	free_dlist(glob.head);
}


/**
 * free_dlist - free double linked list
 * @head : head pointer to d.linked list
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
