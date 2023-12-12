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

		char *args[] = {(char *)command, NULL}; /*cli argument*/
		char *envp[] = {NULL}; /* Environment var for new program*/

		if (execve(command, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process*/

		wait(NULL);
	}
}
