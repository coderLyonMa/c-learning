#include "show_bytes.h"
#include <stddef.h>
#include <stdio.h>
#include <debug_macros.h>


typedef size_t Int;

int main()
{
    int i = ~(~0U >> 1);

    show_int_bytes(i);
}

