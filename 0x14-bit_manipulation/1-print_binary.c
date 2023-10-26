#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int bit, started = 0;
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask > 0)
	{
		bit = (n & mask) ? 1 : 0;

		if (bit)
			started = 1;

		if (started)
			_putchar(bit + '0');

		mask >>= 1;
	}
}
