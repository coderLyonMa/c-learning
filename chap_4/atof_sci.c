#include <ctype.h>
#include <stdio.h>

double atof_sci(char s[]);

double atof_sci(char s[])
{
    int i = 0;
    double f = 0.0;
    double sign = 1.0;
    double power = 1.0;
    int e_sign = 1;
    int exp = 0;
    double e_power = 1.0;

    // 下面这样写会导致访问越界数组，core dump
    //     for (i = 0; isspace(s[i]) || s[i] != '+' || s[i] != '-'; i++) 这样遍历会越界
    for (i = 0; isspace(s[i]); i++)
        ;

    if (s[i] == '-') {
        i++;
        sign = -1.0;
    }

    for (; isdigit(s[i]); i++)
        f = f * 10.0 + s[i] - '0';

    if (s[i] == '.' && isdigit(s[i+1]))
        i++;

    for (; isdigit(s[i]); i++) {
        f = f * 10.0 + s[i] - '0';
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    if (s[i] == '-') {
        i++;
        e_sign = -1;
    }

    for (; isdigit(s[i]); i++)
        exp = exp * 10 + s[i] - '0';

    for (; e_sign == -1 && exp > 0; exp--)
        e_power /= 10.0;

    for (; e_sign == 1 && exp > 0; exp--)
        e_power *= 10.0;   


    return sign * f / power * e_power;

}
