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
    if (argc < 2)
        argv[0] = "./";
    dir = opendir(argv[0]);
    while ((read = readdir(dir)) != NULL)
        {
            if (read->d_name[0] == ".")
                printf("%s\n", read->d_name);
        }
    closedir(dir);
    return(0);
}