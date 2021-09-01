#include <stdio.h>

int atoi(char s[]);

int main()
{
    printf("The value of string '2043664' is %d\n", atoi("2043664"));
}

int atoi(char s[])
{
    int ret = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}

