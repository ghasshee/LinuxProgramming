#include "../lib/tlpi_hdr.h"
#include "../lib/error_functions.c"

#define MAX_ALLOCS 1000000

int
main(int argc, char *argv[])
{
    char *ptr[MAX_ALLOCS]; 
    int freeStep, freeMin, freeMax, blockSize, numAllocs, j;

    printf("\n");

    if (argc < 3 || strcmp(argv[1], "--help") == 0) 
        usageErr("%s num-allocs block-size [step [min [max]]]\n", argv[0]);

    numAllocs = getInt(argv[1]. GN_GT_0, "num-allocs");
    if (numAllocs > MAX_ALLOCS) 
        cmdLineErr("num-allocs > %d\n", MAX_ALLOCS); 

    blockSize = getInt(argv[2], GN_GT_0 | GN_ANY_BASE, "block-size");

    freeStep = (argc > 3) ? getInt(argv[3], GN_GT_0, "step") : 1;
    freeMin  = (argc > 4) ? getInt(argv[4], GN_GT_0, "min")  : 1;
    freeMax  = (argc > 5) ? getInt(
