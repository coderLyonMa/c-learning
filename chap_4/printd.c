#include <stdio.h>
#define my_printd(x) {printd(x); printf("\n");}


void printd(int n);


int main()
{
    my_printd(12345);
    my_printd(54321);
    my_printd(-2147483648);

}

void printd(int n)
{
    if (n < 0) {
        printf("-");
        // ~(~0U >> 1) not supported
        n = -n;
    }

    if (n / 10)
        printd(n / 10);
    printf("%d", n % 10);
}
