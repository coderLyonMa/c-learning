#include <stdio.h>
#define MAXC 1000

int str_len(char *s);
void reverse(char s[]);


int main()
{
    char s_1[] = "hello world"; 
    reverse(s_1);
    printf("%s\n", s_1);
    //printf("%d\n", str_len(s_1));
}


void reverse(char s[])
{
    char tmp;

    if (str_len(s) != 1) {
        tmp = *(s+1);
        *(s+1) = *s;
        *s = tmp;
    }

    reverse((s + 1));
}

int str_len(char *s)
{
    int i = 0;
    while (*s++ != '\0')
        i++;
    return i;
}
