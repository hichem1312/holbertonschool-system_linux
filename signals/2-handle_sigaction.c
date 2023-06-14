#include "signals.h"
/**
 * handle - handling errors
 * @signal: signal
 */
void handle(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}
/**
 * handle_sigaction - a function that set a handler for the signal SIGINT
 * Return: 0 or -1
*/
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = &handle;
	return (sigaction(SIGINT, &sa, NULL));
}
