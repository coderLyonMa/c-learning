#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char *itoa(int n, char *s);

int main()
{
    char s_1[SIZE];
    //itoa(12345, s_1);
    printf("%s", itoa(12345, s_1));
}


char *itoa(int n, char *s)
{
    int stack = 0;
    char *a;

    if (n / 10) {
        stack++;
        itoa(n / 10, s + 1);
    }

    if (stack == 0) {
        *s = n % 10 + '0';
        for (; isdigit(*s); s++)
            ;
        

        while ((*a = *s)) {
            a++;
            s--;
        }

        return a;
    }

    *s = n % 10 + '0';
}
