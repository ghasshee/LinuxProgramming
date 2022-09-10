#include <dirent.h> 

#include "tlpi_hdr.h"
#include "error_functions.h"
#include "error_functions.c"

static void 
listFiles(const char *dirpath) 
{ 
    DIR *dirp;
    struct dirent *dp;
    Boolean isCurrent;

    isCurrent = strcmp(dirpath, ".") == 0;

    dirp = opendir(dirpath);
    if (dirp == NULL) {
        errMsg("opendir failed on '%s'", dirpath);
        return;
    }

    /* For each entry in this dir, print dir + filename */

    for (;;) {
        errno = 0;
        dp = readdir(dirp);
        if (dp == NULL) 
            break;

        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        if (!isCurrent)
            printf("%s/", dirpath);
        printf("%s\n", dp->d_name);
    }

    if (errno != 0) 
        errExit("readdir");

    if (closedir(dirp) == -1)
        errExit("closedir");
}

int 
main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [dir...]\n", argv[0]);

    if (argc == 1)
        listFiles(".");
    else
        for (argv++; *argv; argv++)
            listFiles(*argv);


    exit(EXIT_SUCCESS);


}
