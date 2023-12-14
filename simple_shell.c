#include "simple_shell.h"
/**
 * main - Entry point
 * command: A character array to store the user input command,
 * assumes a maximum command length of 104 characters.
 * Return: Always 0 (Success)
 */

int main(void)
{
	char command[105];
	size_t len;

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExiting shell. Goodbye!\n");
			break;
		}

		len = strlen(command);
		if (len > 0 && command[len - 1] == '\n')
		{
			command[len - 1] = '\0';
		}

		execute_command(command);
	}

	return (0);
}
