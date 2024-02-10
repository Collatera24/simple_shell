#include "simple_shell.h"

/**
 * handle_path - Handles the PATH environ var to find the command.
 * @cmd: The command to check if it's in the PATH environ.
 *
 * Return: The full PATH if found; otherwise, NULL.
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

char *handle_path(const char *cmd)
{
	/* Function to handle path */
	const char *var = "PATH";
	const char *delim = ":";
	char *path = _getenv(var), *path_copy = NULL, *path_token;
	char *file_path = NULL;
	size_t cmd_len = _strlen(cmd), dir_len;
	struct stat check_path;

	/* Error handling for missing path var */
	if (path == NULL)
	{
		_perror(cmd, "not found");
		exit(EXIT_FAILURE);
	}

	/* Allocate memory and copy the path */
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	/*Tokenise path copy */
	path_token = strtok(path_copy, delim);

	/* Iterate through path tokens */

	while (path_token)
	{
		dir_len = _strlen(path_token);
		if (dir_len + cmd_len + 2 <= MAX_PATH_LENGTH)
		{
			file_path = (char *)malloc(dir_len + cmd_len + 2);
			if (file_path == NULL)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);

			/* Check if the file exists and executable*/
			if (stat(file_path, &check_path) == 0)
			{
				free(path_copy);
				return (file_path);
			}

			free(file_path);
			file_path = NULL;
		}

		/*Move to the next path token*/
		path_token = strtok(NULL, delim);
	}

	free(path_copy);
	if (access(cmd, X_OK) == 0)
		return ((char *)cmd);

	return (NULL);
}

/**
 * _getenv - Gets the specified environ var.
 * @str: The environ var to retrieve.
 *
 * Return: The environ var if found; otherwise, NULL.
 */

char *_getenv(const char *str)
{
	char **env = environ;
	char *find_equalto;
	int len;

	while (*env != NULL)
	{
		find_equalto = _strchr(*env, '=');

		if (find_equalto != NULL)
		{
			len = find_equalto - *env;

			if (_strncmp(str, *env, len) == 0)
			{
				return (find_equalto + 1);
			}
		}

		env++;
	}

	return (NULL);
}
