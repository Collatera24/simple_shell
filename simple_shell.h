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
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdbool.h>

/* Struct */

/**
 * struct Node_env - Structure representing an environment variable node.
 * @data: The environment variable list.
 * @number: Number used to check the environment variable list.
 * @next: Pointer to the next node in the structure.
 */

typedef struct Node_env
{
	char *data;
	int number;
	struct Node_env *next;
} Node_env;

/* Prototypes */

void free_env(char **env);
int str_count(char *av, char ***args);
void out_perror(const char *cmd, char *error_message);
int print_error(char *str);
char *path_handler(const char *cmd);
char *_getenv(const char *str);
void handle_signal(int sig);
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
void display_prompt(void);
char *handle_comment(char *cmd);
int wcount(char *str, char *delim);
int change_dir(char *cmd);
int _atoi(char *str);
char *_strtok(char *str, const char *delim);
void free_env(Node_env *head);
int handle_env(void);
void print_env(Node_env *head);
void add_to_list(Node_env **head, Node_env *new_node);
Node_env *create_node(char *data, int number);
void exit_builtin(char *cmd, char *status);
void free_new_av(char **new_av);
void execute_cmd(const char *cmd, char *const envp[]);
char **split_string(const char *cmd);
int countArgs(const char *cmd);


/* String prototype */

void *_memcpy(void *dest, const void *src, size_t n);
char *_strdup(char *str);
size_t _strcspn(const char *str, const char *char_set);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_strcat(char *to, const char *fro);
char *_strcpy(char *to, const char *fro);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(const char *str, int character);
size_t _strspn(const char *str, const char *char_set);

/* Macros */

static char *cmd __attribute__((unused));
extern char **environ;
#define MAX_PATH_LENGTH 1024
#define MAX_ARGS 64
extern int updated;


#endif /* SIMPLE_SHELL_H */
