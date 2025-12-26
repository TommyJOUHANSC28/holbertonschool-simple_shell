#include <unistd.h>
#include "shell.h"

/**
 * _getenv - gets an environment variable
 *
 * @name: name of environmental variable
 * @env: current environment
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match
 *
 */
char *_getenv(const char *name, char **envp)
{
int i;
size_t len;
if (!name || !envp)
return (NULL);
len =_strlen(name);
for (i = 0; envp[i] != 0; i++)
{
if (_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
return (envp[i] + len + 1);
}
return (NULL);
}
