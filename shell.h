#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define READ_SIZE 1024
extern char **environ;
extern int last_status;

/* ========= ALIAS ========= */
/**
 * struct alias_s - Represents a shell alias
 * @name: The alias name
 * @value: The alias value
 * @next: Pointer to the next alias in the list
 */
typedef struct alias_s
{
    char *name;
    char *value;
    struct alias_s *next;
} alias_t;

extern alias_t *alias_list;

/* ========= HISTORY ========= */
#define HIST_MAX 4096
extern char *history[HIST_MAX];
extern int hist_count;
extern char *line;

/* ========= PROTOTYPES ========= */


ssize_t get_line(char **line, size_t *len);
char *del_space(char *str);
char **split_line(char *line);
int exe_cmd(char *cmd, char **envp);
char *find_in_path(char *cmd);
void handle_exit(char **av);
int builtin_env(char **av);
char *_strchr(const char *s, char c);
char *_strdup(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
unsigned int _strlen(const char *s);
int _isdigit(char c);
int _atoi(const char *s);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int _unsetenv(char **av);
int _setenv(char **av);
char *_getcwd(void);
int builtin_cd(char **av);
int builtin_exit(char **av);
int _chdir(char *path);
char *_getenv(const char *name);
int is_path(char *cmd);
void sigint_handler(int sig);
void handle_semicolon(char *line, char **envp);
char *expand_status(char *line);
void handle_logical(char *line, char **envp);
char *expand_pid(char *line);
void set_alias(char *name, char *value);
void builtin_alias(char **av);
char *replace_alias(char *line);

void add_history(char *line);
void builtin_history(void);
void load_history(void);
void save_history(void);
void print_alias(alias_t *a);
/* string utils */
char *_strstr(const char *haystack, const char *needle);
char *replace_substr(char *line, char *old, char *new);

#endif
