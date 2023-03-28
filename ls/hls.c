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
	int i, j, a = 0, A = 0, l = 0, n = argc, f = 0, total = 0, v = 0, p;
	/*int x = argc - 1;*/
	struct stat buf;

	if (argc < 2)
		argv[0] = "./";
	for (p = 1; p < argc; p++)
	{
		if (!(opendir(argv[p])))
		{
			v += 1;
		}
	}
	for (j = 1; j < argc; j++)
	{
		if ((argv[j][0] == '-') && (argv[j][1] == '1'))
			l += 1;
		else if ((argv[j][0] == '-') && (argv[j][1] == 'a'))
			a += 1;
		else if ((argv[j][0] == '-') && (argv[j][1] == 'A'))
			A += 1;
		if (!(opendir(argv[j])) && (v < 2) && (lstat(argv[j], &buf) == 0))
		{
			printf("%s\n", argv[j]);
			f += 1;
		}
		else if (!(opendir(argv[j])) && (v > 1) && (lstat(argv[j], &buf) == 0))
		{
			printf("%s ", argv[j]);
			f += 1;
		}
		else
		{
			total += 1;
		}
	}
	if ((f > 0 && total > 0) && (v < 2))
		printf("\n");
	else if ((f > 0 && total > 0) && (v > 1))
		printf("\n\n");
	n = n - (l + a + A + f);
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
		{
			dir = opendir(argv[i]);
			if (dir)
			{
				if (n > 2 || f > 0)
					printf("%s:\n", argv[i]);
				while ((read = readdir(dir)) != NULL)
				{
					if (((read->d_name[0] != '.' || (a > 0)) || ((A > 0) && (read->d_name[2] > 46 && strlen(read->d_name) > 1))) && (l > 0))
						printf("%s\n", read->d_name);
					else if (((read->d_name[0] != '.' || (a > 0)) || ((A > 0) && (read->d_name[2] > 46 && strlen(read->d_name) > 1))) && (l == 0))
						printf("%s  ", read->d_name);
				}
				if (l == 0)
					printf("\n");
				closedir(dir);
			}
			else if (lstat(argv[i], &buf) == 0)
			{
				if (errno == 13)
				{
					fprintf(stderr, "%s: cannot open directory %s: ", argv[0], argv[i]);
					perror("");
				}
				/*else
					printf("%s\n", argv[i]);*/
			}
			else
			{
				fprintf(stderr, "%s: cannot access %s: ", argv[0], argv[i]);
				perror("");
			}
			if (i < n - 1 && argc != 2/*|| (n == 2) || (l == 0 && a == 0 && A == 0)*/)
				printf("\n");
		}
	}
	return (0);
}
