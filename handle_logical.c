#include "shell.h"
/**
* handle_logical - opérateurs logiques
* @line: pointeur line
* @envp: pointeur environnement
* Return: cmd2 exécutée si cmd1 réussit
*/
void handle_logical(char *line, char **envp)
{
char *cmd1;
char *cmd2;
if (_strstr(line, "&&"))
{
cmd1 = _strtok(line, "&&");
cmd2 = _strtok(NULL, "&&");
exe_cmd(del_space(cmd1), envp);
if (last_status == 0)
exe_cmd(del_space(cmd2), envp);
return;
}
if (_strstr(line, "||"))
{
cmd1 = _strtok(line, "||");
cmd2 = _strtok(NULL, "||");
exe_cmd(del_space(cmd1), envp);
if (last_status != 0)
exe_cmd(del_space(cmd2), envp);
}
}
