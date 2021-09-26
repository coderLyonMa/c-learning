#include <stdio.h>
#include "alloc.h"
#include "get_line.h"
#include "sort_lines.h"

/* 最多读取5000行 */
#define LINESMAX 5000
#define MAXLINE 1000

void strcp(char* s, char* t);
void write_lines(char* lines[], int nlines);
int read_lines(char* lines[]);


char* lines[LINESMAX];
char line[1000];


int main()
{

    // 读取所有的行
    int n = read_lines(lines);

    q_sort(lines, 0, n - 1);

    //for (int i = 0; i < n - 1; i++)
    //    printf("%s\n", lines[i]);
    //return 0;
    printf("==========================\n");
    write_lines(lines, n);
    // 排序
    // 打印排序后的行

    return 0;
}


/* 返回行号 */
int read_lines(char* lines[])
{
    char* p;
    int len, nlines;

    nlines = 0;

    while ((len = get_line(line, MAXLINE)) && (nlines < LINESMAX)) {
        p = alloc(len);
        if (p == NULL) {
            printf("no more memory!");
            return -1;
        }

        line[len-1] = '\0';
        strcp(line, p);
        lines[nlines++] = p;
        //printf("%s\n", lines[nlines-1]);
    }
    return nlines;
}

void write_lines(char* lines[], int nlines)
{
    int i = 0;
    while (nlines--)
        printf("%s\n", lines[i++]);
}


void strcp(char* s, char* t)
{
    while (*t++ = *s++)
        ;
}

