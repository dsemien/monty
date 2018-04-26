#include "monty.h"
/**
 * add_dnodeint - adds node to begging of list
 * @head: node struct
 * @n: number to put in node
 * Return: dlistint_t
 **/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *box;

	if (head == NULL)
		return (NULL);
	box = malloc(sizeof(stack_t));
	if (box == NULL)
		return (NULL);
	box->n = n;
	box->next = *head;

	if (*head != NULL)
		(*head)->prev = box;

	*head = box;
	return (*head);
}

/**
 * add_dnodeint_end - adds node to the end of list.
 * @head: node struct
 * @n: number to put in node
 * Return: dlistint_t
 **/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (new);
}

/**
 * free_dlistint - free listint_t
 * @head: takes in listint_t *head
 **/
void free_dlistint(stack_t *head)
{
        stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
}
