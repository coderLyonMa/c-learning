#include <stdio.h>
#define TABW 4

int str_cmp(char*, char*);
int atoi(char*);


int main(int argc, char** argv)
{
    int pos = 1;
    int c;
    int tabw = 4;

    if (argc > 2) {
         if (str_cmp(*++argv, "-dw") == 0)
            tabw = atoi(*++argv);
         else {
            printf("Usage: detab -dw [TABWIDTH]\n");
        }
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            pos = 1;
            putchar(c);
        } else if (c == '\t') {
            int ns = (tabw - (pos - 1) % tabw);
            for (; ns > 0; --ns)
                ++pos, putchar(' ');
        } else {
            ++pos;
            putchar(c);
        }
    }

    return 0;
}

int str_cmp(char *s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
        ;

    return *s1 - *s2;
}

int atoi(char* s)
{
    int i = 0;

    while (*s) {
        i = i * 10 + *s - '0';
        ++s;
    }
    return i;
}
