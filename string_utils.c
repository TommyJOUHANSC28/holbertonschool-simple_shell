#include "shell.h"
#include <stdlib.h>

/* ===================== STRING ===================== */
/**
 * _strlen - Compute the length of a string.
 * @s: Pointer to the null-terminated string.
 *
 * Return: The number of characters in the string (excluding the null byte).
 */
unsigned int _strlen(const char *s)
{
unsigned int len = 0;
if (!s)
return (0);
while (s[len])
len++;
return (len);
}
/**
 * _strcmp - Compare two strings lexicographically.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: 0 if equal, a positive or negative value depending on comparison.
 */
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
/**
 * _strncmp - Compare two strings up to n characters.
 * @s1: First string.
 * @s2: Second string.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if equal, otherwise difference between first mismatched characters.
 */
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
/**
 * _strdup - Duplicate a string into newly allocated memory.
 * @s: String to duplicate.
 *
 * Return: Pointer to the new string, or NULL on allocation failure.
 */
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
/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return: Pointer to the first occurrence of c, or NULL if not found.
 */
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
/**
 * _strcpy - Copy a string from src to dest.
 * @dest: Destination buffer.
 * @src: Source string.
 *
 * Return: Pointer to dest.
 */
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
/**
 * _strcat - Concatenate two strings.
 * @dest: Destination buffer containing the initial string.
 * @src: String to append.
 *
 * Return: Pointer to dest.
 */
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
/**
 * _isdigit - Check if a character is a digit.
 * @c: Character to check.
 *
 * Return: 1 if digit, 0 otherwise.
 */
int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}
/**
 * _atoi - Convert a string to an integer.
 * @s: String to convert.
 *
 * Return: The converted integer value.
 */
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
/**
 * _strtok - Tokenize a string using delimiters.
 * @str: String to tokenize (or NULL to continue tokenizing).
 * @delim: Delimiter characters.
 *
 * Return: Pointer to the next token, or NULL if no more tokens.
 */
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
/* ===================== STRSTR ===================== */
/**
 * _strstr - Locate a substring within a string.
 * @haystack: String to search in.
 * @needle: Substring to find.
 *
 * Return: Pointer to the beginning of the located substring, or NULL.
 */
char *_strstr(const char *h, const char *n)
{
size_t i, j;
if (!*n)
return ((char *)h);
for (i = 0; h[i]; i++)
{
for (j = 0; n[j] && h[i + j] == n[j]; j++)
;
if (!n[j])
return ((char *)(h + i));
}
return (NULL);
}
/* ===================== REALLOC ===================== */
/**
 * _realloc - Reallocate a memory block.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the reallocated memory, or NULL on failure.
 */
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
