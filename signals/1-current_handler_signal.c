#include "signals.h"
/**
 * current_handler_signal -  a function that retrieves the current handler
 * Return: returns a position to the current handle
*/
void (*current_handler_signal(void))(int)
{
	void (*current_signal)(int) = NULL;

	current_signal = signal(SIGINT, NULL);
	signal(SIGINT, current_signal);
	return (current_signal);
}
