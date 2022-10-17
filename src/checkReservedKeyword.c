#include <stdio.h>
#include "checkReservedKeyword.h"

void foo(int param)
{
    if (param)
    {
        printf("foo param != 0\n");
    }
    else
    {
        printf("foo param == 0\n");
    }
}

