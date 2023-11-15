#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int vr1, vr2, vr3, vr4, numberwords = 0;
	char **p1;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (vr1 = 0; str[vr1] != '\0'; vr1++)
		if (!is_delim(str[vr1], d) && (is_delim(str[vr1 + 1], d) || !str[vr1 + 1]))
			numberwords++;

	if (numberwords == 0)
		return (NULL);
	p1 = malloc((1 + numberwords) * sizeof(char *));
	if (!p1)
		return (NULL);
	for (vr1 = 0, vr2 = 0; vr2 < numberwords; vr2++)
	{
		while (is_delim(str[vr1], d))
			vr1++;
		vr3 = 0;
		while (!is_delim(str[vr1 + vr3], d) && str[vr1 + vr3])
			vr3++;
		p1[vr2] = malloc((vr3 + 1) * sizeof(char));
		if (!p1[vr2])
		{
			for (vr3 = 0; vr3 < vr2; vr3++)
				free(p1[vr3]);
			free(p1);
			return (NULL);
		}
		for (vr4 = 0; vr4 < vr3; vr4++)
			p1[vr2][vr4] = str[vr1++];
		p1[vr2][vr4] = 0;
	}
	p1[vr2] = NULL;
	return (p1);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int vr1, vr2, vr3, vr4, numberwords = 0;
	char **p1;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (vr1 = 0; str[vr1] != '\0'; vr1++)
		if ((str[vr1] != d && str[vr1 + 1] == d) ||
				    (str[vr1] != d && !str[vr1 + 1]) || str[vr1 + 1] == d)
			numberwords++;
	if (numberwords == 0)
		return (NULL);
	p1 = malloc((1 + numberwords) * sizeof(char *));
	if (!p1)
		return (NULL);
	for (vr1 = 0, vr2 = 0; vr2 < numberwords; vr2++)
	{
		while (str[vr1] == d && str[vr1] != d)
			vr1++;
		vr3 = 0;
		while (str[vr1 + vr3] != d && str[vr1 + vr3] && str[vr1 + vr3] != d)
			vr3++;
		p1[vr2] = malloc((vr3 + 1) * sizeof(char));
		if (!p1[vr2])
		{
			for (vr3 = 0; vr3 < vr2; vr3++)
				free(p1[vr3]);
			free(p1);
			return (NULL);
		}
		for (vr4 = 0; vr4 < vr3; vr4++)
			p1[vr2][vr4] = str[vr1++];
		p1[vr2][vr4] = 0;
	}
	p1[vr2] = NULL;
	return (p1);
}


