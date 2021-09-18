#include <stdio.h>
#include <stdlib.h>
#include "atof_sci.c"
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

// 栈值
double val[MAXVAL];
// 栈指针
int sp = 0;

char getop(char s[]);
void push(double f);
double pop();



int main()
{
    int c;
    char type, s[MAXOP];

    double op1, op2;

    while (type=getop(s)) {
        switch (type) {
            case NUMBER:
                push(atof_sci(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op1 = pop();
                push(pop() - op1);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                if (op2 != 0.0)
                    push(op2 / op1);
                else
                    printf("error: divide by zero");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}


char getop(char s[])
{
    int i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    for (i = 0; isdigit(s[i]); i++)
        ;

    if (i != 0 && s[i-1] >= '0' && s[i-1] <= '9')
        return NUMBER;

    if (s[i] == '\n')
        return '\n';

    return s[i];
}


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can not push %g\n", f);
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else
        printf("empty stack\n");
        return 0.0;
}

