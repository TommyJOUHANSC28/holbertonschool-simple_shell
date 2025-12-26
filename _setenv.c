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
int i;
char *new_var;
size_t len;
/* Vérification du nombre d’arguments */
if (!av || !av[1] || !av[2])
return (1);
len = _strlen(av[1]) + _strlen(av[2]) + 2;
new_var = malloc(len);
if (!new_var)
return (1);
_strcpy(new_var, av[1]);
_strcat(new_var, "=");
_strcat(new_var, av[2]);
for (i = 0; environ[i]; i++)
{
if (_strncmp(environ[i], av[1], _strlen(av[1])) == 0 &&
 environ[i][_strlen(av[1])] == '=')
{
environ[i] = new_var;
return (0);
}
}
return (0);
}
