#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 * @delim: délimitation de la chaine
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line, const char *delim)
{
char **av = NULL;
char *token;
size_t i = 0;
token = our_strtok(line, delim);
while (token)
{
av = realloc(av, sizeof(char *) * (i + 2));
av[i++] = strdup(token);
token = our_strtok(NULL, delim);
}
if (av)
av[i] = NULL;
return (av);
}
