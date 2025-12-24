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
char **new_env;
/* Vérification du nombre d’arguments */
if (!av[1] || !av[2])
{
fprintf(stderr, "setenv: usage: setenv VARIABLE VALUE\n");
last_status = 1;
return (1);
}
/* Vérifier si la variable existe déjà */
for (i = 0; environ[i]; i++)
{
if (_strncmp(environ[i], av[1], _strlen(av[1])) == 0 &&
environ[i][_strlen(av[1])] == '=')
{
/* Remplacer la valeur */
free(environ[i]);
environ[i] = malloc(_strlen(av[1]) + _strlen(av[2]) + 2);
if (!environ[i])
{
last_status = 1;
return (1);
}
_strcpy(environ[i], av[1]);
_strcat(environ[i], "=");
_strcat(environ[i], av[2]);
last_status = 0;
return (0);
}
}
/* Variable inexistante → agrandir environ */
new_env = malloc(sizeof(char *) * (i + 2));
if (!new_env)
{
last_status = 1;
return (1);
}
/* Copier l’ancien environnement */
for (i = 0; environ[i]; i++)
new_env[i] = environ[i];
/* Créer la nouvelle variable */
new_var = malloc(_strlen(av[1]) + _strlen(av[2]) + 2);
if (!new_var)
{
free(new_env);
last_status = 1;
return (1);
}
_strcpy(new_var, av[1]);
_strcat(new_var, "=");
_strcat(new_var, av[2]);
new_env[i] = new_var;
new_env[i + 1] = NULL;
free(environ);
environ = new_env;
last_status = 0;
return (0);
}
