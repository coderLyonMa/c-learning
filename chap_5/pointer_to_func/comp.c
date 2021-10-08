int str_cmp(char* s1, char* s2)
{
    for (; *s1 == *s2 && *s1 && *s2; s1++, s2++)
        ;

    return *s1 - *s2;
}

int str_fcmp(char* s1, char* s2)
{
    int is_alpha(char c);
    int cmp_alpha(char a, char b);

    for (;*s1 && *s2; s1++, s2++) {
        if (*s1 == *s2)
            continue;
        if (is_alpha(*s1) && is_alpha(*s2) && cmp_alpha(*s1, *s2))
            continue;
    }

    return *s1 - *s2;
}

int num_cmp(char* s1, char* s2)
{
    double v1, v2;
    double atof(char* s);

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v2 > v1)
        return 1;
    else
        return 0;
}


double atof(char* s)
{
    double f;

    for (f = 0.0; *s; s++)
        f = f * 10.0 + *s;

    return f;
}

int is_alpha(char c)
{
    return c >= 'a' && c <= 'Z';
}

int cmp_alpha(char a, char b)
{
    int i = a - b;
    return i == 26 || i == -26 || i == 0;
}
