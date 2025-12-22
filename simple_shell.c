#include "shell.h"
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
int main(int ac, char **av, char **envp)
{
char *line = NULL;
size_t len = 0;
ssize_t r;
int status = 0;
(void)ac;
(void)av;
signal(SIGINT, sigint_handler);
while (1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
r = get_line(&line, &len, STDIN_FILENO);
if (r == -1)
break;
if (*line == '\0')
continue;
status = exe_cmd(line, envp);
}
free(line);
return (status);
}
