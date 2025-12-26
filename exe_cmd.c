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
int exe_cmd(char *line, char **envp, char *line_buf)
{
pid_t child;
int i;
char *cmd_path;
char **av;
int status;
(void)line_buf;
av = split_line(line);
if (!av || !av[0])
{
free(av);
return (0);
}
if (strcmp(av[0], "cd") == 0)
{
last_status = builtin_cd(av, envp);
goto cleanup;
}
if(_strcmp(av[0], "exit") == 0)
{
handle_exit(av);
}
if (_strcmp(av[0], "env") == 0)
{
last_status = builtin_env(envp);
goto cleanup;
} 
if (_strcmp(av[0], "setenv") == 0)
{
last_status = _setenv(av);
goto cleanup;
}
if (_strcmp(av[0], "unsetenv") == 0)
{
last_status = _unsetenv(av);
goto cleanup;
}

cmd_path = find_in_path(av[0], envp);
if (!cmd_path)
{
fprintf(stderr, "%s: %d: %s: not found\n", SHELL_NAME, 1, av[0]);
last_status = 127;
goto cleanup;
}
child = fork();
if (child == -1)
{
perror("fork");
free(cmd_path);
last_status = 1;
goto cleanup;
}
if (child == 0)
{
execve(cmd_path, av, envp);
perror("execve");
free(cmd_path);
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
_exit(126);
}
waitpid(child, &status, 0);
if (WIFEXITED(status))
last_status = (WEXITSTATUS(status));
else
last_status = 1;
free(cmd_path);

cleanup:
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
return (last_status);
}
