#include <stdio.h>
#define FLAG 0x80

typedef unsigned char* byte_pointer;

void show_bits(byte_pointer start, size_t len)
{
    for (int i = 0; i < len; ++i) {
        for (char byte = start[i], j = 0; j < 8; ++j, byte <<= 1)
           printf("%d", (byte & FLAG) >> 7);
        printf("%s", i != len ? " " : "");
    }
    printf("\n");
}

void show_int_bits(int i)
{
    show_bits((byte_pointer) &i, sizeof(int));
}

void show_char_bits(char c)
{
    show_bits((byte_pointer) &c, sizeof(char));
}

