void insertion_sort(int v[], int n)
{
    int i, j, tmp;

    for (i = 0; i < n - 1; ++i)
        for (j = i; j >= 0 && v[j] > v[j+1]; --j)
            tmp = v[j], v[j] = v[j+1], v[j+1] = tmp;
}
