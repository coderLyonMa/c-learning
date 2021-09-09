#include <stdio.h>
void squeeze(char s1[], char s2[]);


int main()
{
    char a[] = "Hello world";
    char b[] = "Ok google";
    char c[] = "Ok computer";
    char d[] = "This world is a fine place";

    squeeze(a, "ll");
    squeeze(b, "go");
    squeeze(c, "t");
    squeeze(d, "is");
    
    printf("squeezed:%s\t\n", a);
    printf("squeezed:%s\t\n", b);
    printf("squeezed:%s\t\n", c);
    printf("squeezed:%s\t\n", d);
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    // i负责向后遍历
    for (i = 0; s_1[i] != '\0'; i++)
        for (j = i, k = 0; s_1[j] == s_2[k]; j++, k++)
            if (s_2[k] == '\0' && k) {
                i += j;
        }
        s_1[i] = s_2[k]
    s[j] = '\0';
}
