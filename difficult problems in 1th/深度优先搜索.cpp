#include<stdio.h>
int a[51][51],book[51][51];  //  book标记是否走过，a数组是地图 
int p, q, m, n;//  p, q是被解救人员的位置 
int min= 9999;//   标志步数而用 
	int dfs(int x, int y, int step) {
	int next[4][2] = {(0, 1), (0, -1), (1, 0), (-1, 0)};//  四个方向
	int tx, ty, k;// tx，ty是目前的位置
	if(x== p&&y== q) {
		if(step< min)
			min= step;
		return;
	}
	for(k= 0; k< 4; k++) {
		tx= x+ next[k][0];  // 0是横坐标，1是纵坐标 
		ty= y+ next[k][1]; 
		if(tx< 1|| tx> n|| ty< 1|| ty> m)
			continue;//  越界，不执行下面语句 
		if(a[tx][ty]== 0&&book[tx][ty]== 0) // 该点可走且没有走过
		{
			book[tx][ty]= 1;
			dfs(tx, ty, step+ 1);
			book[tx][ty]= 0;
		}
	}
	return 0;
}
