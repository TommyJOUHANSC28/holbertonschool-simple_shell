#include "shell.h"
/**
 * get_line - Affiche le prompt puis lit une ligne depuis l'entrée standard.
 * @line: pointeur vers le buffer qui contiendra la ligne lue
 * @len: taille du buffer
 *
 * Return: le nombre de caractères lus ou -1 en cas d'erreur ou EOF
 */
ssize_t get_line(char **line, size_t *len)
{
static char buffer[READ_SIZE];
static ssize_t buf_pos;
static ssize_t buf_size;
ssize_t i;
char *tmp;

if (!line || !len)
return (-1);
if (*line == NULL)
{
*len = 128;
*line = malloc(*len);
if (!*line)
return (-1);
}
i = 0;
while (1)
{
/* Recharger le tampon si vide */
if (buf_pos >= buf_size)
{
buf_size = read(STDIN_FILENO, buffer, READ_SIZE);
buf_pos = 0;
if (buf_size <= 0)
return (i > 0 ? i : -1);
}
/* Agrandir la ligne si nécessaire */
if ((size_t)i + 1 >= *len)
{
*len *= 2;
tmp = realloc(*line, *len);
if (!tmp)
return (-1);
*line = tmp;
}
(*line)[i] = buffer[buf_pos++];
if ((*line)[i++] == '\n')
break;
}
(*line)[i] = '\0';
return (i);
}
