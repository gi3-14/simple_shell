#include "main.h"
/**
 * get_error - Function that prints errors
 *
 * @count: Variable that counts the commands entered
 * @line_argument: Line of argument recalled
 */
void get_error(size_t count, char *line_argument)
{
	int length;

	for (length = 0; line_argument[length] != '\0'; length++)
	{}

	if (length < 256)
	{
		write(STDERR_FILENO, "/bin/hsh: ", 11);
		print_number(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_argument, length);
		write(STDERR_FILENO, ": not found\n", 13);
		/* exit(127); */
	}
	else
	{
		write(STDERR_FILENO, "/bin/hsh: ", 11);
		print_number(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_argument, length);
		write(STDERR_FILENO, ": File name too long\n", 22);
		/* exit(0); */
	}
}
