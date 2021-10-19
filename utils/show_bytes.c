#include <stddef.h>
#include <stdio.h>


typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{


    for (int i = 0; i < len; ++i)
        printf("%p\t0x%.2x\n", &start[i], start[i]);
    // 等价于 *start++
    printf("\n");
}

void show_int_bytes(int i)
{
    printf("origin value: %d\nbyte in hex:\n", i);
    show_bytes((byte_pointer) &i, sizeof(int));
}

void show_float_bytes(float* fp)
{
    printf("origin value: %g\nbyte in hex:\n", *fp);
    show_bytes((byte_pointer) fp, sizeof(float));
}


