#include <stdio.h>


int main()
{
    int d_min = ~(~0U >> 1);


    printf("%d", d_min % 10);

}
