#include <sys/stat.h> 
#include <fcntl.h> 


#include "tlpi_hdr.h"
#include "error_functions.h"
#include "error_functions.c"

#define CMD_SIZE 0

int 
main(int argc, char *argv[])
{
    int fd, j, numBlocks; 
    char shellCmd[CMD_SIZE];
    char buf[BUF_SIZE];

    if (argc < 2 ) {};


    exit(EXIT_SUCCESS);


}
