/*
	Name: 蛇形矩阵 
	Copyright: 
	Author: boyce 
	Date: 13/11/15 23:51
	Description: 
*/
#include<stdio.h>
int insert(int a[99][99], int i, int j, int n, int order)/*i、j表示写数的第一个位置的行与列，n表示写数的空心方块的边长，order表示写入的第一个数的数值，
                                                          并返回 一个方块的数全部写完后待写入的下一个方块的第一个写入的数的数值 
                                                            
                                                            */ 
{
	int k;
	k = 0;
	if(n == 1) a[i][j]=order++;
	else {
	while(k <= n-2) {
		a[i + k][j] = order++;
		k++;
	}
	k = 0;
	while(k <= n-2) {
		a[i + n - 1][j - k] = order++;
		k++;
	}
	k = n - 1;
	while(k >= 1) {
		a[i + k][j - n + 1] = order++;
		k--;
	}
	k = n - 1;
	while(k >= 1) {
		a[i][j - k] = order++;
		k--;
	}
    }
    return order;
}
int main()
{
	int a[99][99];
	int n;
	int t;
	int k;
	int i, j, l;
	int order = 1;
	scanf("%d", &n);
	k = (n + 1) / 2;
	for(t = 1; t <= k; t++) {
		i = 0 + t - 1;
		j = n - t;
		l = n - (t - 1)*2;
		order = insert(a, i, j, l, order);
	}
	for(i = 0; i <= n - 1; i++) {
		for(j = 0; j <= n - 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("%d",a[i][n-1]);
		if(i <= n - 2) printf("\n");
	}
	return 0;
}

