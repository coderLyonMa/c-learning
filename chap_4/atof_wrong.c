#include <ctype.h>

double atof(char s[]);


double atof(char s[])
{
    int i;
    double sign;
    double df = 0.0;
    double e = 1.0;
    double f = 0.0;

    // 读取符号
    for (i = 0; s[i] != '+' && s[i] != '-'; i++)
        ;

    if (s[i] == '-' || s[i] == '+')
        sign = (s[i++] == '-') ? -1.0 : 1.0;
    // 跳过非数字字符
    for (; isdigit(s[i]) && s[i] != '.'; i++) {
        df = df  * 10.0 + (s[i] - '0');
    }

    if (s[i] == '.' && s[i + 1] != '\0') {
        // 跳过小数点
        i++;
        // 遍历到末尾, 并且确定最后一个数字的位
        for (; isdigit(s[i]); i++)
            e *= 0.1;
        i--;

        for (int j; s[i] != '.'; i--) {
            f += e * (s[i] - '0');
            e *= 10.0;
        }
            
    }

    return sign * (df + f);
}
