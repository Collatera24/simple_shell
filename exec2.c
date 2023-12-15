#include "simple_shell.h"

/**
 * execute_command - executes a shell command in a child process
 * @command: The command to be executed
 *
 * Return: Always 0 (Success)
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		custom_printf("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if
		(child_pid == 0)
		{
			/* Child process */
			execlp(command, command, (char *)NULL);

			perror("Error executimg command");
			exit(EXIT_FAILURE);
		}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t len;

	while (1)
	{
		display_prompt();

		/* Read user input */
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* Handle EOF */
			printf("\nExisting shell. Goodbye!\n");
			break;
		}

		/* Remove the trailing new line */
		len = strlen(command);

		if (len > 0)
		{
			if (command[len - 1] == '\n')
			{
			command[len - 1] = '\0';
			}

			execute_command(command);
		}
	}

	return (0);
}
