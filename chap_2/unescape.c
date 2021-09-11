#include <stdio.h>
#define MAXLINE 1000

void unescape(char *s, char *t);

int main()
{
    char s[MAXLINE];
    char *a = "Hello\tworld\n\0";
    printf("%s", a);    
    unescape(s, a);
    printf("%s", s);
}

void unescape(char *s, char *t)
{
    int c;

    while ((c = *t++) != '\0') {

        if (c != '\\') {
            *s++ = c;
            continue;
        }

        switch (*t++) {
            case 'n':
                *s++ = '\n';
                break;
            case 't':
                *s++ = '\t';
                break;
            default:
                break;
        }
    }
    *s++ = '\0';
}

