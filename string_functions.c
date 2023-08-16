#include "our_shell.h"
char *_strdup(const char *s);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, const char *src);

/**
 * _strlen - prints the length of a string
 * @s: string to find the length
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0, len = 0;
	/*to avoid trailing white space warning*/
	for (i = 0; s[i]; i++)
		len++;
	return (len);
}

/**
 * _strcat - sticks the src string to the dest string
 * @src: the source string
 * @dest: the destination string
 * Return: the concanated string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, len = 0;
	/*to avoid trailing white space warining*/
	while (dest[i++])
		len++;
	for (i = 0; src[i]; i++)
		dest[len++] = src[i];
	return (dest);
}

/**
 * _strncat - concatinates at most n characters of src to dest
 * @src: the source file
 * @dest: the destination file
 * @n: the number of charabers to concatinate
 * Return: the destination string that is concatinated with n characters
 */

char *_strncat(char *dest, char *src, int n)
{
	int index = 0, len = 0;
	/*to avoid trailing white space warning*/
	while (dest[index++])
		len++;
	for (index = 0; index < n && src[index] != '\0'; index++)
		dest[len++] = src[index];
	return (dest);
}

/**
 * _strcpy - copies string src to string dest
 * @src: the source of the string to be copied
 * @dest: the destination of the copy
 * Return: the destination string
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;
	/*to avoid trailing white space warning*/
	while ((dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}

/**
 * _strdup - duplicates a string s
 * @s: the string to duplicate
 * Return: a pointer to the duplicate string
 */

char *_strdup(const char *s)
{
	int len = 0;
	char *ptr;
	/*to avoid trailing white space warning*/
	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--s;
	return (ptr);
}
