#include <stdio.h>
#define MAXC 1000

int str_len(char *s);
void reverse(char s[], int l, int r);


int main()
{
    char s_1[] = "hello world"; 
    reverse(s_1, 0, str_len(s_1) - 1);
    printf("%s\n", s_1);
//    printf("%d\n", str_len(s_1));
}


void reverse(char s[], int l, int r)
{
    char tmp;

    if (r - l <= 0) {
        return;
    }

    tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
    reverse(s, l+1, r-1);
}

int str_len(char *s)
{
    int i = 0;
    while (*s++ != '\0')
        i++;
    return i;
}
