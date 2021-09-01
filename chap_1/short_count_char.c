# include <stdio.h>

int main ()
{
    long nc;
    char c;

    for (nc = 0; (c = getchar()) != EOF; ++nc)
        ;
    printf("%ld characters input\n", nc);
}

