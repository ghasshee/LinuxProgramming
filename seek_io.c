#include <sys/stat.h> 
#include <fcntl.h> 
#include <ctype.h> 
#include "lib/tlpi_hdr.h"


int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    chahr *buf;
    ssize_t numRead, numWritten;


    if (argc < 3 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>} ... \n", argv[0]);

    fd = open(argv[1], O_RDWR | O_CREAT, 

