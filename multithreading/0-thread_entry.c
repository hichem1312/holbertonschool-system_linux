#include "multithreading.h"
/**
 * thread_entry - entry point
 * @arg: arguments
 * Return: 1 or 0
 */
void *thread_entry(void *arg)
{
	char *str;

	str = (char *)arg;
	printf("%s\n", str);
	pthread_exit(NULL);
}
