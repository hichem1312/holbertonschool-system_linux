#include "signals.h"
/**
 * current_handler_sigaction - a function that retrieves the current handler
 * Return: signal
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	if (sigaction(SIGINT, NULL, &sa) == -1)
		return (NULL);
	return (sa.sa_handler);
}