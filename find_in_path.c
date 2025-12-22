#include "shell.h"
/**
* find_in_path - Cherche une commande dans les dossiers du PATH,
* @cmd: commande à chercher*,
* Return: chemin complet si trouvé, NULL sinon
*/
char *find_in_path(char *cmd, char **envp)
{
char *path, *copy, *dir, *full;
int i;
if (strchr(cmd, '/'))
return (access(cmd, X_OK) == 0 ? strdup(cmd) : NULL);
for (i = 0; envp[i]; i++)
if (strncmp(envp[i], "PATH=", 5) == 0)
path = envp[i] + 5;
if (!path)
return NULL;
copy = strdup(path);
dir = strtok(copy, ":");
while (dir)
{
full = malloc(strlen(dir) + strlen(cmd) + 2);
sprintf(full, "%s/%s", dir, cmd);
if (access(full, X_OK) == 0)
{
free(copy);
return full;
}
free(full);
dir = strtok(NULL, ":");
}
free(copy);
return NULL;
}
