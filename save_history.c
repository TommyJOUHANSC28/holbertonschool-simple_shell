#include "shell.h"
/**
 * save_history - Saves the command history to a file.
 *
 * Writes the in‑memory history list to the file specified by `filename`.
 * If the file cannot be opened or written, the function fails silently.
 *
 * Return: Path to the history file to write.
 */
void save_history(void)
{
char *home;
char path[1024];
int fd, i;
home = _getenv("HOME");
if (!home)
return;
snprintf(path, sizeof(path), "%s/.simple_shell_history", home);
fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return;
for (i = 0; i < hist_count; i++)
{
write(fd, history[i], _strlen(history[i]));
write(fd, "\n", 1);
free(history[i]);
}
close(fd);
}
