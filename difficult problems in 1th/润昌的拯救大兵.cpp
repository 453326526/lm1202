#include<stdio.h>
#include <string.h>
int T[11], C[11];
int a[11][11];
// int b[11];
int m;
int sum= 0;
int flag= 0;
int f[20] = {0};
	void next(int x, int time, int tot) {
		int i, j;
		if (tot == m) {
			sum++;
			return;
		}
		for (i = 0; i <= m; i++) { 
			if (f[i] == 0 && a[x][i] != 0 && time - a[x][i] - T[i] > 0) {
				f[i] = 1;
				next(i, time - a[x][i] - T[i] + C[i], tot + 1);
				f[i] = 0;//标记有没有走过 
			}
		}
		
	int main() {
		int i, j, p, time;
		scanf("%d%d", &time, &m);
		for(i= 1; i<= m; i++)
			scanf("%d", &T[i]);
		for(i= 1; i<= m; i++)
			scanf("%d", &C[i]);
		for(i= 0; i<= m; i++) {
			for(j= 0; j<= m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		sum = 0;
		memset(f, 0, sizeof f);
		f[0] = 1;
		next(0, time, 0);
		printf("%d\n", sum);
return 0;
}

