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
	int k = 0;

	if (!(str))
		return (0);

	while (str[k])
	{
		write(STDERR_FILENO, &str[k], 1);
		k++;
	}
	return (k);
}

/**
 * _perror - prints the error output to the stderr
 * @cmd: user command input
 * @error_message: the error message displayed
 */

void _perror(const char *cmd, char *error_message)
{

	char *program_name = _strdup((char *)cmd);
	char *first_cmd = strtok(program_name, " \t\r\n");

	print_error(_getenv("_"));
	print_error(": 1: ");
	print_error(first_cmd);
	print_error(": ");
	print_error(error_message);
	print_error("\n");
	free(program_name);
}
