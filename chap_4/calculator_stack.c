#define NUMBER '0'
#define MAXVAL 100

void push(double f);
double pop();

// 栈值
double val[MAXVAL];
// 栈指针
int sp = 0;




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
