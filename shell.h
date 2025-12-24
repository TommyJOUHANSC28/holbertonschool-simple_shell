#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#define READ_SIZE 1024

ssize_t get_line(char **line, size_t *len);
char *del_space(char *str);
char **split_line(char *line);
int exe_cmd(char *line, char **envp, char *line_buf);
char *find_in_path(char *cmd, char **envp);
void handle_exit(char **av);
int builtin_env(char **envp);
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

#endif
