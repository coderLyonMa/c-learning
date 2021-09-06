#include <stdio.h>
#define  LINE_MAX_C      1000





char line[LINE_MAX_C], longest[LINE_MAX_C];

int get_line(void);
void copy(void);


int main()
{
    extern int max;
    int len = 0;

    while ((len = get_line())) {
        if (len < max)
            continue;
        
        max = len;
        copy();
    }

    printf("The longest line is :\t%s", longest);
    printf("The lenght of the line is : %d", max);
}


int get_line()
{
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        i++;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}


void copy()
{
    int i = 0;
    for (; (longest[i] = line[i]) != '\0'; i++)
        ;
    longest[i] = '\0';
}

int max = 0;

