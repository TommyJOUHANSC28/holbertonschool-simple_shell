#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line, const char *delim)
{
int i = 0, j = 0, k = 0, count = 1;
char **tokens;
/* Compter les tokens */
for (i = 0; line[i]; i++)
if (line[i] == delim[0])
count++;
tokens = malloc(sizeof(char *) * (count + 1));
if (!tokens)
return NULL;
i = 0;
while (line[i])
{
/* Sauter les délimiteurs */
while (line[i] == delim[0])
i++;
j = i;
while (line[j] && line[j] != delim[0])
j++;
tokens[k] = malloc(j - i + 1);
if (!tokens[k])
return NULL;
memcpy(tokens[k], line + i, j - i);
tokens[k][j - i] = '\0';
k++;
i = j;
}
tokens[k] = NULL;
return tokens;
}