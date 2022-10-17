#include <stdio.h>
#include "checkReservedKeyword.h"

void foo(int param)
{
    if (param==0)
    {
        printf("foo param == 0\n");
    }
    else if (param < 0)
    {
        printf("foo param < 0\n");
    }
    else
    {
        printf("foo param > 0\n");
    }
}

