#include <stdio.h>
void lower(char s[]);


int main()
{
    char a[] = "HelloO woRld";
    char b[] = "Ok googlE";
    char c[] = "Ok cOMputer";
    char d[] = "This WORLD is a fine place";

    lower(a);
    lower(b);
    lower(c);
    lower(d);
    
    printf("squeezed:%s\t\n", a);
    printf("squeezed:%s\t\n", b);
    printf("squeezed:%s\t\n", c);
    printf("squeezed:%s\t\n", d);
}

void lower(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'a' + s[i] - 'A';
    s[i] = '\0';
}
