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
 * Return: 0
 */
int main(void)
{
	int server_id = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server, client;
	socklen_t adr_size = sizeof(struct sockaddr);

	if (server_id < 0)
	{
		perror("Socket:");
		return (EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server_id, (struct sockaddr *)&server, adr_size) < 0)
	{
		perror("Bind:");
		return (EXIT_FAILURE);
	}

	if (listen(server_id, 1) < 0)
	{
		perror("Listen:");
		return (EXIT_FAILURE);
	}

	printf("Server listening on port %d\n", PORT);

	if (accept(server_id, (struct sockaddr *)&client, &adr_size) < 0)
	{
		perror("Accepting error:");
		return (EXIT_FAILURE);
	}

	printf("Client connected: %s\n", inet_ntoa(client.sin_addr));

	close(server_id);
	return (0);
}