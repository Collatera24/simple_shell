#include "simple_shell.h"

/**
 * read_command - Reads and interprets the input commands
 * @command: Strings inputted
 * @size: Size of the inputted strings
 *
 * Return: 0
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			custom_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			custom_printf("Error reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0'; /* Remove new line */
}

/**
 * execute_command - Reads, interprets and tokenise commands
 * @command: Strings to be tokenised
 *
 * Return: 0
 * Author - Kolawole Tella and Hammed Yakub
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		custom_printf("Error message.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/**
		 * Child process
		 * Parse the command and its arguments
		 */
		char *args[105]; /* Maximum 105 arguments */
		int arg_count = 0;

		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		/* Execute the command */
		execve(args[0], args, NULL);

		/* If execve fails, return an error message */
		custom_printf("Error message.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent proccess */
		wait(NULL);
	}
}
