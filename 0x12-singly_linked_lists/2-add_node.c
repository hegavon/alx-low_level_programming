#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @str: The string to be duplicated and added to the new node.
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *fresh_node;

	/* Allocate memory for the new node */
	fresh_node = malloc(sizeof(list_t));
	if (fresh_node == NULL)
		return (NULL);

	/* Duplicate the string and assign values to the new node */
	fresh_node->str = strdup(str);
	if (fresh_node->str == NULL)
	{
		free(fresh_node);
		return (NULL);
	}

	fresh_node->len = strlen(str);

	/* Make the new node the head of the list */
	fresh_node->next = *head;
	*head = fresh_node;

	return (fresh_node);
}
