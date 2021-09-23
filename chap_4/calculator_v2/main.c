#include <stdio.h>
#include <stdlib.h>
#include "../atof_sci.c"

#include "calc.h"
#include "stack.c"
#include "getop.c"
#include "getch.c"


#define MAXOP 100


int main()
{
    int c;
    char type, s[MAXOP];

    double op1, op2;
    long lop1, lop2;

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
            case '%':
                lop1 = (long) pop();
                lop2 = (long) pop();
                push(lop2 % lop1);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'p':
                prt_top();
                break;
            case 's':
                swap();
                break;
            case 'c':
                cp_top();
                break;
            case 'r':
                reset();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

