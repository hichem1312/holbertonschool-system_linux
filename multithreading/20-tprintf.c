#include "multithreading.h"

static pthread_mutex_t lock;
void init_mutex(void) __attribute__((constructor));
void destroy_mutex(void) __attribute__((destructor));

/**
 * tprintf - a function that uses the printf family to print out a given formatted string.
 *@format: the format
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	va_list arg;

	va_start(arg, format);

	if (pthread_mutex_lock(&lock))
	{
		printf("lock failed\n");
		exit(EXIT_FAILURE);
	}

	printf("[%lu] ", pthread_self());
	vprintf(format, arg);
	pthread_mutex_unlock(&lock);
	va_end(arg);
	return (EXIT_SUCCESS);
}