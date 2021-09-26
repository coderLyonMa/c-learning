int strcmp(char* s, char* t)
{
    while (*s == *t) {
        s++;
        t++;
    }

    return *s - *t;
}

/* 
为什么该函数的实现是错误的？
因为当第一次匹配到不相等的字符之后，下一个循环虽然得到了false，但是指针又向前移动了一次
解决方案，指针向前回退一次即可
*/

int n_strcmp(char* s, char* t)
{
    while (*s++ == *t++)
        ;

    return *(--s) - *(--t);
}

void swap(char* s[], int i, int j)
{
    char* tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
