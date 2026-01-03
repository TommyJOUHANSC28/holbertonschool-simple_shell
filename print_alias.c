#include "shell.h"
/**
 * print_alias - affiche un alias
 * @a: alias
 * Return: affiche un alias
 */
void print_alias(alias_t *a)
{
if (!a)
return;
write(1, a->name, _strlen(a->name));
write(1, "='", 2);
write(1, a->value, _strlen(a->value));
write(1, "'\n", 2);
}