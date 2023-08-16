#include "our_shell.h"

/**
 * _strchr - locates a character in a string.
 * @s: the string to be searched
 * @ch: the character to be searched
 * Return: a pointer to the first occurance of the charactr when found
 */

char *_strchr(char *s, char ch)
{
	int i = 0;
	/*to avoid trailing white space errore*/
	for (i = 0; s[i]; i++)
	{
		if (s[i] == ch)
			return (s + i);
	}
	return (NULL);
}
/**
 * _strncmp - copies n characters of string2 to string 1
 * @s1: the string to be copied
 * @s2: the string to copy from
 * @n: the number of characters to copy
 * Return: 0 if success
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;
	/*to avoid trailing white space error*/
	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * my_putchar - writes character
 * @c: character
 *
 * Return: character
 */

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints the string given
 * @s: string to print
 * Return: the printed string on stdout
 */
void _puts(const char *s)
{
	int i = 0;
	/*to avoid trailing white space error*/
	while (s[i] != '\0')
	{
		putchar(s[i]);
		i++;
	}
	putchar('\n');
}

/**
 * my_strcmp - compares two strings
 * @s1: frist string
 * @s2: second string
 *
 * Return: 1 if its true
 */

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
