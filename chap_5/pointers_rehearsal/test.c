#include "utils.h"
#define MAXLINE 1000

void test_get_line(void);
void test_strindex(void);
void test_itoa();
void test_reverse();


int main()
{
    test_itoa();
}

void test_get_line()
{
    char line[MAXLINE];
    int len;

    while (len = get_line(line, MAXLINE)) {
        printf("%s", line);
    }
}

void test_strindex()
{
    char a[MAXLINE];
    char b[MAXLINE];
    get_line(a, MAXLINE);
//    get_line(b, MAXLINE);
//    mysprint(a);
  //  mysprint(b);
//    dprintc(a[10]);


    dprint(atoi(a));
}

void test_itoa()
{
    char a[MAXLINE];

    get_line(a, MAXLINE);
    int n;
    dprint(n = atoi(a));

    char b[MAXLINE];
    itoa(n, b);

    mysprint(b);

}

void test_reverse()
{
    char s[] = "hello world";
    reverse(s);
    mysprint(s);
}

