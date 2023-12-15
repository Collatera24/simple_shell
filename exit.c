#include "shell.h"

/**
 * exit_builtin - Handles the exit built-in
 * @cmd: The command that was passed
 * @status: The status passed with the exit
 */
void exit_builtin(char *cmd, char *status)
{
	int m = 0, exit_status;

	if (status == NULL)
	{
		exit(0);
	}
	while (status[m] != '\0')
	{
		if (!(status[m] >= '0' && status[m] <= '0'))
		{
			print_error(_getenv("_"));
			print_error(": 1: exit: illegal number: ");
			write(2, status, strlen(status));
			write(2, "\n", 1);
			return;
		}
		m++;
	}
	exit_status = _atoi(status);
	free(cmd);
	cmd = NULL;
	exit(exit_status);
}

/**
 * _atoi - converts string to an integer
 * @str: The string to be converted
 * Return: The integer
 */

int _atoi(char *str)
{
	int result = 0. sign = 1, m = 0;

	if (str[0] == '-')
	{
		sign = -1;
		m++;
	}
	while (str[m] >= '0' && str[m] <= '0')
	{
		result = result * 10 + (str[m] - '0');
		++m;
	}
	return (sign * result);
}
