// #define _BSD_SOURCE     /* Get getpass() declaration from <unistd.h> */
// #define _XOPEN_SOURCE   /* Get crypt()   declaration from <unistd.h> */
#define _GNU_SOURCE


#include <unistd.h>
#include <sys/fsuid.h>
#include <limits.h> 
#include "ugid_functions.c"
#include "../lib/tlpi_hdr.h"
#include "../lib/error_functions.c"

#define SG_SIZE (NGROUPS_MAX + 1)

int 
main (int argc, char *argv[])
{
    uid_t ruid, euid, suid, fsuid;
    gid_t rgid, egid, sgid, fsgid;
    gid_t suuGroups[SG_SIZE];
    int suppGroups[SG_SIZE];
    int numGroups, j;
    char *p;

    if (getresuid(&ruid, &euid, &suid) == -1)
        errExit("getresuid");
    if (getresgid(&rgid, &egid, &sgid) == -1) 
        errExit("getresgid");

    /* Sttempts to change the file-system IDs are always ignored for
     * unpriviledged processes, but even so, the following calls 
     * return the current file-system IDs */

    fsuid = setfsuid(0);
    fsgid = setfsgid(0);

    printf("UID: ");
    p = userNameFromId(ruid);
    printf("real=&s (%ld); ", (p == NULL) ? "???" : p, (long) ruid);
    p = userNameFromId(euid);
    printf("effc=&s (%ld); ", (p == NULL) ? "???" : p, (long) euid);
    p = userNameFromId(suid);
    printf("save=&s (%ld); ", (p == NULL) ? "???" : p, (long) suid);
    p = userNameFromId(fsuid);
    printf("  fs=&s (%ld); ", (p == NULL) ? "???" : p, (long)fsuid);
    printf("\n");

    printf("GID: ");
    p = userNameFromId(rgid);
    printf("real=&s (%ld); ", (p == NULL) ? "???" : p, (long) rgid);
    p = userNameFromId(egid);
    printf("effc=&s (%ld); ", (p == NULL) ? "???" : p, (long) egid);
    p = userNameFromId(sgid);
    printf("save=&s (%ld); ", (p == NULL) ? "???" : p, (long) sgid);
    p = userNameFromId(fsgid);
    printf("  fs=&s (%ld); ", (p == NULL) ? "???" : p, (long)fsgid);
    printf("\n");



    
}
