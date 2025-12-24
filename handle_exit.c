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
size_t i;
int status = last_status;
if (av[1])
{
for (i = 0; av[1][i]; i++)
{
if (i == 0 && (av[1][i] == '+' || av[1][i] == '-'))
continue;
if (!_isdigit(av[1][i]))
{
fprintf(stderr, "%s: exit: %s: numeric argument required\n", SHELL_NAME, av[1]);
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
_exit(2); /* code d’erreur pour argument invalide */
}
}
status =_atoi(av[1]);
status %= 256;
if (status < 0)
status += 256;
}
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
_exit(status);
}
