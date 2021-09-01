#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

void copy(char from[], char to[]);

int main()
{
    int len = 0;  /* the length of the line is reading */ 
    int max = 0;    /* the longest length known */
    char line[MAXLINE]; /* the line is reading */
    char longest[MAXLINE]; /* the longest line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len >= max) {
            max = len;
            copy(line, longest);
        }
    }
    printf("\nThe longest line show as below:\n");
    printf("%s", longest);
    printf("The length of this sentence is %d\n", max);
}

int get_line(char s[], int lim)
{
    int i = 0;
    int c = 0;

    while (i < lim -1 && (c = getchar()) != EOF && c != '\n') {
        s[i] = c;
        ++i;
    }
/*    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim -1; ++i)
        s[i] = c; */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char from[], char to[])
{
    for (int i = 0; from[i] != '\0'; ++i)
        to[i] = from[i];
}

