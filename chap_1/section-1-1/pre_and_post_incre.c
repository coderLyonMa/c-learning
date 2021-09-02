#include <stdio.h>

int main()
{
    int pre = 0;
    int post = 0;

    for (int i = 0; i < 5; i++) {
        printf("The post here is %d\n", ++pre);
        printf("The pre  here is %d\n", post++);
    }
}
