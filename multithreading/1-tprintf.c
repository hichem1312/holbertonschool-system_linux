#include "multithreading.h"

/**
 * tprintf-printf function
 * @format: string
 * Return: 1 or 0
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (0);
}
