#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		node_count++;

		if (head <= head->next)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}

		head = head->next;
	}

	return (node_count);
}
