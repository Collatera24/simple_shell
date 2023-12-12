#include "simple_shell.h"

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
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child Process*/
		char *argv[2];

		argv[0] = (char *)command;
		argv[1] = NULL;

		execve(command, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process*/

		wait(NULL);
	}
}
