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
int i, j;
if (!av || !av[1])
return (1);
for (i = 0; environ[i]; i++)
{
if (_strncmp(environ[i], av[1], _strlen(av[1])) == 0 && environ[i][_strlen(av[1])] == '=')
{
/* Décaler les variables */
for (j = i; environ[j]; j++)
environ[j] = environ[j + 1];
return (0);
}
}
return (0);
}
