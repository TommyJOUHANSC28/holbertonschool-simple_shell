#include "shell.h"
/**
 * get_line - Affiche le prompt puis lit une ligne depuis l'entrée standard.
 * @line: pointeur vers le buffer qui contiendra la ligne lue
 * @len: taille du buffer
 * @fd: sortie d'entrée standard
 * Return: le nombre de caractères lus ou -1 en cas d'erreur ou EOF
 */
ssize_t get_line(char **line, size_t *len, int fd)
{
ssize_t i = 0;
char c;
if (*line == NULL)
{
*len = 1024;
*line = malloc(*len);
if (*line == NULL)
return (-1);
}
while (read(fd, &c, 1) > 0)
{
if (c == '\n')
break;
(*line)[i++] = c;
}
if (i == 0)
return (-1);
(*line)[i] = '\0';
return (i);
}
