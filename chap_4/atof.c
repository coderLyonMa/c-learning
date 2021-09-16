#include <ctype.h>

double atof(char s[]);


double atof(char s[])
{
    int i;
    double sign = 1.0;
    double n = 0.0;
    double power;

    // 读取符号
    for (i = 0; isspace(s[i]); i++)
        ;

    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i++] == '-') ? -1.0 : 1.0;
    }

    // 处理小数点前的数字
    for (; isdigit(s[i]) && s[i] != '.'; i++) {
        n = n  * 10.0 + (s[i] - '0');
    }

    if (s[i] == '.' && s[i + 1] != '\0') {
        // 跳过小数点
        i++;
        // 
        for (power = 1.0; isdigit(s[i]); i++) {
            n = n  * 10.0 + (s[i] - '0');
            power *= 10.0;
        }
    }

    return sign * n / power;
}
