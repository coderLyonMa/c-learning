#include <stdio.h>
void squeeze(char s[], char c);


int main()
{
    char a[] = "Hello world";
    char b[] = "Ok google";
    char c[] = "Ok computer";
    char d[] = "This world is a fine place";

    squeeze(a, 'o');
    squeeze(b, 'o');
    squeeze(c, 'o');
    squeeze(d, 'o');
    
    printf("squeezed:%s\t\n", a);
    printf("squeezed:%s\t\n", b);
    printf("squeezed:%s\t\n", c);
    printf("squeezed:%s\t\n", d);
}

void squeeze(char s[], char c)
{
    int i, j;
    // i负责向后遍历
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c) {
            s[j++] = s[i];
    }
    s[j] = '\0';
}
