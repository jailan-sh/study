#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head : head pointer
 * @n : data
 *
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_monty();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	return (new);
}
