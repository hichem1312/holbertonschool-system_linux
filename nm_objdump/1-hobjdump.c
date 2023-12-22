#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - a program that reproduces the GNU objdump command
 * @argc: argument count
 * @argv: Argument Vector
 * @env: the environment
 * Return: 0 or 1
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *command[] = {"./hobjdump", "-s", "-f", "", NULL};

	command[3] = argv[1];
	if (execve("/usr/bin/hobjdump", command, env) == -1)
	{
		perror("execv");
		return (0);
	}
	return (1);
}
