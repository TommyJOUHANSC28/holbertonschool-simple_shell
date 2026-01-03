#include "shell.h"
/**
 * _unsetenv - builtin unsetenv (maison)
 * @av: arguments (av[0] = "unsetenv", av[1] = VARIABLE)
 *
 * Return:
 *  0 en cas de succès
 *  1 en cas d'erreur
 */
int _unsetenv(char **av)
{
if (!av || !av[1])
return (1);
if (unsetenv(av[1]) == -1)
return (1);
return (0);
}
