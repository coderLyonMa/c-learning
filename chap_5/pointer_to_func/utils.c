void reverse_arr(void **v)
{
    int i = 0;
    void* tmp;

    while (v[i+1])
        i++;

    for (int j = 0; j < i; j++, i--)
        tmp = v[i], v[i] = v[j], v[j] = tmp;
}

