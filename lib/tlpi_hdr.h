#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h>  /* Type definitions */
#include <stdio.h> 
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* */
#include <string.h> 

#include "get_num.h"    /* getInt() getLong() */
#include "error_functions.h" 

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif 



