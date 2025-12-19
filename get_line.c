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
static char buffer[BUF_SIZE];
static ssize_t buf_len = 0;
static ssize_t buf_pos = 0;
ssize_t nread = 0;
char *buf, c;

if (isatty(STDIN_FILENO))
            printf("#usr$ ");
    if (*line == NULL || *len == 0) {
        *len = 128;
        *line = malloc(*len);
        if (!*line)
            return -1;
    }
    buf = *line;

    while (1) {
        if (buf_pos >= buf_len) {
            buf_len = read(STDIN_FILENO, buffer, BUF_SIZE);
            buf_pos = 0;
            if (buf_len <= 0) {
                if (nread == 0)
                    return -1;
                break;
            }
        }

c = buffer[buf_pos++];

        if (nread + 1 >= (ssize_t)*len) {
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
