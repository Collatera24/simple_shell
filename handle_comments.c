#include "shell.h"

/**
 * handle_comment - It prevents execution of words after comment
 * @cmd: The command received from standard input
 * AUTHORS: Kolawole Tella and Hammed Yakub
 * Return: The pointer to executable command
 */

char *handle_comment(char *cmd)
{
	char check[3];
	int m;

	check[2] = '\0';

	if (_strlen(cmd) == 1 && cmd[0] != '#')
		return (cmd);

	if (cmd[0] == '#')
		return (NULL);

	for (m = 0; cmd[m] != '\0'; m++)
	{
		if (cmd[m] == '#')
		{
			check[0] = cmd[m - 1];
			check[1] = cmd[m];
			if (_strcmp(check, " #") == 0)
			{
				return (strtok(cmd, "#"));
			}
		}
	}
	return (cmd);
}
