#include "shell.h"
/**
* load_history - Loads command history from a file into memory.
* @history: Pointer to the history structure to populate.
* @filename: Path to the history file.
*
* Return: 0 on success, -1 on failure.
*
* This function reads the history file line by line, allocates memory
* for each entry, and appends it to the history list. If the file does
* not exist, the function returns 0 without modifying the history.
*/
void load_history(void)
{
char *home;
char path[1024];
FILE *fp;
char *line = NULL;
size_t len = 0;
home = _getenv("HOME");
if (!home)
return;
snprintf(path, sizeof(path), "%s/.simple_shell_history", home);
fp = fopen(path, "r");
if (!fp)
return;
while (getline(&line, &len, fp) != -1)
{
line[_strlen(line) - 1] = '\0';
add_history(line);
}
free(line);
fclose(fp);
}
