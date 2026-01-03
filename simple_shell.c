#include "shell.h"

/**
 * main - Point d'entrée du simple shell
 * @ac: nombre d'arguments
 * @av: tableau des arguments
 * @envp: environnement
 *
 * Return: 0 en cas de succès
 */
int main(int ac, char **av, char **envp)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *cmd;
(void)ac;
(void)av;
signal(SIGINT, sigint_handler);
while (1)
{
write(1, "$ ", 2);
read = get_line(&line, &len);
if (read == -1)
{
write(1, "\n", 1);
free(line);
exit(last_status);
}
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
cmd = del_space(line);
if (!cmd || *cmd == '\0')
continue;
exe_cmd(cmd, envp);
}
free(line);
return 0;
}
