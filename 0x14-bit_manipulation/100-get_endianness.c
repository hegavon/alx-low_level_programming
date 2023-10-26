#include "main.h"

/**
 * get_endianness - Checks the endianness of the machine.
 *
 * Return: 0 if the machine is big endian, 1 if it's little endian.
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *endian_check = (char *)&n;

	if (*endian_check)
		return (1);
	else
		return (0);
}
