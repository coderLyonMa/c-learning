#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

// 栈值
static double val[MAXVAL];
// 栈指针
static int sp = 0;


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can not push %g\n", f);
}

double pop()
{
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("empty stack\n");
        return 0.0;
    }
}

static void prt_top()
{
    if (sp > 0)
        printf("stack pointer now is pointing: <%g>\n", val[sp - 1]);
    else
        printf("empty stack\n");
}

void swap()
{
    if (sp < 2)
        printf("insufficient elements in the stack\n");
    else {
        int tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
    }
}

void cp_top()
{
    if (sp > 0) {
        int tmp = val[sp-1];
        val[sp++] = tmp;
    }
    else {
        printf("empty stack\n");
    }
}

/* rest the stack */
void reset()
{
    for (; sp > 0; sp--)
        ;
}
