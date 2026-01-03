#include "shell.h"
/**
 * _setenv - builtin setenv (maison)
 * @av: arguments (av[0] = "setenv", av[1] = VAR, av[2] = VALUE)
 *
 * Return:
 *  0 en cas de succès
 *  1 en cas d'erreur
 */
int _setenv(char **av)
{
if (!av || !av[1] || !av[2])
return (1);
/* Utilise setenv() du système, plus sûr que putenv() */
if (setenv(av[1], av[2], 1) == -1)
return (1);
return (0);
}
