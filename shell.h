#ifndef SHELL_H
#define SHELL_H
#define BUF_SIZE 1024

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

ssize_t get_line(char **line, size_t *len);
char *del_space(char *str);
char **split_line(char *line, const char *delim);
int exe_cmd(char *line, char **envp, char *line_buf);
char *find_in_path(char *cmd, char **envp);
void handle_exit(char **av);
int builtin_env(char **envp);
void sigint_handler(int sig);
#endif
