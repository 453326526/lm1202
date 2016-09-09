#include<stdio.h>
int main() {
int num, x, y, i, t, m;  //t是一个变量去熄灯
int p= 1;
int temp= 0;
int begin;
int a[100];
int flag; 
for(i= 0; i< 100; i++)
a[i]= 1;  //  1表示这个灯亮着 
scanf("%d", &num);
flag= num;
scanf("%d%d", &x, &y);
t= x;
while(flag> 0) {
t%= num;
if(a[t]== 1) {
printf("%d ", t);
a[t]= 0;
flag--;
}
if(flag== 0)
break;
while(1) {
m= t+ p;
m%= num;
if(a[m]== 1)
temp++;
p++;
if(temp== y) {
t+= p- 1;
p= 1;
temp= 0;
break;
}
}
}
printf("\n");
return 0;
}


