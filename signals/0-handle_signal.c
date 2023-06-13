#include "signals.h"
/**
 * handler - a handler
 * @signal: signal
 */
void handler(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_signal - a function that set a handler for the signal SIGINT
 * Return: 0 or -1
 */
int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	return (0);
}