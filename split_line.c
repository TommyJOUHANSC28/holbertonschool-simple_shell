#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line)
{
char *ptr, *token, *line_copy;
char **av = NULL;
size_t i = 0, count = 0;
if (!line)
return (NULL);
line_copy = strdup(line);
if (!line_copy)
return (NULL);
ptr = line_copy;
while ((token = strsep(&ptr, " \t")) != NULL)
{
if (*token == '\0')
continue;
count++;
}
free(line_copy);
av = malloc(sizeof(char *) * (count + 1));
if (!av)
return (NULL);
line_copy = strdup(line);
if (!line_copy)
{
free(av);
return (NULL);
}
ptr = line_copy;
while ((token = strsep(&ptr, " \t")) != NULL)
{
if (*token == '\0')
continue;
av[i] = strdup(token);
if (!av[i])
{
while (i > 0)
free(av[--i]);
free(av);
free(line_copy);
return NULL;
}
i++;
}
av[count] = NULL;
free(line_copy);
return (av);
}
