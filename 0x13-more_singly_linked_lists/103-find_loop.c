#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: A linked list to search for a loop.
 *
 * Return: The address of the node where the loop starts, or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hot = head;
	listint_t *cold = head;

	if (!head)
		return (NULL);

	for (; hot && cold && hot->next;)
	{
		hot = hot->next->next;
		cold = cold->next;
		if (hot == cold)
		{
			cold = head;
			for (; cold != hot;)
			{
				cold = cold->next;
				hot = hot->next;
			}
			return (hot);
		}
	}

	return (NULL);
}
