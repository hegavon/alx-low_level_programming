#include "main.h"

/**
 * read_textfile - function that reads a text file and prints
 * @filename: File to be modified
 * @letters: The letters
 * Return: Always success
*/

ssize_t read_textfile(const char *filename, size_t letters);
{
	ssize_t opn, rd;

	char *ptr;

	if (filename == NULL)
		return (0);
	ptr = malloc(sizeof(char) * letters);
	if (ptr == NULL)
		return (0);

	opn = open(filename, O_RDONLY);
	rd = read(opn, ptr, letters);
	write(STDOUT_FILENO, ptr, rd);
	if (opn == -1 || rd == -1)
	{
		free(ptr);
		return (0);
	}
	free(ptr);
	close(opn);
	return (write);
}
