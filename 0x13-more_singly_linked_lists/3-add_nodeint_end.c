#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *fresh_node = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (fresh_node == NULL)
		return (NULL);

	fresh_node->n = n;
	fresh_node->next = NULL;

	if (*head == NULL)
	{
		*head = fresh_node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = fresh_node;
	}

	return (fresh_node);
}
