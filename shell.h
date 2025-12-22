#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#define BUF_SIZE 1024
#define SHELL_NAME "hsh"

/* Prototypes */
ssize_t get_line(char **line, size_t *len);
char *del_space(char *str);
char **split_line(char *line, const char *delim);
char *find_in_path(char *cmd, char **envp);
int builtin_env(char **envp);
int exe_cmd(char *line, char **envp);
void sigint_handler(int sig);
void handle_exit(char **av);

#endif