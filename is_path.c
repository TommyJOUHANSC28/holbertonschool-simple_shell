#include "shell.h"
/**
* is_path - fonction pour terminer path
* @cmd: pointeur cmd 
* Return: valeur du path 
*/
int is_path(char *cmd)
{
int i = 0;
while (cmd[i])
{
if (cmd[i] == '/')
return (1);
i++;
}
return (0);
}
