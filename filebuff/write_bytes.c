
#include <sys/stat.h>
#include <fcntl.h> 
#include "tlpi_hdr.h"
#include "error_functions.c"
#include "get_num.c"



int
main(int argc, char *argv[])
{
    if (argc != 4 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file num-bytes buf-size\n", argv[0]);

    size_t numBytes = getLong(argv[2], GN_GT_0, "num-bytes");
    size_t bufSize = getLong(argv[3], GN_GT_0, "buf-size");

    char *buf = malloc(bufSize);
    if (buf == NULL)
        errExit("malloc");

    int openFlags = O_CREAT | O_WRONLY;

#if defined(USE_O_SYNC) && defined(O_SYNC)
    openFlags |= O_SYNC;
#endif

    int fd = open(argv[1], openFlags, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");

    size_t thisWrite, totWritten;
    for (totWritten = 0; totWritten < numBytes;
            totWritten += thisWrite) {
        thisWrite = min(bufSize, numBytes - totWritten);

        if (write(fd, buf, thisWrite) != thisWrite)
            fatal("partial/failed write");

#ifdef USE_FSYNC
        if (fsync(fd))
            errExit("fsync");
#endif
#ifdef USE_FDATASYNC
        if (fdatasync(fd))
            errExit("fdatasync");
#endif
    }

    if (close(fd) == -1)
        errExit("close");
    exit(EXIT_SUCCESS);
}
