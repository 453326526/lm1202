#include<stdio.h>
int stop= 0;
int DFS(int arr[], int N, int pos, int X) {
int t, p;
printf("%d ", arr[pos]);
if(arr[pos]== X) {
stop= 1;
printf("\n");
return 0;
}
t= 2* pos+ 1;
p= 2* pos+ 2;
if (t< N&& stop== 0)
DFS(arr, N, t, X);
if (p< N&& stop== 0)
DFS(arr, N, p, X);
}


int main() {
    int leng = 0;
    int arr[MAX] = {0};
    int i;
    int X = 0;
    scanf("%d", &leng);
    for (i = 0; i < leng; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &X);
    DFS(arr, leng, 0, X);
    return 0;
}
