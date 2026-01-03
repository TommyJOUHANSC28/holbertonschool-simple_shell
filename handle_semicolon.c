#include "shell.h"
/**
* handle_semicolon - fonction pour les points virgules
* @line: pointeur ligne
* @envp: environnement
* Return: NULL
*/
void handle_semicolon(char *line, char **envp)
{
char *cmd;
cmd = _strtok(line, ";");
while (cmd)
{
cmd = del_space(cmd);
if (*cmd)
exe_cmd(cmd, envp);
cmd = _strtok(NULL, ";");
}
}
