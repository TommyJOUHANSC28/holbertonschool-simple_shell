#include "shell.h"
/**
 * set_alias - Adds or updates an alias in the shell's alias list.
 * @name: The alias name to set.
 * @value: The value to assign to the alias.
 *
 * This function handles creating a new alias or updating an existing one.
 * It ensures correct memory allocation and replaces previous values safely.
 */
void set_alias(char *name, char *value)
{
alias_t *tmp = alias_list;
while (tmp)
{
if (_strcmp(tmp->name, name) == 0)
{
free(tmp->value);
tmp->value = _strdup(value);
return;
}
tmp = tmp->next;
}
tmp = malloc(sizeof(alias_t));
tmp->name = _strdup(name);
tmp->value = _strdup(value);
tmp->next = alias_list;
alias_list = tmp;
}
