#include "shell.h"
/**
 * replace_alias - Replaces an alias with its corresponding value.
 *
 * Detailed explanation of what the function does, how it behaves,
 * edge cases, return values, etc.
 *
 * @alias: The alias to replace.
 * Return The replaced string, or NULL on failure.
 */
char *replace_alias(char *line)
{
alias_t *tmp = alias_list;
char *cmd, *new;
cmd = _strtok(line, " ");
if (!cmd)
return (line);
while (tmp)
{
if (_strcmp(cmd, tmp->name) == 0)
{
new = _strdup(tmp->value);
free(line);
return (new);
}
tmp = tmp->next;
}
return (line);
}
