#include <stdio.h>
 
#define MAXm 11
 
typedef struct {
    int x, i, n;
} str;
 
int main() {
    int m, i, j, t = 0, ans = 0;
    char visited[MAXm] = { 0 };
    str stack[MAXm];
    int A[MAXm][MAXm], T[MAXm], C[MAXm];
    scanf("%d%d", &stack[0].n, &m);
    for (i = 1; i <= m; ++i)
        scanf("%d", T + i);
    for (i = 1; i <= m; ++i)
        scanf("%d", C + i);
    for (i = 0; i <= m; ++i)
        for (j = 0; j <= m; ++j)
            scanf("%d", &A[i][j]);
    stack[0].x = 0;
    stack[0].i = 0;
    while (t >= 0) {
        if (t == m) {
            ++ans;
            visited[stack[t].x] = 0;
            --t;
        } else {
            while (++stack[t].i <= m)
                if (A[stack[t].x][stack[t].i] + T[stack[t].i] < stack[t].n
                    && !visited[stack[t].i]) {
                    stack[t+1].i = 0;
                    stack[t+1].x = stack[t].i;
                    stack[t+1].n = stack[t].n - A[stack[t].x][stack[t].i]
                        - T[stack[t].i] + C[stack[t].i];
                    visited[stack[t++].i] = 1;
                    break;
                }
            if (stack[t].i > m)
                visited[stack[t--].x] = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}


