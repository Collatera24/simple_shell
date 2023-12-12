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
			custom_printf("Error input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0'; /* Remove new line */
}
