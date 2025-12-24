#include "shell.h"
/**
 * split_line - Sépare une ligne en mots (arguments) pour execve.
 * @line: chaîne à découper
 *
 * Return: un tableau de chaînes (terminé par NULL) ou NULL en cas d'erreur
 */
char **split_line(char *line)
{
    char *token, *copy;
    char **av;
    size_t i = 0, count = 0;

    if (!line)
        return (NULL);

    /* 1️⃣ Compter les mots */
    copy = _strdup(line);
    if (!copy)
        return (NULL);

    token = _strtok(copy, " \t");
    while (token)
    {
        count++;
        token = _strtok(NULL, " \t");
    }
    free(copy);

    /* 2️⃣ Allouer le tableau */
    av = malloc(sizeof(char *) * (count + 1));
    if (!av)
        return (NULL);

    /* 3️⃣ Remplir le tableau */
    copy = _strdup(line);
    if (!copy)
    {
        free(av);
        return (NULL);
    }

    token = _strtok(copy, " \t");
    for (i = 0; i < count; i++)
    {
        av[i] = _strdup(token);
        if (!av[i])
        {
            while (i > 0)
                free(av[--i]);
            free(av);
            free(copy);
            return (NULL);
        }
        token = _strtok(NULL, " \t");
    }

    av[count] = NULL;
    free(copy);
    return (av);
}
