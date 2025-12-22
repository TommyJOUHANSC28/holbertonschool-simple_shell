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
   
    ssize_t buf_len;
    ssize_t nread = 0;
    char *buf = *line;
    char c;


    if (*line == NULL || *len == 0)
    {
        *len = 128;
        *line = malloc(*len);
        if (*line == NULL)
            return -1;
    }
  buf = *line;

    while (1)
    {
        buf_len = read(STDIN_FILENO, &c, 1);
        if (buf_len <= 0)
        {
            if (nread == 0)
                return -1;
            break;
        }

        if (nread + 1 >= (ssize_t)*len)
        {
            size_t new_len = *len * 2;
            char *new_buf = realloc(buf, new_len);
            if (!new_buf)
                return -1;
            buf = new_buf;
            *line = buf;
            *len = new_len;
        }

        buf[nread++] = c;

        if (c == '\n')
            break;
    }

    buf[nread] = '\0';
     return nread;
}