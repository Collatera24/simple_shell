#include "simple_shell.h"

/**
 * str_count - Counts the already tokenised strings
 * @av: Character strings
 * @args: Token
 *
 * Return: Number of counts
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

int str_count(char *av, char ***args)
{
	int count = 0, a;
	char *token;
	char **tokens = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (tokens == NULL)
		return (-1);

	token = strtok(av, " \t\r\n");

	while (token != NULL && count < MAX_ARGS)
	{
		(tokens)[count] = _strdup(token);
		token = strtok(NULL, " \t\r\n");
		count++;
	}

	tokens[count] = NULL;
	*args = tokens;

	for (a = 0; a < count; a++)
		free(tokens[a]);
	free(tokens);
	return (count);
}

/**
 * free_env - Frees the environment
 * @env: The environment to be freed
 */

void free_environ(char **env)
{
	int a = 0;

	while (env[a] != NULL)
	{
		free(env[a]);
		a++;
	}
	free(env);
}


