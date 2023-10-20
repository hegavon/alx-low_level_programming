#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *current;

	for (; head != NULL; head = current)
	{
		current = head->next;

		free(head->str);
		free(head);
	}
}
