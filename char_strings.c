#include "simple_shell.h"

/**
 * _strlen - determines the string length
 * @str: the string whoes length is to be determined
 *
 * Return: String length
 * AUTHOR - Kolawole Tella and Hammed Yakub
 */

int _strlen(const char *str)
{
	int k = 0;

	while (str[k] != '\0')
		k++;

	return (k);
}

/**
 * _strcmp - String comparer
 * @str1: The first string to be compared
 * @str2: The other string to be compared
 *
 * Return: Comparison
 */

int _strcmp(const char *str1, const char *str2)
{
	int k = 0;

	while (str1[k] != '\0' && str2[k] != '\0')
	{
		if (str1[k] != str2[k])
			return (str1[k] - str2[k]);
		k++;
	}

	return (str1[k] - str2[k]);
}

/**
 * _strcspn - Function to get length of a prefix substring
 * @str: The string
 * @char_set: The character set
 *
 * Return: Returns length
 */

size_t _strcspn(const char *str, const char *char_set)
{
	size_t len = 0;
	const char *ptr = str, *char_ptr = char_set;

	while (*ptr != '\0')
	{
		while (*char_ptr != '\0')
		{

			if (*ptr == *char_ptr)

				return (len);
			char_ptr++;
		}
		ptr++;
		len++;
	}

	return (len);
}

/**
 * _strdup - String duplicator
 * @str: String to be duplicated
 *
 * Return: New string
 */

char *_strdup(char *str)
{
	size_t length = _strlen(str) + 1;
	char *new_str = malloc(length);

	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, length);

	return (new_str);
}

/**
 * _memcpy -  Copies a number of bytes from src to dest
 * @dest: Pointer to dest memory area
 * @src: Pointer to src memory area
 * @n: number of bytes to be copied
 *
 * Return: Pointer to the dest memory area
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr = (unsigned char *)dest;
	const unsigned char *src_ptr = (const unsigned char *)src;
	size_t k = 0;

	while (k < n)
	{
		dest_ptr[k] = src_ptr[k];
		k++;
	}
	return (dest);
}
