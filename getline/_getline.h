#ifndef _H_GETLINE
#define _H_GETLINE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define READ_SIZE 1024

char *_getline(const int fd);

#endif /* _H_GETLINE */