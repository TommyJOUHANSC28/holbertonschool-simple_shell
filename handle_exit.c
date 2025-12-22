#include "shell.h"

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
long status = 0;
char *arg = av[1];
if (arg)  
{
size_t j = 0;
/* Vérifie signe + ou - */
if (arg[j] == '+' || arg[j] == '-')
j++;
/* Vérifie que le reste est numérique */
for (; arg[j]; j++)
{
if (!isdigit((unsigned char)arg[j]))
{
fprintf(stderr, "%s: exit: %s: numeric argument required\n", SHELL_NAME, arg);
/* Libère av */
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
_exit(2);
}
}
/* Trop d'arguments */
if (av[2])
{
fprintf(stderr, "%s: exit: too many arguments\n", SHELL_NAME);
return;
}
status = atoi(arg);
}
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
_exit((unsigned char)status);  
}
