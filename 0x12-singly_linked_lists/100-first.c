#include <stdio.h>

void special_print(void) __attribute__ ((constructor));

/**
 * special_print - Prints a sentence before the main function is executed.
 *
 * This function uses the constructor attribute to ensure it's executed
 * before the main function, and it prints specific lines
 */
void special_print(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
