#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include "../lib/tlpi_hdr.h"
#include "../lib/error_functions.h"
#include "../lib/error_functions.c"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif 

#define MAX_READ 20 
char buffer[MAX_READ]; 

int 
main(int argc, char *argv[])
{
    if (read(STDIN_FILENO, buffer, MAX_READ) == -1)
        errExit("read");

    printf("The input data was: %s\n", buffer);

}
