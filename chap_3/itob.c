#include "reverse.c"

void itob(int a, char s[], int b);

void itob(int a, char s[], int b)
{
    int i = 0;
    int c, sign;

    sign = a < 0 ? -1 : 1;

    do {
        c = a % b;


        if (sign > 0)
            s[i] = c + '0';
        else
            s[i] = (0 - c) + '0';
        if (c < b)
            s[++i] = '1';

        i++;

    } while (a /= 10);

    if (sign < 0)
        s[i++] = '-';


    //reverse(s);
    s[i] = '\0';
    reverse(s);

}
