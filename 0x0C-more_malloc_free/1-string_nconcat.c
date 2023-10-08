#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * *string_nconcat - Function concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int s1len = 0;
	unsigned int s2len = 0;
	char *display;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
		s1len++;
	for (i = 0; s2[i] != '\0'; i++)
		s2len++;

	display = malloc(sizeof(char) * (s1len + n) + 1);
	if (display == NULL)
		return (NULL);
	if (n >= s2len)
	{
		for (i = 0; s1[i] != '\0'; i++)
			display[i] = s1[i];
		for (i = 0; s2[i] != '\0'; i++)
			display[s1len + i] = s2[i];
		display[s1len + i] = '\0';
	}
	else
	{
		for (i = 0; s1[i] != '\0'; i++)
			display[i] = s1[i];
		for (i = 0; i < n; i++)
			display[s1len + i] = s2[i];
		display[s1len + i] = '\0';
	}
	return (display);
}
