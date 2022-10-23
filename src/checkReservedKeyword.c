#include <stdio.h>
#include "checkReservedKeyword.h"

int foo(int param)
{
    printf("Primer cambio con GitLens instalado\n");
    printf("Cambio desde VS Code en la rama nueva_rama_vs_code, cambio 3\n");
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

    printf("--***** End foo *****--\n");

    return -1;
}

