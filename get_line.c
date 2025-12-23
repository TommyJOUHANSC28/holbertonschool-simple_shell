#include "shell.h"
/**
 * get_line - Affiche le prompt puis lit une ligne depuis l'entrée standard.
 * @line: pointeur vers le buffer qui contiendra la ligne lue
 * @len: taille du buffer
 * @fd: sortie d'entrée standard
 * Return: le nombre de caractères lus ou -1 en cas d'erreur ou EOF
 */
ssize_t get_line(char **line, size_t *len, FILE *fd)
{
ssize_t i = 0;
int c;
char *buf, *tmp;
if (!line || !len || !fd)
return (-1);
if (*line == NULL || *len == 0)
{
*len = 128;
*line = malloc(*len);
if (*line == NULL)
return (-1);
}
buf = *line;
while ((c = fgetc(fd)) != EOF)
{
if (i + 1 >= (ssize_t) *len)
{
tmp = realloc(buf, *len);
if (!buf)
return (-1);
buf = tmp;
*line = buf;
}
buf[i++] = c;
if (c == '\n')
break;
}
if (i == 0 && c == EOF)
return (-1);
buf[i] = '\0';
return (i);
}
