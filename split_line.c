#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line, const char *delim)
{
    char **tokens = NULL;
    size_t i = 0, start = 0, end = 0;
    int in_token = 0;

    /* Parcours caractère par caractère */
    while (line[end] != '\0')
    {
        /* Si on tombe sur un délimiteur */
        if (strchr(delim, line[end]) != NULL)
        {
            if (in_token)
            {
                /* Fin du token */
                line[end] = '\0';

                tokens = realloc(tokens, sizeof(char *) * (i + 2));
                if (!tokens)
                    return NULL;

                tokens[i] = strdup(&line[start]);
                i++;

                in_token = 0;
            }
        }
        else
        {
            if (!in_token)
            {
                /* Début d’un nouveau token */
                start = end;
                in_token = 1;
            }
        }

        end++;
    }

    /* Dernier token si la ligne ne finit pas par un délimiteur */
    if (in_token)
    {
        tokens = realloc(tokens, sizeof(char *) * (i + 2));
        if (!tokens)
            return NULL;

        tokens[i] = strdup(&line[start]);
        i++;
    }

    /* Terminaison du tableau */
    if (tokens)
        tokens[i] = NULL;

    return tokens;
}