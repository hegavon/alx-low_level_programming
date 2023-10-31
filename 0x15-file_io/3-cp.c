#include "main.h"

/**
 * open_from - opens a file for reading
 * @file: name of the file to open
 *
 * Return: file descriptor of the opened file
 */
int open_from(const char *file)
{
	int fd_from = open(file, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}

	return (fd_from);
}

/**
 * open_to - opens a file for writing
 * @file: name of the file to open
 *
 * Return: file descriptor of the opened file
 */
int open_to(const char *file)
{
	int fd_to = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (fd_to);
}

/**
 * copy_content - copies the content of one file to another
 * @fd_from: file descriptor of the source file
 * @fd_to: file descriptor of the destination file
 */
void copy_content(int fd_from, int fd_to)
{
	ssize_t rd, wr;
	char buffer[1024];

	do {
		rd = read(fd_from, buffer, 1024);
		if (rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %d\n", fd_from);
			exit(98);
		}

		wr = write(fd_to, buffer, rd);
		if (wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %d\n", fd_to);
			exit(99);
		}
	} while (rd == 1024);
}

/**
 * close_files - closes file descriptors
 * @fd_from: file descriptor of the source file
 * @fd_to: file descriptor of the destination file
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		int fd = fd_from > fd_to ? fd_from : fd_to;

		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from;
	int fd_to;

	umask(0000);

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_from(av[1]);
	fd_to = open_to(av[2]);

	copy_content(fd_from, fd_to);

	close_files(fd_from, fd_to);

	return (0);
}
