#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 10
#define BUFFSIZE 100


int getint(int* pn);
char getch(void);
void ungetch(char );

int buff[BUFFSIZE];
int bufp = 0;


int main()
{
    int v[SIZE];
    int getint(int* pn);

    for (int i = 0; i < SIZE && getint(&v[i]) != EOF; i++)
        ;

    for (int i = 0; i < SIZE; i++)
        printf("%d\n", v[i]);
}

int getint(int* pn)
{
    *pn = 0;
    int c;

    // 一个循环就是一个监听
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    if (c == EOF)
        return c;

    int sign = c == '-' ? -1 : 1;

    //while (!isdigit(c = getch()))
    //    ; 这样写可能会跳过一个符合预期的字符

    // 非常重要！！这里要读很多遍
    //while (!isdigit(c) && !isdigit(c = getch())) {
    //    if (c == '-' || c == '+')
    //        ungetch(c);
    //}

    // bug case: input = - + 12345
    if (!isdigit(c))
        while (isspace(c = getch()))
            ;

    for (c; isdigit(c); c = getch())
        *pn = *pn * 10 + c - '0';
    *pn *= sign;

    if (c != EOF)
        return 0;

    return c;
}

char getch()
{
    return bufp > 0 ? buff[--bufp] : getchar();
}

void ungetch(char c)
{
    if (bufp >= BUFFSIZE)
        return ;
    else
        buff[bufp++] = c;
}


