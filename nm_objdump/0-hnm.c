#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - a program that reproduces the GNU nm command
 * @argc: argument count
 * @argv: Argument Vector
 * @env: environment
 * Return: 0 or 1
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *command[] = {"./hnm", "-p", "", NULL};

	command[2] = argv[1];
	if (execve("/usr/bin/nm", command, env) == -1)
	{
		perror("execv");
		return (0);
	}
	return (1);
}
