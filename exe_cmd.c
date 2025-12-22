#include "shell.h"
/**
 * exe_cmd - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 * @envp: tableau des variables d'environnement
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 * Return: 1
 */
int exe_cmd(char *line, char **envp)
{
pid_t pid;
char **av;
char *path;
int status, i;
av = split_line(line, " \t");
if (!av || !av[0])
return (0);
if (strcmp(av[0], "env") == 0)
return (builtin_env(envp));
path = find_in_path(av[0], envp);
if (!path)
{
fprintf(stderr, "%s: %s: not found\n", SHELL_NAME, av[0]);
goto free_all;
}
pid = fork();
if (pid == 0)
execve(path, av, envp);
waitpid(pid, &status, 0);
free(path);
free_all:
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
return (status);
}
