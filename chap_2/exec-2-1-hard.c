#include <stdio.h>

int main()
{
    // int
    printf("Max of unsigned int is : %d\n", ((int)(unsigned int) ~0 >> 1));
    printf("Minimum value of signed int is : %d\n",
            -((int)(unsigned int) ~0 >> 1));
    printf("Maximum value of signed int is : %d\n",
            (int)((unsigned int) ~0 >> 1));
    
    // uint
    unsigned int ret_uint = 0U;
    printf("Minimum value of unsigned int is : %ud\n", ret_uint - 1);
    // char
    char ret_char = 0;
//    while (ret_char >= 0) {
//        ++ret_char;
//    }
    printf("Maximum value of signed char is : %d\n", 
            -(char)((unsigned char) ~0 >> 1));
    printf("Minimum value of signed char is : %d\n", 
            (char)((unsigned char) ~0 >> 1));
    // uchar
    unsigned char ret_uchar = 0U;
    printf ("Maxmum value of unsigned char is :%d\n", ret_uchar - 1);
    // short
    // ushort
    // long
    // ulong
}
