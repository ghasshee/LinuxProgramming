#define _BSD_SOURCE         /* Get major() and minor() from <sys/types.h> */
#include <sys/types.h>
#include <sys/stat.h> 
#include <time.h>
#include "file_perms.h"
#include "file_perms.c"
#include "tlpi_hdr.h"
#include "error_functions.c"
#include <sys/sysmacros.h>

static void 
displayStatInfo(const struct stat *sb)
{
    printf("File type:                      ");

    switch (sb->st_mode & S_IFMT) {
        case S_IFREG:   printf("regular file         \n");   break;
        case S_IFDIR:   printf("directory            \n");   break;
        case S_IFCHR:   printf("character device     \n");   break;
        case S_IFBLK:   printf("block device         \n");   break;
        case S_IFLNK:   printf("symbolic (soft) link \n");   break;
        case S_IFIFO:   printf("FIFO or pipe         \n");   break;
        case S_IFSOCK:  printf("socket               \n");   break;
        default:        printf("unknown file type?   \n");   break;
    } 

    printf("Device containing i-node: major=%ld     minor=%ld\n",
            (long) major(sb->st_dev), (long) minor(sb->st_dev)); 

    printf("I-node number:                  %ld\n", 
            (long) sb->st_ino); 

    printf("Mode:                           %lo (%s)\n",
            (unsigned long) sb->st_mode, filePermStr(sb->st_mode, 0));

    if (sb->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
        printf("        special bits set:       %s%s%s\n",
                (sb->st_mode & S_ISUID) ? "set-UID " : "",
                (sb->st_mode & S_ISGID) ? "set-GID " : "",
                (sb->st_mode & S_ISVTX) ? "sticky  " : "");

    printf("Number of (hard) links:         %ld\n",
            (long) sb->st_nlink);

    printf("Ownership:      UID=%ld     GID=%ld\n",
            (long) sb->st_uid,  (long) sb->st_gid);

    if (S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode))
        printf("Device number (st_rdev):    major=%ld; minor=%ld\n",
                (long) major(sb->st_rdev), (long) minor(sb->st_rdev));

    printf("File size:                      %lld bytes\n",
            (long long) sb->st_size);

    printf("Optimal I/O block size:         %ld bytes\n",
            (long) sb->st_blksize);

    printf("512B blocks allocated:          %lld\n",
            (long long) sb->st_blocks); 

    printf("Last file access:               %s", 
            ctime(&sb->st_atime));

    printf("Last file modification:         %s", 
            ctime(&sb->st_mtime));

    printf("Last status chanage:            %s", 
            ctime(&sb->st_ctime));

}

int 
main(int argc, char *argv[])
{

    struct stat sb;
    Boolean statLink;
    int fname;

    statLink = (argc > 1) && strcmp(argv[1], "-1") == 0;

    fname = statLink ? 2 : 1;

    if (fname >= argc || (argc > 1 && strcmp(argv[1], "--help") == 0))
        usageErr("%s [-l] file\n"
                "           -l = use lstat() insted of stat()\n", argv[0]);

    if (statLink) {
        if (lstat(argv[fname], &sb) == -1)
            errExit("lstat");
    } else{
        if (stat(argv[fname],  &sb) == -1)
            errExit("stat");
    }

    displayStatInfo(&sb);

    exit(EXIT_SUCCESS);


}



/*
static void
usageError(const char *progName, const char *msg)
{
    if (msg != NULL)
        fprintf(stderr, "%s", msg);

    fprintf(stderr, "Usage: %s [options] source target\n\n", progName);
    fprintf(stderr, "Available options:\n");
#define fpe(str) fprintf(stderr, "    " str)   
    fpe("-t fstype        [e.g., 'ext2' or 'reiserfs']\n");
    fpe("-o data          [file system-dependent options,\n");
    fpe("                 e.g., 'bsdgroups' for ext2]\n");
    fpe("-f mountflags    can include any of:\n");
#define fpe2(str) fprintf(stderr, "            " str)
    fpe2("b - MS_BIND         create a bind mount\n");
    fpe2("d - MS_DIRSYNC      synchronous directory updates\n");
    fpe2("l - MS_MANDLOCK     permit mandatory locking\n");
    fpe2("L - MS_LAZYATIME    lazy atime updates\n");
    fpe2("m - MS_MOVE         atomically move subtree\n");
    fpe2("A - MS_NOATIME      don't update atime (last access time)\n");
    fpe2("V - MS_NODEV        don't permit device access\n");
    fpe2("D - MS_NODIRATIME   don't update atime on directories\n");
    fpe2("E - MS_NOEXEC       don't allow executables\n");
    fpe2("S - MS_NOSUID       disable set-user/group-ID programs\n");
    fpe2("p - MS_PRIVATE      mark as private\n");
    fpe2("r - MS_RDONLY       read-only mount\n");
    fpe2("c - MS_REC          recursive mount\n");
    fpe2("T - MS_RELATIME     relative atime updates\n");
    fpe2("R - MS_REMOUNT      remount\n");
    fpe2("h - MS_SHARED       mark as shared\n");
    fpe2("v - MS_SLAVE        mark as slave\n");
    fpe2("s - MS_SYNCHRONOUS  make writes synchronous\n");
    fpe2("u - MS_UNBINDABLE   mark as unbindable\n");
    exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
    unsigned long flags;
    char *data, *fstype;
    int j, opt;

    flags = 0;
    data = NULL;
    fstype = NULL;

    while ((opt = getopt(argc, argv, "o:t:f:")) != -1) {
        switch (opt) {
        case 'o':
            data = optarg;
            break;

        case 't':
            fstype = optarg;
            break;

        case 'f':
            for (j = 0; j < strlen(optarg); j++) {


                switch (optarg[j]) {
                case 'b': flags |= MS_BIND;             break;
                case 'd': flags |= MS_DIRSYNC;          break;
                case 'l': flags |= MS_MANDLOCK;         break;
                case 'm': flags |= MS_MOVE;             break;
                case 'A': flags |= MS_NOATIME;          break;
                case 'V': flags |= MS_NODEV;            break;
                case 'D': flags |= MS_NODIRATIME;       break;
                case 'E': flags |= MS_NOEXEC;           break;
                case 'S': flags |= MS_NOSUID;           break;
                case 'p': flags |= MS_PRIVATE;          break;
                case 'r': flags |= MS_RDONLY;           break;
                case 'c': flags |= MS_REC;              break;
                case 'T': flags |= MS_RELATIME;         break;
                case 'R': flags |= MS_REMOUNT;          break;
                case 'h': flags |= MS_SHARED;           break;
                case 'v': flags |= MS_SLAVE;            break;
                case 's': flags |= MS_SYNCHRONOUS;      break;
                case 'u': flags |= MS_UNBINDABLE;       break;
                default:  usageError(argv[0], NULL);
                }
            }
            break;

        default:
            usageError(argv[0], NULL);
        }
    }

    if (argc != optind + 2)
        usageError(argv[0], "Wrong number of arguments\n");

    if (mount(argv[optind], argv[optind + 1], fstype, flags, data) == -1)
        errExit("mount");

    exit(EXIT_SUCCESS);
}
*/
