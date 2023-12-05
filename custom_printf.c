#include "simple_shell.h"
/**
 * custom_printf - This function emulates a simplified version
 * of the printf function.
 * @format: A pointer to the format string to be printed
 * Return: void
 */

void custom_printf(const char *format)
{
	 write(STDOUT_FILENO, format, strlen(format));
}
