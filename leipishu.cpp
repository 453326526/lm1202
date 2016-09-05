#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int a[10][10];
    int num;
    int flag= 1;
    cin>> num;
    for (int i= 0; i< num; i++)
        for (int j= 0; j< num; j++)
            cin>> a[i][j];
    int sum= 0;
    for (int i= 0; i< num; i++)
        sum+= a[0][i];
    int tot= 0;
    for (int p= 0; p< num; p++) {
        for (int t= 0; t< num; t++) {
            tot+= a[p][t];
        }
        if (tot== sum) {
            tot= 0;
            continue;
        } else {
            flag= 0;
        }
    }
    tot= 0;
    for (int i= 0; i< num; i++) {
        tot+= a[i][i];
    }
    if (tot!= sum)
        flag= 0;
    else
        tot= 0;
    for (int i= 0; i< num; i++) {
        tot+= a[num- i- 1][num- i- 1];
    }
    if (tot!= sum)
        flag= 0;
    else
        tot= 0;
   
    if (flag)
        cout<< "Yes"<< endl;
    else
        cout<< "No"<< endl;
}
