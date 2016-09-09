int iLoveYukiNagato(int *num, const int size, const int k) {
    int x = num[size >> 1];
    int i = 0, j = size-1, t;
    do {
        while (num[i] > x)
            ++i;
        while (num[j] < x)
            --j;
        if (i <= j) {
            t = num[i];
            num[i] = num[j];
            num[j] = t;
            ++i;
            --j;
        }
    } while (i <= j);
    if (j+1 < k && k <= i)
        return num[k-1];
    if (j+1 >= k)
        return iLoveYukiNagato(num, j+1, k);
    return iLoveYukiNagato(num+i, size-i, k-i);
}
 
