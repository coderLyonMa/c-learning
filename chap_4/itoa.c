#include <stdio.h>
#include <stdlib.h> 
#define SIZE 100

void itoa(int n, char s[]);

int main()
{
    char s_1[SIZE];
    itoa(-12345, s_1);
    printf("%s", s_1);
}


void itoa(int n, char s[])
{
    static int i;

    /* baseline 个位数 */
    if (n / 10 != 0)
        itoa(n / 10, s);
    else if (n < 0) {
        s[0] = '-';
        i++;
    }
        
    /* 将要取的10进制位，移动到个位 */    


    s[i++] = abs(n) % 10 + '0';
}
