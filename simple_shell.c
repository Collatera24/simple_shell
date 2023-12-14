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

	while (1)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
