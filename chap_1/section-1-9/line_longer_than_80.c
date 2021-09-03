#include <stdio.h>
#define  LINE_LEN_ACCEPT 80
#define  MAX_LINES_NUM   100
#define  LINE_MAX_C      1000

int get_line(char s[], int limit);
void copy(char from[], char to[]);


int main()
{
    int len, line_num, lines_total;
    len = line_num = lines_total = 0;
    char line[LINE_MAX_C], lines[MAX_LINES_NUM][LINE_MAX_C];

    while ((len = get_line(line, LINE_MAX_C)) > 0) {
        lines_total++;
        if (len < LINE_LEN_ACCEPT)
            continue;

        copy(line, lines[line_num]);
        line_num++;
    }
    printf("%d lines input\n", lines_total);
    printf("%d lines with 80+ characters\n", line_num);

    for (int i = 0; i < line_num; i++)
        printf("%s", lines[i]);
}

int get_line(char s[], int limit)
{
    int i = 0;
    char c;
    
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < limit; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; i++)
        to[i] = from[i];
    to[i++] = '\0';
}
