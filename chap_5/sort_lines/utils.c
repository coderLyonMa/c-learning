int strcmp(char* s, char* t)
{
    while (*s == *t) {
        s++;
        t++;
    }

    return *s - *t;
}

/* 为什么该函数的实现是错误的？ */
int n_strcmp(char* s, char* t)
{
    while (*s++ == *t++)
        ;

    return *s - *t;
}

void swap(char* s[], int i, int j)
{
    char* tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
