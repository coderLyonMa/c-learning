#include <stdio.h>
#include "utils.h"


int main()
{
    char a[100] = "hello world";
    char *b = "ok google";

    str_ncat(a, 3, b);
    mysprint(a);
}

