void q_sort(void** v, int left, int right, int (*comp)(void*, void*))
{
    int last, i;
    void swap(void* v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}


void swap(void* v[], int i, int j)
{
    // v 作为参数被传入，调用栈内拷贝了其地址，用数组索引访问的其实是对应的数组元素的地址，为数组元素地址赋值相当于修改对应指针的值
    void* tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}


