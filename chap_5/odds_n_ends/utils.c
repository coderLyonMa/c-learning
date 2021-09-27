int str_len(char *s)
{
    int i = 0;
    while (*s++)
        i++;
    return i;
}

int n_strcmp(char* a, char* b)
{
    while (*a++ == *b++) {
        ;
    }

    return *a - *b;
}

int strcmp(char* s, char* t)
{
    while (*s == *t) {
        s++;
        t++;
    }

    return *s - *t;
}

void str_cat(char* s, char* t)
{
    while (*++s)
        ;

    while (*s++ = *t++)
        ;
}

int str_end(char* s, char* t)
{
    char *t0 = t;
    while (*++s)
        ;

    while (*++t)
        ;

    for (; *t == *s; t--, s--)
        if (t == t0)
            return 1;

    return -1;
}

void str_ncp(char* s, int n, char* t)
{
    while (n > 0) {
        *s++ = *t++;
        n--;
    }
}

int str_ncmp(char* s, int n, char* t)
{
    if (!n)
        return n;

    for (; n > 1 && *(s+1) && *(t+1); n--)
        s++, t++;

    return *s - *t;
}

/* 将t中最多n个字符链接到s的尾部 */
void str_ncat(char* s, int n, char* t)
{
    while (*++s)
        ;

    while (n > 0 && (*s = *t)) {
        s++;
        t++;
        n--;
    }
}

