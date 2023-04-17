#include "_getline.h"

/**
 * _getline - a function that reads an entire line from file descriptor.
 * @fd:	file descriptor
 * Return: a line from the file descriptor
 **/
char *_getline(const int fd)
{
    char buff[READ_SIZE];
    size_t check;
    char *new_line = NULL;
    int i = 0;

    while ((check = read(fd, buff + i, 1)) > 0)
    {
        if (buff[i] == '\n')
        {
            break;
        }
        i++;
    }
    
    if (i >= 0)
    {
        new_line = malloc((i + 1) * sizeof(char));
        if (!new_line) 
        {
            return(NULL);
        }
        strncpy(new_line, buff, i);
        new_line[i] = '\0';
    }
    if (check == 0 && i <= 0)
    {
       return(NULL);
    }
    return(new_line);
}