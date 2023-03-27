#include "ls.h"
/**
 * main - ls program
 * @argc: the number of arguments on the command line
 * @argv: argv
 * Return: content of the current diractory
*/
int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *read;
	int i;
	int x = argc - 1;
	struct stat buf;

	if (argc < 2)
		argv[0] = "./";
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
			dir = opendir(argv[i]);
		if (dir && argv[i][0] != '-')
		{
			if (argc > 2 && (argv[2][0] != '-'))
				printf("%s:\n", argv[i]);
			while ((read = readdir(dir)) != NULL)
			{
				if ((read->d_name[0] != '.') && (argv[x][0] == '-' && argv[x][1] == '1'))
					printf("%s\n", read->d_name);
				else if (read->d_name[0] != '.')
					printf("%s  ", read->d_name);
			}
			if (argv[x][0] != '-' && i == x)
				printf("\n");
			if (argv[i][0] != '-')
				closedir(dir);
		}
		else if (lstat(argv[i], &buf) == 0)
		{
			if (errno == 13)
			{
				fprintf(stderr, "%s: cannot open directory %s: ", argv[0], argv[i]);
				perror("");
			}
			else
				printf("%s\n", argv[i]);
		}
		else if (argv[i][0] != '-')
		{
			fprintf(stderr, "%s: cannot access %s: ", argv[0], argv[i]);
			perror("");
		}
		if (i != x && (argv[i + 1][0] != '-'))
			printf("\n");
		
	}
	
	return (0);
}
