#include "shell.h"
/**
* expand_status - remplace $? par le code de retour précédent
* @line: chaîne d'entrée
 * Return: nouvelle chaîne avec $? substitué, ou line si pas de $?.
*/
char *expand_status(char *line)
{
char buf[16];
char *pos;
if(!line)
return (NULL);
pos = _strstr(line, "$?");
if (!pos)
return (line);
snprintf(buf, sizeof(buf), "%d", last_status);
return replace_substr(line, "$?", buf);
}
