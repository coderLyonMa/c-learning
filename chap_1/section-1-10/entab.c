#include <stdio.h>
#include <debug_macros.h>

#define TABW 8
#define BUFFSIZE 100

static char buff[BUFFSIZE];
char* buffp = buff;

int getch(void);
void ungetch(int c);
int count_spaces(void);


int main()
{
    int c, pos;

    pos = 1;

    while ((c = getch()) != EOF) {
        if (c == '\n') {
            pos = 1;
            putchar(c);
        } else if (c == ' ') {

            int ns = 1 + count_spaces();
            // printd(ns);

            // no tran
            if (((pos - 1) % TABW) + ns < TABW) {
                for (; ns > 0; --ns)
                    putchar(' '), ++pos;
            } else {
                int tabn = (((pos - 1) % TABW) + ns) / TABW;
                int spacen = (((pos - 1) % TABW) + ns) % TABW;

                for (; tabn > 0; --tabn)
                    putchar('\t');
                for (; spacen > 0; --spacen)
                    putchar(' ');
                
                pos += ns;
            }
        } else {
            ++pos;
            putchar(c);
        }
    }

    return 0;
}

int count_spaces(void)
{
    int c;
    int ns = 0;

    while ((c = getch()) != EOF && c == ' ')
        ++ns;

    ungetch(c);

    return ns;
}

int getch(void)
{
    return (buffp > buff) ? *--buffp : getchar();
}

void ungetch(int c)
{
    if (buffp >= buff + BUFFSIZE)
        printf("Buff size exceeded\n");
    else
        *buffp++ = c;
}


