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

	if (argc < 2)
		argv[0] = "./";
	for (i = 1; i < argc; i++)
	{

		dir = opendir(argv[i]);
		if (dir)
		{
			printf("%s:\n", argv[i]);
				while ((read = readdir(dir)) != NULL)
			{
				if (read->d_name[0] != '.')
					printf("%s  ", read->d_name);
			}
			printf("\n");
		}
		else
		{
			fprintf(stderr, "./hls: cannot access '%s': ", argv[i]);
			perror("");
		}
		
	}
	
	closedir(dir);
	return (0);
}
