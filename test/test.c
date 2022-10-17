#include <stdio.h>
#include <stdlib.h>
#include "../src/checkReservedKeyword.h"

int main(int argc, char* argv[])
{
    printf("--- Test Program for checkReservedKeyword function in cyclonedds --- \n");
    foo(atoi(argv[1]));

    return 0;
}

