int binsearch(int v[], int x, int n)
{
    int low, high, half;

    low = 0;
    high = n - 1;
    
    for (half = (low+high) / 2; low <= high; half = (low+high) / 2)
        if (v[half] > x)
            high = half - 1;
        else if (v[half] < x)
            low = half + 1;
        else
            return half;
    return -1;
}
