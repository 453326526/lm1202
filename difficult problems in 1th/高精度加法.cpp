#include <stdlib.h>
 
short *plus(short *a, short *b) {
    int la, lb, n, i;
    for (la = 0; a[la] >= 0; ++la)
        continue;
    for (lb = 0; b[lb] >= 0; ++lb)
        continue;
    if (la < lb)
        n = lb;
    else
        n = la;
    short *ans = (short*)malloc(sizeof(a[0])*(n+2));
    for (i = 0; i < n; ++i)
        if (i < la && i < lb)
            ans[i] = a[la-i-1]+b[lb-i-1];
        else if (i < la)
            ans[i] = a[la-i-1];
        else
            ans[i] = b[lb-i-1];
    for (i = 0; i < n-1; ++i)
        if (ans[i] > 9) {
            ++ans[i+1];
            ans[i] -= 10;
        }
    if (ans[n-1] > 9) {
        ans[n] = 1;
        ans[n-1] -= 10;
        ans[n+1] = -1;
    } else {
        ans[n] = -1;
        --n;
    }
    for (i = n/2; i >= 0; --i) {
        la = ans[i];
        ans[i] = ans[n-i];
        ans[n-i] = la;
    }
    return ans;
}
