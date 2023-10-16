#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>


/**
 * main - a program that connects to a listening server
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 or 0
 */
int main(int argc, char **argv)
{
	struct sockaddr_in server;
	struct hostent *host;
    int server_id;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	host = gethostbyname(argv[1]);
	server_id = socket(PF_INET, SOCK_STREAM, 0);
	if (server_id < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	server.sin_family = AF_INET;
	inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server.sin_addr);
	server.sin_port = htons(atoi(argv[2]));
	if (connect(server_id, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("connect failure");
		return (EXIT_FAILURE);
	}

	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(server_id);
	return (EXIT_SUCCESS);
}