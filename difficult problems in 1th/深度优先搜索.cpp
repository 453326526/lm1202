#include<stdio.h>
int a[51][51],book[51][51];  //  book����Ƿ��߹���a�����ǵ�ͼ 
int p, q, m, n;//  p, q�Ǳ������Ա��λ�� 
int min= 9999;//   ��־�������� 
	int dfs(int x, int y, int step) {
	int next[4][2] = {(0, 1), (0, -1), (1, 0), (-1, 0)};//  �ĸ�����
	int tx, ty, k;// tx��ty��Ŀǰ��λ��
	if(x== p&&y== q) {
		if(step< min)
			min= step;
		return;
	}
	for(k= 0; k< 4; k++) {
		tx= x+ next[k][0];  // 0�Ǻ����꣬1�������� 
		ty= y+ next[k][1]; 
		if(tx< 1|| tx> n|| ty< 1|| ty> m)
			continue;//  Խ�磬��ִ��������� 
		if(a[tx][ty]== 0&&book[tx][ty]== 0) // �õ������û���߹�
		{
			book[tx][ty]= 1;
			dfs(tx, ty, step+ 1);
			book[tx][ty]= 0;
		}
	}
	return 0;
}
