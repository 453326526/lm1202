#include <stdio.h>
 
#define MAXn (10+1)
#define MAXt (1000+1)
 
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
 
typedef struct {
    int s, w, t, d;
} Course;
 
int main() {
    int n, i, j, m;
    Course c[MAXn];
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d%d%d%d", &c[i].s, &c[i].w, &c[i].t, &c[i].d);
 
    for (i = 1; i <= n && m >= 0; ++i)
        if (c[i].s < 60) {
            j = (59 - c[i].s + c[i].d) / c[i].d;
            c[i].s += c[i].d * j;
            if (c[i].s > 100)
                c[i].s = 100;
            m -= j * c[i].t;
        }
 
    if (m < 0) {
        printf("0\n");
    } else {
        int w = 0;
        for (i = 1; i <= n; ++i)
            w += c[i].w;
        double f[2][MAXt + 1] = { { 0 } };
        for (i = 1; i <= n; ++i)
            f[0][0] += c[i].w * (c[i].s-50);
        f[1][0] = f[0][0];
        for (j = 1; j <= m; ++j)
            f[0][j] = f[0][0];
 
        int k, tem;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j) {
                f[i & 1][j] = f[(i & 1) ^ 1][j];
                tem = c[i].d;
                for (k = c[i].t;
                     k<= j && tem + c[i].s < 100;
                     k += c[i].t, tem += c[i].d)
                    f[i & 1][j] = MAX(
                        f[i & 1][j],
                        f[(i & 1) ^ 1][j - k] + c[i].w * tem);
                if (k <= j)
                    f[i & 1][j] = MAX(
                        f[i & 1][j],
                        f[(i & 1) ^ 1][j - k] + c[i].w * (100 - c[i].s));
            }
        printf("%.2lf\n", f[n & 1][m]/(w * 10.0));
    }
    return 0;
}
