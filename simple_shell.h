#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

void display_prompt(void);
void custom_printf(const char *format);
void read_command(char *command, size_t size);
void execute_command(const char *command);

#endif /* SIMPLE_SHELL_H */
