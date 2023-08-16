#ifndef OUR_SHELL_H
#define OUR_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_ARGS 10

int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);
char *_strchr(char *s, char ch);
void _puts(const char *s);
int _strncmp(char *s1, char *s2, int n);
int my_putchar(char c);
char **tokenize_input(char *input_string);
void show_prompt(void);
int my_strcmp(const char *s1, const char *s2);
void _signal(int n);
void free_mem(char **buff);
void print_env(char **env);
void my_exit(char **cmd, char *argv);
int builtin_handle(char **cmd, char *argv);
void free_mem(char **buff);
int my_path(char **cmd, char *input);
extern char **environ;
void exec_cmd(char *cmd, char **av);
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
char *_getenv(void);
char *locate_cmd(char *cmd, char *input_string);
char *check_path(char **cmd, char *av);
/**
 * struct check -checks for flag
 * @interactive: flag
 */
struct check
{
	bool interactive;
} check;

/**
 * struct builtin - builtin variables
 * @env: builtin environment variable
 * @exit: built in exit
 */
struct builtin
{
	char *env;
	char *exit;
} b;
#endif
