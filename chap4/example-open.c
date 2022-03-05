#include <sys/stat.h> 
#include <fcntl.h> 
#include "../lib/tlpi_hdr.h"
#include "../lib/error_functions.h"
#include "../lib/error_functions.c"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif 

int 
main(int argc, char *argv[])
{
    int fd; 
    /*
    fd = open("startup", O_RDONLY); 

    if (fd == -1) 
        errExit("open");
    close(fd); 

    fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open"); 
    close(fd); 
    fd = open("w.log", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);

    if (fd == -1) 
        errExit("open");
    close(fd); 
    */

    fd = creat("w.log", O_WRONLY | O_CREAT | O_APPEND);
    close(fd); 
}
