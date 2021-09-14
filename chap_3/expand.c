#include <ctype.h>


void expand(char s[])
{
    int i = 0;
    int from;

    // 读取字符
    // 需要记录状态，如果在一段有效标记内，就继续往前读，直到读到下一个空字符
    // a-b-c
    // 这些字符必定是连续的，那么其实位置s[start] ~ s[end], 边界条件是
    while (s[i] && !isspace(s[i])) {
        if (s[i] == '')
        if (s[i] == '-' && state == OUT) {
            continue;
        }
        if (s[i] != '-' && state == OUT) {
            from = []
            state = IN;
        }

        
        for (int i = s[start]; i <= end; i++)
            s[i] = i;
    }

}
