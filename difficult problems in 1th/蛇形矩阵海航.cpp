/*
	Name: ���ξ��� 
	Copyright: 
	Author: boyce 
	Date: 13/11/15 23:51
	Description: 
*/
#include<stdio.h>
int insert(int a[99][99], int i, int j, int n, int order)/*i��j��ʾд���ĵ�һ��λ�õ������У�n��ʾд���Ŀ��ķ���ı߳���order��ʾд��ĵ�һ��������ֵ��
                                                          ������ һ���������ȫ��д����д�����һ������ĵ�һ��д���������ֵ 
                                                            
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

