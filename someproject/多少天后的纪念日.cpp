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
    cout<< "����1�������\n����0�˳�����"<< endl;
    cin>> num;
    while (num) {
        cout<< "�����쵼������Ϫ���鿪ʼ����һ��"<< endl;
        for (int i= 0; i< 3; i++)
            cout<< begin[i]<< " ";
        cout<<endl;
        cout<< "����֪���ĸ������պ��ʱ��"<< endl;
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
        cout<< "�����쵼��Ϸ����ϪС����"<< t<< "���� ";  
        cout<< begin[0]+ allyear<< "�� "<< temp1<< "�� "<< temp2<< "��"<< endl; 
        cout<< "����1�������\n����0�˳�����"<< endl; 
        cin>> num;
    }
    cout<< "��ӭ�ٴ�ʹ�ü����ռ�����"<< endl; 
    return 0;
} 
