#include "simple_shell.h"

/**
 * _strspn - Gets the length of a prefix substring that consists
 * only of characters from a specified set.
 * @str: The string to be examined.
 * @char_set: The set of characters to match against.
 *
 * Return: The length of the prefix substring consisting
 * of characters from @charset
 * AUTHOR- Kolawole Tella and Hammed Yakub
 */

size_t _strspn(const char *str, const char *charset)
{
	size_t k = 0;
	const char *ptr;

	while (*str)
	{
		ptr = charset;
		while (*ptr)
		{
			if (*str == *ptr)
			{
				k++;
				break;
			}
			ptr++;
		}
		if (!*ptr)
			break;
		str++;
	}

	return (k);
}

/**
 * _strchr - Locates a specified character in a given string
 * @str: The string in which the character is to be located.
 * @character: The character to be located.
 *
 * Return: A pointer or NULL if not found
 */

char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}

/**
 * _strncmp - Compares the first n bytes of two strings.
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 * @n: the first n bytes to be compared
 *
 * Return: return an interger if successful
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k = 0;

	while (k < n)
	{
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);
		if (s1[k] == '\0' || s2[k] == '\0')
			break;
		k++;
	}

	return (0);
}

/**
 * _strcpy - copy a string
 * @to: the destination string
 * @from: the source string
 *
 * Return: the destination string
 */

char *_strcpy(char *to, const char *from)
{
	int k = 0;

	while (from[k] != '\0')
	{
		to[k] = from[k];
		k++;
	}
	to[k] = '\0';

	return (to);
}

/**
 * _strcat - concatenate two strings
 * @to: the destination string
 * @from: the source string
 *
 * Return: the destination string
 */

char *_strcat(char *to, const char *from)
{
	int to_len = 0, k = 0;

	while (to[to_len] != '\0')
		to_len++;
	for (; from[k] != '\0'; k++)
	{
		to[to_len + k] = from[k];
	}
	to[to_len + k] = '\0';

	return (to);
}
