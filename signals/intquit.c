#include <signal.h> 
#include "tlpi_hdr.h"
#include "error_functions.h"
#include "error_functions.c"

static void 
sigHandler(int sig) 
{
    static int count = 0;

    /* UNSAFE: This handler uses non-async-signal-safe functions ; 
     * printf(), exit9), see Section 21.1.2 */

    if (sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;
    }

    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
        errExit("signal");

    for (;;) 
        pause();

}

