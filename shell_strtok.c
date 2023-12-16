#include "simple_shell.h"

/**
 * _strtok - used for tokenization
 * @str: string to be tokenized
 * @delimeter: Delimeters to check
 * Return: Tokenized string
 */

char *_strtok(char *str, const char *delimeter)
{
	static char *buffer;
	char *token;
	int m = 0, n = 0, is_found;

	if (str)
	buffer = str;
	if (buffer == NULL || *buffer == '\0')
		return (NULL);
	token = buffer;
	while (buffer[m] != '\0')
	{
		is_found = 0;
		for (n = 0; delimeter[n] != '\0'; n++)
		{
			if (buffer[m] == delimeter[n])
			{
				is_found = 1;
				break;
			}
		}
		if (is_found)
		{
			buffer[m] = '\0';
			buffer = buffer + m + 1;
			return (token);
		}
		m++;
	}
	buffer = NULL;
	return (token);
}
