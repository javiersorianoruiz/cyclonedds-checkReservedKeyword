#include <stdio.h>
#include "checkReservedKeyword.h"

int foo(int param)
{
    if (param==0)
    {
        printf("foo param == 0\n");

        return 0;
    }
    else if (param < 0)
    {
        printf("foo param < 0\n");
    }
    else
    {
        printf("foo param > 0\n");
    }

    printf("***** End foo *****\n");

    return -1;
}

