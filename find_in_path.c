#include "shell.h"
/**
* find_in_path - Cherche une commande dans les dossiers du PATH,
* @cmd: commande à chercher*,
* Return: chemin complet si trouvé, NULL sinon
*/
char *find_in_path(char *cmd)
{
char *path, *copy, *token, *full;
int len_cmd, len_dir;
if (!cmd || !*cmd)
return NULL;
/* Si la commande contient un '/', ne pas chercher dans PATH */
if (_strchr(cmd, '/'))
{
if (access(cmd, X_OK) == 0)
return _strdup(cmd);
return NULL;
}
/* Récupérer PATH depuis environ */
path = _getenv("PATH");
if (!path)
return NULL;
copy = _strdup(path);
if (!copy)
return NULL;
token = _strtok(copy, ":");
len_cmd = _strlen(cmd);
while (token)
{
len_dir = _strlen(token);
full = malloc(len_dir + len_cmd + 2);
if (!full)
break;
_strcpy(full, token);
_strcat(full, "/");
_strcat(full, cmd);
if (access(full, X_OK) == 0)
{
free(copy);
return full;
}
free(full);
token = _strtok(NULL, ":");
}
free(copy);
return NULL;
}
