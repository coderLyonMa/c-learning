#include <stdio.h>
#include "calculator_stack.c"
#include "op.c"
#include "atof_sci.c"

#define MAXOP 100


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
