#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to be deleted (starting at 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (1);
	}

	prev = *head;
	for (i = 0; prev && i < index - 1; i++)
		prev = prev->next;

	if (!prev || !prev->next)
		return (-1);

	temp = prev->next;
	prev->next = temp->next;
	free(temp);

	return (1);
}
