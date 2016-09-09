#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
bool runnian(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    return false;
}
int main() {
    const int time[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int begin[3]= {2014, 05 , 06};
    int end[3];
    int num;
    int allday= 0;
    int allyear= 0;
    int allmonth= 0;
    int count= 0;
    cout<< "输入1进入程序\n输入0退出程序"<< endl;
    cin>> num;
    while (num) {
        cout<< "罗淼大领导和苏梦溪秘书开始的那一天"<< endl;
        for (int i= 0; i< 3; i++)
            cout<< begin[i]<< " ";
        cout<<endl;
        cout<< "你想知道哪个纪念日后的时间"<< endl;
        int day;
        cin>> day;
        int temp= begin[0]+ 1; 
        int temp1= begin[1];
        int temp2= begin[2];
        int t= day;
        while (day>= 365) {
            if (runnian(temp)) {
                allyear+= 1;
                day-= 366;
            } else {
                allyear+= 1;
                day-= 365;
            }
            temp++;
        }
        while (day--) {
            if (temp2+ 1<= time[begin[1]]) {
                allday++;
                temp2++;
            } else {
                temp1++;
                if (temp1> 12) {
                    allyear++;
                    temp1= 1;
                }
                allday= 1;
                temp2= 1;
            }
        }
        cout<< "罗淼大领导调戏苏梦溪小秘书"<< t<< "天是 ";  
        cout<< begin[0]+ allyear<< "年 "<< temp1<< "月 "<< temp2<< "日"<< endl; 
        cout<< "输入1进入程序\n输入0退出程序"<< endl; 
        cin>> num;
    }
    cout<< "欢迎再次使用纪念日计算器"<< endl; 
    return 0;
} 
