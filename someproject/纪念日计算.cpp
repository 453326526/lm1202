#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
bool runnian(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    return false;
}
void fun1() {
    const int time[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int begin[3]= {2014, 05 , 06};
    int end[3];
    int num;
    int allday= 0;
    int count= 0;
        cout<< "罗淼大领导和苏梦溪秘书开始的那一天"<< endl;
        for (int i= 0; i< 3; i++)
            cout<< begin[i]<< " ";
        cout<<endl; 
        cout<< "请输入现在日期: 格式XXXX XX XX"<< endl; 
        for (int i= 0; i< 3; i++)
            cin>> end[i];
        if (begin[0]== end[0]) {
            if (runnian(begin[0])) {
                count++;
            }
            for (int i= begin[1]+ 1; i< end[1]; i++) {
                allday+= time[i];
            }
            if (end[1]> begin[1]) {
                allday= allday+ time[begin[1]]- begin[2];
                allday+= end[2];
            } else {
                allday= end[2]- begin[2];
            }
            if (begin[1]<= 2&& end[1]>= 3)
                allday+= count; 
        } else {
            for (int k= begin[0]+ 1; k< end[0]; k++)
                if (runnian(k)) {
                    count++;
                }
            for (int i= begin[0]+ 1; i< end[0]; i++) {
                allday+= 365;
            }
            for (int i= begin[1]+ 1; i<= 12; i++) {
                allday+= time[i];
            }
            allday= allday+ time[begin[1]]- begin[2];
            for (int i= 0; i< end[1]; i++) {
                allday+= time[i];
            }
            allday+= end[2];
            allday+= count;
            if (runnian(begin[0])&& begin[1]<= 2)
                allday++;
            if (runnian(end[0])&& end[1]>= 3)
                allday++;            
        }
        cout<< "罗淼大领导已经调戏苏梦溪小秘书"<< allday<< "天啦"<< endl;
}
void fun2() {
    const int time[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int begin[3]= {2014, 05 , 06};
    int end[3];
    int num;
    int allday= 0;
    int allyear= 0;
    int allmonth= 0;
    int count= 0;
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
}
int main() {
    int n;
    cout<< "欢迎进入罗淼大领导调戏苏梦溪臭豆腐计算器！\n\n"<< endl;
        cout<< "输入1计算罗淼大领导调戏罗家臭豆腐已经多少天啦\n";
        cout<< "输入2计算罗淼大领导调戏罗家臭豆腐多少天后的日期\n"<< endl; 
        int num;
        cin>> num;
        if (num== 1)
            fun1();
        else
            fun2();
    return 0;
} 
