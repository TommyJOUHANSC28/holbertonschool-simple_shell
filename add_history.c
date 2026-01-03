#include "shell.h"
/**
* add_history - ajoute une ligne à l'historique
* @line: commande entrée par l'utilisateur
*/
void add_history(char *line)
{
char *copy;
if (!line || !*line)
return;
/* Dupliquer la ligne avant toute modification */
copy = _strdup(line);
if (!copy)
return; /* erreur malloc → on ignore */
/* Si l'historique est plein, supprimer la plus ancienne entrée */
if (hist_count == HIST_MAX)
{
free(history[0]);
memmove(history, history + 1, sizeof(char *) * (HIST_MAX - 1));
hist_count--;
}
history[hist_count++] = copy;
}
