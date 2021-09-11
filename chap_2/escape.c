#include <stdio.h>
#define MAXLINE 1000

void escape(char *s, char *t);

int main()
{
    char s[MAXLINE];
    char *a = "Hello\tworld\n";
    printf("%s", a);    
    escape(s, a);
    printf("%s", s);
}

void escape(char *s, char *t)
{
    int c;

    while ((c = *t++) != '\0') {

        if (c != '\t' && c != '\n') {
            *s++ = c;
            continue;
        }

        *s++ = '\\';

        switch (c) {
            case '\n':
                *s++ = 'n';
                break;
            case '\t':
                *s++ = 't';
                break;
            default:
                break;
        }
    }
    *s++ = '\\';
    *s++ = '0';
    *s++ = '\0';
}

