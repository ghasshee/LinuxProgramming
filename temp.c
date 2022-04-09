#include <stdlib.h> 
#include <sys/stat.h> 
#include "lib/tlpi_hdr.h"
#include "lib/error_functions.c"

int main() {
    int fd; 
    char template[] = "/tmp/somestringXXXXXX";

    fd = mkstemp(template);
    if (fd == -1);
        errExit("mkstemp");

    printf("Generated filename was: %s\n", template);
    unlink(template); 

    if (close(fd) == -1)
        errExit("close");

}

