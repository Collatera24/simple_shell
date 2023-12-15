#include "simple_shell.h"

/**
 * print_error - writes a string to standard error library(stderr)
 * @str: the string to be written
 *
 * Return: number of written characters
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

int print_error(char *str)
{
	if (str == NULL)
		return (0);

	int k = 0;

	while (str[k] != '\0')

	{
		write(STDERR_FILENO, &str[k], 1);
		k++;
	}
	return (k);
}

/**
 * out_perror - prints the error output to the stderr
 * @cmd: user command input
 * @error_message: the error message displayed
 */

void out_perror(const char *cmd, char *error_message)
{
	if (cmd == NULL || error_message == NULL)
		return;

	char *program_title = _strdup((char *)cmd);
	char *first_cmd = strtok(program_title, " \t\r\n");

	print_error(_getenv("_"));
	print_error(": 1: ");
	print_error(first_cmd);
	print_error(": ");
	print_error(error_message);
	print_error("\n");
	free(program_title);
}
