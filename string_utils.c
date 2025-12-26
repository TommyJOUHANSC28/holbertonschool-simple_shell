#include "shell.h"
#include <stdlib.h>

/* ===================== STRING ===================== */

unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;

	return (len);
}

int _strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (s1 - s2);

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
if (!s1 || !s2)
return (s1 - s2);
for (i =0; i < n; i++)
{
if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
return (0);
}

char *_strdup(const char *str)
{
	size_t i, len;
	char *dup;

	if (!str)
		return (NULL);

	len = _strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

char *_strchr(const char *s, char c)
{
	if (!s)
		return (NULL);

	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (!dest || !src)
		return (NULL);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	if (!dest || !src)
		return (NULL);

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';

	return (dest);
}

/* ===================== CHAR / INT ===================== */

int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int _atoi(const char *s)
{
	int sign = 1;
	int result = 0;

	if (!s)
		return (0);

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;

	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	while (*s && _isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

/* ===================== STRTOK ===================== */

char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *start;

	if (!delim)
		return (NULL);

	if (str)
		next = str;

	if (!next)
		return (NULL);

	while (*next && _strchr(delim, *next))
		next++;

	if (*next == '\0')
	{
		next = NULL;
		return (NULL);
	}

	start = next;

	while (*next && !_strchr(delim, *next))
		next++;

	if (*next)
	{
		*next = '\0';
		next++;
	}
	else
		next = NULL;

	return (start);
}

/* ===================== REALLOC ===================== */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    char *new;
    size_t i;

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    new = malloc(new_size);
    if (!new)
        return (NULL);

    for (i = 0; i < old_size && i < new_size; i++)
        new[i] = ((char *)ptr)[i];

    free(ptr);
    return (new);
}