#include "shell.h"
/**
 * builtin_env - Affiche l'environnement courant
 * @envp: tableau des variables d'environnement
 *
 * Return: 0 en cas de succès
 */
int builtin_env(char **envp)
{
int i = 0;

while (envp && envp[i])
{
write(1, envp[i], _strlen(envp[i]));
write(1, "\n", 1);
i++;
}
return (0);
}
/**
 * builtin_cd - Changer le repertoire actuel courant
 * @args: argument de la commande cd
 *
 * Return: -1 en cas de succès
 */
int builtin_cd(char **args, char **envp)
{
char *path;
(void)envp;
/* cd sans argurment -> HOME */
if (!args[1])
{
path = getenv("HOME");
if (!path)
{
write(2, "cd: HOME not set\n", 17);
return (-1);
}
return (_chdir(path));
}
/** cd - */
if (_strncmp(args[1], "-", 2) == 0)
{
path = getenv("OLDPWD");
if (!path)
{
write(2, "cd: OLDPWD not set\n", 19);
return (-1);
}
write(1, path, _strlen(path));
write(1, "\n", 1);
return (_chdir(path));
}
return (_chdir(args[1]));
}
