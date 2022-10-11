/*
 * File: 4-new_dog.c
 * Auth: Jan Nelson
 */

#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char *_strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _strlen - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _strcopy - Copies a string pointed to by src, including the
 *            terminating null byte, to a buffer pointed to by dest.
 * @dest: The buffer storing the string copy.
 * @src: The source string.
 *
 * Return: The pointer to dest.
 */
char *_strcopy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: The new struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doggs;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	doggs = malloc(sizeof(dog_t));
	if (doggs == NULL)
		return (NULL);

	doggs->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (doggs->name == NULL)
	{
		free(doggs);
		return (NULL);
	}

	doggs->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (doggs->owner == NULL)
	{
		free(doggs->name);
		free(doggs);
		return (NULL);
	}

	doggs->name = _strcopy(doggs->name, name);
	doggs->age = age;
	doggs->owner = _strcopy(doggs->owner, owner);

	return (doggs);
}
