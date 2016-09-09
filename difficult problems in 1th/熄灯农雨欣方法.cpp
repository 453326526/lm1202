#include<stdio.h>
int main() {
int N, t, p, i = 0, j = 0;
int a[50];
	for (i = 0; i < 50; i++)
		a[i] = 1;
	i = 0;
	scanf("%d%d%d", &N, &t, &p);
	while (1) {
		if (a[t] == 1)
			a[t] = 0;
			printf("%d ", t);
			j++;
		if (j >= N)
			break;
		while (1) {
			if (t >= N - 1)
				t -= N;
			t++;
			if (a[t] == 1 && i < p)
				i++;
			if (i == p)
				break;
		}
		i = 0;
		}
printf("\n");
return 0;
}
