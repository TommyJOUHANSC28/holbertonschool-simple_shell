#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * handle_exit - Gère la commande builtin exit
 * @av: tableau des arguments (av[0] == "exit")
 *
 * Cette fonction quitte le shell avec le code fourni
 * ou 0 si aucun argument.
 */
void handle_exit(char **av)
{
int i, status = last_status;
if (av[1])
status = _atoi(av[1]);
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
if (line)
free(line);
_exit(status);
}