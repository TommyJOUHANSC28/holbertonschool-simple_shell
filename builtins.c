#include "shell.h"
/**
 * builtin_env - Affiche l'environnement courant
 * @av: tableau de chaine
 * Return: 0 en cas de succès
 */
int builtin_env(char **av)
{
int i;
(void)av;
for (i = 0; environ[i]; i++)
{
write(1, environ[i], _strlen(environ[i]));
write(1, "\n", 1);
}
return (0);
}
/**
 * builtin_cd - Changer le repertoire actuel courant
 * @av: argument de la commande cd
 *
 * Return: -1 en cas de succès
 */
int builtin_cd(char **av)
{
char *oldpwd, *newpwd, *target;
char *args[4];
oldpwd = _getcwd();
if (!oldpwd)
return (1);
if (!av[1])
target = _getenv("HOME");
/* cd - → OLDPWD */
else if (_strcmp(av[1], "-") == 0)
{
target = _getenv("OLDPWD");
if (target)
write(1, target, _strlen(target));
write(1, "\n", 1);
}
else
target = av[1];
if (!target || chdir(target) == -1)
{
perror("cd");
free(oldpwd);
return (1);
}
newpwd = _getcwd();
if (!newpwd)
{
free(oldpwd);
return (1);
}
/* OLDPWD */
args[0] = "setenv";
args[3] = NULL;
args[1] = "OLDPWD";
args[2] = oldpwd;
_setenv(args);
/* PWD */
args[1] = "PWD";
args[2] = newpwd;
_setenv(args);
free(oldpwd);
free(newpwd);
return (0);
}
/**
* Implémente la fonction intégrée d'alias.
* @av: Vecteur d'arguments contenant les définitions ou requêtes d'alias.
* Renvoie 0 en cas de succès.
*/
void builtin_alias(char **av)
{
alias_t *tmp;
int i;
if (!av[1])
{
for (tmp = alias_list; tmp; tmp = tmp->next)
print_alias(tmp);
return;
}
for (i = 1; av[i]; i++)
{
char *eq = _strchr(av[i], '=');
if (eq)
{
*eq = '\0';
set_alias(av[i], eq + 1);
}
else
{
tmp = alias_list;
while (tmp)
{
if (_strcmp(tmp->name, av[i]) == 0)
print_alias(tmp);
tmp = tmp->next;
}
}
}
}
/**
* builtin_history - Affiche ou modifie l'historique du shell.
* @av: Vecteur d'arguments pour les options d'historique.
* Renvoie 0 en cas de succès.
*/
void builtin_history(void)
{
int i;
char buf[32];
for (i = 0; i < hist_count; i++)
{
snprintf(buf, sizeof(buf), "%d ", i);
write(1, buf, _strlen(buf));
write(1, history[i], _strlen(history[i]));
write(1, "\n", 1);
}
}