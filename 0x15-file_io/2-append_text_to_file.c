#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file
 * @text_content: NULL-terminated string to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr, i;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (!text_content)
		return (1);

	for (i = 0; text_content[i] != '\0'; i++)
		;

	wr = write(fd, text_content, i);
	if (wr == -1)
		return (-1);

	if (close(fd) == -1)
		return (-1);

	return (1);
}
