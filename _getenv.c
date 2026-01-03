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
char *_getenv(const char *name)
{
int i;
size_t len;
if (!name)
return (NULL);
len =_strlen(name);
for (i = 0; environ[i] != 0; i++)
{
if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
return (environ[i] + len + 1);
}
return (NULL);
}
