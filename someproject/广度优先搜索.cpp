#include<iostream>
#include<cstdio>
using namespace std;
struct note {
    int x, y;
    int father;
    int step;
};
int main () {
    struct note queue[500];
    char a[21][21]= {0};
    int book[21][21]= {0};
    int next[4][2]= {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m, x1, y1, x2, y2, head, tail;
    for (int i= 0; i< 21; i++) {
        for (int j= 0; j< 21; j++) {
            a[i][j]= '#';
            book[i][j]= 0;
        }
    }
    cin>> n>> m;
    for (int i= 0; i< n; i++) {
        for (int j= 0; j< m; j++)
            cin>> a[i][j];
    }
    for (int i= 0; i< n; i++) {
        for (int j= 0; j< m; j++) {
            if (a[i][j]== 'S') {
                x1= i;
                y1= j;
            }
            if (a[i][j]== 'E') {
                x2= i;
                y2= j;
                a[i][j]= '.';
            }
        }
    }
    head= 1;
    tail= 1;
    queue[tail].x= x1;
    queue[tail].y= y1;
    queue[tail].father= 0;
    queue[tail].step= 0;
    tail++;
    book[x1][y1]= 1;
    int flag= 0;
    while (head< tail) {
        int tx, ty;
        for (int k= 0; k< 4; k++) {
            tx= queue[head].x+ next[k][0];
            ty= queue[head].y+ next[k][1];
            if (tx< 1|| tx>= n|| ty< 1|| ty>= m)
                continue;
             if ((a[tx][ty]==  '.'&& book[tx][ty]== 0)) {
                book[tx][ty]= 1;
                queue[tail].x= tx;
                queue[tail].y= ty;
                // queue[tail].father= head;
                queue[tail].step= queue[head].step+ 1;
                tail++;
             }
             if (tx== x2&& ty== y2) {
                 flag= 1;
                 break;
             }
        }
        if (flag== 1)
            break;
        head++;
    }
    if (queue[tail- 1].step> 0&& flag== 1)
        cout<< queue[tail- 1].step<< endl;
    else
        cout<< "-1"<< endl;
    return 0;
}
