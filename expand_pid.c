#include "shell.h"
/**
* expand_pid - remplace $$ par le PID du shell
* @line: chaîne d'entrée
*
* Return: nouvelle chaîne avec PID substitué, ou line si pas de $$
*/
char *expand_pid(char *line)
{
char buf[16];
char *pos;
pos = _strstr(line, "$$");
if (!pos)
return (line);
snprintf(buf, sizeof(buf), "%d", getpid());
return replace_substr(line, "$$", buf);
}