#include <stdio.h>

/*
该版本很容易溢出
*/

int atoi(char s[]);

int main()
{
    char s_1[] = "hello world!";
    char s_2[] = "ok google";
    char s_3[] = "ok computer";
    
    printf("%s\t converted through atoi: %d\n", s_1, atoi(s_1));
    printf("%s converted through atoi: %d\n", s_2, atoi(s_2));
    printf("%s converted through atoi: %d\n", s_3, atoi(s_3));
}

int atoi(char s[])
{
    int i = 0;
    for (int j = 0; s[j] != '\0'; j++)
        i = s[j] - '\0' + i * 10;
    return i;
}

