#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int d, f;

	d = 0;
	while (src[d] != '\0' && d < n - 1)
	{
		dest[d] = src[d];
		d++;
	}
	if (d < n)
	{
		f = d;
		while (f < n)
		{
			dest[f] = '\0';
			f++;
		}
	}
	return (dest);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int d, f;

	d = 0;
	f = 0;
	while (dest[d] != '\0')
		d++;
	while (src[f] != '\0' && f < n)
	{
		dest[d] = src[f];
		d++;
		f++;
	}
	if (f < n)
		dest[d] = '\0';
	return (dest);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

