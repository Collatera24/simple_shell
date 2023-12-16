#include "simple_shell.h"

/**
 * wcount - counts the number of words present in a string
 * @str: string used to count words
 * @delim: It delimeters separating words
 *
 * Return: The number of words in string, else -1 on error
 */

int wcount(char *str, char *delim)
{
	int count;
	char *dup;

	dup = str;
	if (str == NULL)
	{
		perror("invalid string");
		return (-1);
	}

	strtok(dup, delim);
	for (count = 1; strtok(NULL, delim) != NULL; count++)
		;
	return (count);
}

/**
 * change_dir - It changes the present working directory
 * and updates old present working directory
 * @cmd: command to change working directory
 * Return: Always 0 (Success), else -1
 * AUTHORS: Kolawole Tella and Hammed Yakub
 */

int change_dir(char *cmd)
{
	char *path, *oldpwd, *pwd, *dup, buf[256];
	int words;
	size_t size = 256;

	dup = _strdup(cmd);
	words = wcount(dup, " \t\r");
	if (words > 2)
	{
		_perror(cmd, "too many arguments");
		free(dup);
		dup = NULL;
		return (-1);
	}
	strtok(cmd, " \t\r");
	path = strtok(NULL, " ");
	if (path == NULL)         /* home directory */
	{
		oldpwd = getcwd(buf, size);
		chdir(_getenv("HOME"));
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", getenv("PWD"), 1);
		free(dup);
		dup = NULL;
		return (0);
	}
	if (_strcmp(path, "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
		{
			perror("OLDPWD");         /* OLDPWD not new */
			free(dup);
			dup = NULL;
			return (-1);
		}
		else
		{
			oldpwd = getcwd(buf, size);
			chdir(_getenv("OLDPWD"));
			setenv("OLDPWD", oldpwd, 1);     /* Update OLDPWD */
			pwd = getcwd(buf, size);
			setenv("PWD", pwd, 1);
			free(dup);
			dup = NULL;
			return (0);
		}
	}
	oldpwd = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		print_error(_getenv("_"));
		print_error(": 1: cd: can't cd to ");
		write(STDERR_FILENO, path, _strlen(path));
		print_error("\n");
		free(dup);
		dup = NULL;
		return (-1);
	}
	setenv("OLDPWD", oldpwd, 1);     /* update OLDPWD */
	pwd = getcwd(buf, size);
	setenv("PWD", pwd, 1);
	free(dup);
	dup = NULL;
	return (0);
}

