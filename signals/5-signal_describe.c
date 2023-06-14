#include "signals.h"
/**
 * main - a program that prints a description of a given signal
 * @argc: number of arguments
 * @argv: argument vector
 * Return: EXIT_FAILURE or 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
	return (1);
}
