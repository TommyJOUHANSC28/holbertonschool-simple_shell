#include "shell.h"
/**
 * replace_substr - Replaces all occurrences of a substring within a string.
 *
 * This function searches for every instance of `old_sub` inside `str`
 * and replaces it with `new_sub`. It returns a newly allocated string
 * containing the result. The caller is responsible for freeing it.
 * @str:      The original string.
 * @old_sub:  The substring to replace.
 * @new_sub:  The substring to insert.
 * @return A newly allocated string with replacements applied,
 *         or NULL on allocation failure.
 */
char *replace_substr(char *line, char *old, char *new)
{
char *pos, *res;
size_t len;
pos = _strstr(line, old);
if (!pos)
return (line);
len = _strlen(line) - _strlen(old) + _strlen(new);
res = malloc(len + 1);
strncpy(res, line, pos - line);
res[pos - line] = '\0';
_strcat(res, new);
_strcat(res, pos + strlen(old));
free(line);
return (res);
}
