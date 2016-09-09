#ifndef __DFSFORTREE__
#define __DFSFORTREE__
#include<stdio.h>
#include<stdlib.h>
int flag = 0;
void DFS(int arr[], int leng, int pos, int theOne) {
    if (flag == 0) {
        if (pos < leng && arr[pos] != theOne) {
            printf("%d ", arr[pos]);
            DFS(arr, leng, (pos + 1) * 2 - 1, theOne);
            DFS(arr, leng, (pos + 1) * 2, theOne);
        } else if (pos < leng && arr[pos] == theOne) {
            printf("%d\n", theOne);
            flag = 1;
        }
    }
}
#endif
