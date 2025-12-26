#include "shell.h"
/**
* _getcwd - Obtenir un répertoire fonctionnel un nom de chemin
* Return: void
*/
char *_getcwd(void)
{
char *cwd;
size_t size = 1024;
cwd = malloc(size);
if (!cwd)
return (NULL);
if (!getcwd(cwd, size))
{
free(cwd);
return (NULL);
}
return (cwd);
}
