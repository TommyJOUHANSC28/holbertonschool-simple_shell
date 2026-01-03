#include "shell.h"
/**
* _chdir - fonction qui permet de changer de répertoire actuel
* @path - chemin cible
* Return: 0 succès, -1 échec
*/
int _chdir(char *path)
{
char *oldpwd = NULL, *newpwd = NULL, *target = NULL;
char *av[4];
/* 1. Gérer cd sans argument → HOME */
if (!path)
target = _getenv("HOME");
else if (_strcmp(path, "-") == 0) /* 2. Gérer cd - → OLDPWD */
target = _getenv("OLDPWD");
else
target = path;
if (!target)
{
write(2, "cd: target not found\n", 21);
return (-1);
}
/* Sauvegarder l'ancien répertoire */
oldpwd = _getcwd();
if (!oldpwd)
return (-1);
/* Tentative de changement de répertoire */
if (chdir(target) == -1)
{
write(2, "cd: can't cd to ", 16);
write(2, target, _strlen(target));
write(2, "\n", 1);
free(oldpwd);
return (-1);
}
/* Récupérer le nouveau répertoire */
newpwd = _getcwd();
if (!newpwd)
{
free(oldpwd);
return (-1);
}
/* 3. Factorisation : fonction interne pour setenv */
av[0] = "setenv";
av[3] = NULL;
av[1] = "OLDPWD";
av[2] = oldpwd;
if (_setenv(av) == -1)
{
free(oldpwd);
free(newpwd);
return (-1);
}
av[1] = "PWD";
av[2] = newpwd;
if (_setenv(av) == -1)
{
free(oldpwd);
free(newpwd);
return (-1);
}
/* Affichage pour cd - */
if (path && _strcmp(path, "-") == 0)
{
write(1, newpwd, _strlen(newpwd));
write(1, "\n", 1);
}
free(oldpwd);
free(newpwd);
return (0);
}
