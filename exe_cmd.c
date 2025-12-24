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
	size_t i;
	char *cmd_path;
	char **av;
	int status;

	av = split_line(line);
	if (!av || !av[0])
	{
			free(av);
		return (0);
	}
if(_strcmp(av[0], "exit") == 0)
{
	handle_exit(av);
}
	if (_strcmp(av[0], "env") == 0)
	{
		status = builtin_env(envp);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		return (status);
	}

cmd_path = find_in_path(av[0], envp);
if (!cmd_path)
{
fprintf(stderr, "%s: %d: %s: not found\n", SHELL_NAME, 1, av[0]);
last_status = 127;
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
return (127);
}
if (_strcmp(av[0], "setenv") == 0)
{
    last_status = _setenv(av);
    for (i = 0; av[i]; i++)
        free(av[i]);
    free(av);
    return (last_status);
}

if (_strcmp(av[0], "unsetenv") == 0)
{
    last_status = _unsetenv(av);
    for (i = 0; av[i]; i++)
        free(av[i]);
    free(av);
    return (last_status);
}
	child = fork();
	if (child < 0)
	{
		perror("fork");
		free(cmd_path);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		return (1);
	}
	if (child == 0)
	{
		execve(cmd_path, av, envp);
		perror("execve");
		free(cmd_path);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(line_buf);
		_exit(126);
	}
	free(cmd_path);
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		last_status = (WEXITSTATUS(status));
	else
	last_status = 1;
	return (last_status);
}
