#include "shell.h"
#include <sys/wait.h>
#include <fcntl.h>
/**
 * main - Point d'entrée du programme.
 * @ac: nombre d'arguments passés au programme
 * @av: tableau des arguments passés au programme
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction affiche un prompt, lit les commandes de l'utilisateur,
 * puis les exécute en boucle jusqu'à la fin de l'entrée standard.
 * Si un fichier de script est passé en argument,il est exécuté à la place.
 *
 * Return: 0 en cas de succès
 */
int last_status = 0;
int main(int ac, char **av, char **envp)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *cmd, *pwd;
int exit_status = 0;
(void)ac;
(void)av;
while (1)
{
if (isatty(STDIN_FILENO))
{
	pwd = _getenv("PWD", envp);
if(pwd)
{
write(1, pwd, _strlen(pwd));
write(1, "$ ", 2);
}
else
write(1, "#usr$ ", 6);
read = get_line(&line, &len);
}
if (read == -1)
break;
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
cmd = del_space(line);
if (*cmd == '\0')
continue;
if (_strncmp(cmd, "exit", 4) == 0)
{
av = split_line(cmd);
free(line);
handle_exit(av);
}
exit_status = exe_cmd(cmd, envp, line);
}
free(line);
return (exit_status);
}
