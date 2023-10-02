#include "main.h"
/**
 * _puts - Prints a string, followed by a new line, to stdout
 * @str: String to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
