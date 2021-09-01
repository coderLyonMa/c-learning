#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int   ret_int = 0;
    short ret_sh = 0;
    char  ret_char = 0;

    while (ret_int >= 0) {
        ++ret_int;
    }
    while (ret_sh >= 0) {
        ++ret_sh;
    }
    while (ret_char >= 0) {
        ++ret_char;
    }
    
    printf("The max value of int is %d\n", ret_int - 1);
    printf("The min value of int is %d\n", ret_int);
    printf("The max value of short int is %d\n", ret_sh - 1);
    printf("The min value of short int is %d\n", ret_sh);
    printf("The max value of char is %d\n", ret_char - 1);
    printf("The min value of char is %d\n", ret_char);


}
