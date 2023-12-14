#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_command - Function that executes given commands
 * @command: String characters to be executed
 *
 * Return: 0
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else if
		(child_pid == 0)
		{
			execlp(command, command, (char *)NULL);

			perror("Error executing command");
			exit(EXIT_FAILURE);

		}
	else
	{
		wait(NULL);
	}
}

