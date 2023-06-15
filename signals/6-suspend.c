#include "signals.h"
/**
 * handler_sig - handling errors
 * @numsig: numsig
 */
void handler_sig(int numsig)
{
	printf("Caught %d\n", numsig);
}
/**
 * main - a program that sets a handler for the signal SIGINT
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = &handler_sig;
	sigaction(SIGINT, &sa, NULL);
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
