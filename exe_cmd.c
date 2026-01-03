#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * exe_cmd - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 * @envp: tableau des variables d'environnement
 * @line_buf: buffer alloué par getline à libérer dans le processus enfant
 *
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 * Return: 1
 */
int exe_cmd(char *cmd, char **envp)
{
pid_t child;
int status, i;
char **av;
char *path;
/* 1. Gestion des opérateurs logiques et du ; */
if (_strstr(cmd, "&&") || _strstr(cmd, "||"))
{
handle_logical(cmd, envp);
return (last_status);
}
if (_strchr(cmd, ';'))
{
handle_semicolon(cmd, envp);
return (last_status);
}
/* 2. Parsing */
av = split_line(cmd);
if (!av)
return (last_status);
if (!av[0])
{
free(av);
return (last_status);
}
/* 3. Builtins */
if (_strcmp(av[0], "exit") == 0)
handle_exit(av); /* handle_exit doit free(av) */
if (_strcmp(av[0], "cd") == 0)
{
builtin_cd(av);
goto clean;
}
if (_strcmp(av[0], "env") == 0)
{
builtin_env(envp);
goto clean;
}
if (_strcmp(av[0], "alias") == 0)
{
builtin_alias(av);
goto clean;
}
if (_strcmp(av[0], "history") == 0)
{
builtin_history();
goto clean;
}
/* 4. Recherche dans le PATH */
path = find_in_path(av[0]);
if (!path)
{
fprintf(stderr, "%s: %s: not found\n", SHELL_NAME, av[0]);
last_status = 127;
goto clean;
}
/* 5. Fork + execve */
child = fork();
if (child == 0)
{
execve(path, av, envp);
perror("execve");
_exit(126);
}
waitpid(child, &status, 0);
if (WIFEXITED(status))
last_status = WEXITSTATUS(status);
free(path);
clean:
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
return last_status;
}
