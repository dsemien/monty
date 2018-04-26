#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: pointer to pointer
 * @index: what to delete
 * Return: -1 upon failure, 1 upon success
 **/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr;
	unsigned int i = 0;
	dlistint_t *h;

	h = *head;
	if (*head == NULL || head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = h->next;
		free(h);
		return (1);
	}
	while (i < index - 1)
	{
		if (h == NULL)
			return (-1);
		h = h->next;
		i++;
	}
	ptr = (h->next)->next;
	free(h->next);
	h->next = ptr;
	return (1);
}
