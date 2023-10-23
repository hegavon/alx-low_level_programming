#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: A pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
	listint_t *fresh_node = NULL;

	for (fresh_node = head; fresh_node != NULL;)
	{
		listint_t *temp = fresh_node->next;

		free(fresh_node);
		fresh_node = temp;
	}
}
