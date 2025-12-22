#include "shell.h"
/**
* our_strtok - split a string into multiple pieces called tokens
* @str: string
* @delim: string delimitation
* Return: value of tocken
*/
char *our_strtok(char *str, const char *delim)
{
static char *save;
char *token;
if (str)
save = str;
if (!save || *save == '\0')
return (NULL);
while (*save && strchr(delim, *save))
save++;
if (*save == '\0')
return (NULL);
token = save;
while (*save && !strchr(delim, *save))
save++;
if (*save)
*save++ = '\0';
return (token);
}
