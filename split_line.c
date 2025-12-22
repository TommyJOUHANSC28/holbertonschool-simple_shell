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
    char **new_tokens;
    size_t i = 0;
    char *token;

    token = strtok(line, delim);

    while (token)
    {
        new_tokens = realloc(tokens, sizeof(char *) * (i + 2));
        if (!new_tokens)
            return NULL;

        tokens = new_tokens;
        tokens[i] = strdup(token);
        i++;

        token = strtok(NULL, delim);
    }

    if (tokens)
        tokens[i] = NULL;

    return tokens;
}
