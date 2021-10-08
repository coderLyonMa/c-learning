int str_cmp(char* s1, char* s2)
{
    for (; *s1 == *s2 && *s1 && *s2; s1++, s2++)
        ;

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

