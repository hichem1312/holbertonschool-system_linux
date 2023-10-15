#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * main - a program that opens an IPv4/TCP socket, and listens to traffic
 * Return: FAILURE or SUCCESS
 */
int main(void)
{
	int server_id = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in name;

	if (server_id < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	name.sin_family = AF_INET;
	name.sin_port = htons(PORT);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_id, (struct sockaddr *)&name, sizeof(name)) < 0)
	{
		perror("Bind failure");
		return (EXIT_FAILURE);
	}
	if (listen(server_id, 10) < 0)
	{
		perror("listen failure");
		return (EXIT_FAILURE);
	}

	printf("LISTENING...\n");
	while (1)
		continue;
	close(server_id);
	return (EXIT_SUCCESS);
}
