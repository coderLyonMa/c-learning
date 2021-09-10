#include <stdio.h>
void squeeze(char s1[], char s2[]);


int main()
{
    char a[] = "Hello world";
    char b[] = "Ok google";
    char c[] = "Ok computer";
    char d[] = "This world is a fine place";

    squeeze(a, "eo");
    squeeze(b, "ge");
    squeeze(c, "mp");
    squeeze(d, "ia");
    
    printf("squeezed:%s\t\n", a);
    printf("squeezed:%s\t\n", b);
    printf("squeezed:%s\t\n", c);
    printf("squeezed:%s\t\n", d);
}

void squeeze(char s1[], char s2[])
{

    int i, j, k;

    for (k = i = 0; s1[i] != '\0'; i++) {
        // 先写边界条件
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
