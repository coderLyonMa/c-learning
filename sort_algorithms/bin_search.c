
int bin_search(int v[], int n, int x)
{
    int low, high, half;
    low = 0;
    high = n - 1;
    
    while (low < high) {
        half = (low + high) / 2;
        if (x < v[half])
            high = half - 1;
        else if (x > v[half])
            low = half + 1;
        else
            return half;
    }
    return -1;
}
