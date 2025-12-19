#include "shell.h"
/**
* find_in_path - Cherche une commande dans les dossiers du PATH,
* @cmd: commande à chercher*,
* Return: chemin complet si trouvé, NULL sinon
*/
char *find_in_path(char *cmd, char **envp)
{
char *ptr, *path = NULL, *copy, *token, *full;
int i = 0;
if (!cmd || !*cmd)
return (NULL);
if (strchr(cmd, '/'))
{
if (access(cmd, X_OK) == 0)
return (strdup(cmd));
return (NULL);
}
if (envp)
{
for (i = 0; envp[i]; i++)
{
if (strncmp(envp[i], "PATH=", 5) == 0)
{
path = envp[i] + 5;
break;
}
}
}
if (!path || !*path)
return (NULL);
copy = strdup(path);
if (!copy)
return (NULL);
ptr = copy;
while ((token = strsep(&ptr, ":")) != NULL)
{
if (*token == '\0')
continue;
full = malloc(strlen(token) + strlen(cmd) + 2);
if (!full)
break;
sprintf(full, "%s/%s", token, cmd);
if (access(full, X_OK) == 0)
{
free(copy);
return (full);
}
free(full);
}
free(copy);
return (NULL);
}
