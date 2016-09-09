#include <iostream>  
#include <string.h>  
using namespace std;  
#define MAX 100  
  
class CDate  // ����������  
{  
private:  
    unsigned short int year;   // ��  
    unsigned short int month;  // ��  
    unsigned short int day;    // ��  
public:  
    CDate(int y=0,int m=0,int d=0);  
    bool operator < (CDate d);  
    friend istream & operator >> (istream &in,CDate &d);  
    friend ostream & operator<<(ostream &out,CDate &d);  
    friend bool CheckValid(CDate d);  
    friend bool LeapYear(int year);  
    void SetDate(int y,int m,int d);  
};  
CDate::CDate(int y,int m,int d):year(y),month(m),day(d) {}  
// ��������  
void CDate::SetDate(int y,int m,int d)  
{  
    year=y;  
    month=m;  
    day=d;  
}  
// �������������>>  
istream &operator>>(istream &in,CDate &d)  
{  
    char ch1,ch2;  
    cout<<"����������(�����ʽ��YYYY-MM-DD)��";  
    while(1)  
    {  
        cin>>d.year>>ch1>>d.month>>ch2>>d.day;  
        if (ch1=='-' && ch2=='-')  
            if (CheckValid(d)) break;  
        cerr<<"ʱ���ʽ��ȡֵ����ȷ! ����������\n";  
    }  
    return cin;  
}  
// ������������<<  
ostream &operator<<(ostream &out,CDate &d)  
{  
    out<<d.year<<"��"<<d.month<<"��"<<d.day<<"��";  
    return out;  
}  
// �ж�����d1<d2  
bool CDate::operator < (CDate d)  
{  
    if (year<d.year) return true;  
    if (year>d.year) return false;  
    if (month<d.month) return true;  
    if (month>d.month) return false;  
    if (day<d.day) return true;  
    return false;  
}  
  
// ����Ƿ�Ϊ����  
bool LeapYear(int year)  
{  
    if (year%4==0 && year%100 || year%400==0)  
        return true;  
    return false;  
}  
  
// ������ںϷ���  
bool CheckValid(CDate d)  
{  
    int n;  
    if (d.month<1 || d.month>12) return false;  
    if (d.day<1) return false;  
    n=31;  
    switch(d.month)  
    {  
    case 2:  
        if (LeapYear(d.year))  
            n=29;  
        else  
            n=28;  
        break;  
    case 4:  
    case 6:  
    case 9:  
    case 11:  
        n=30;  
        break;  
    }  
    if (d.day>n) return false;  
    return true;  
}  
  
class CStudent  
{  
private:  
    char *name;              // ����  
    bool sex;                // �Ա�  
    CDate date;              // �������ڣ�����������ݳ�Ա  
public:  
    static int num;          // ѧ������  
    CStudent();  
    void InputData();  
    friend void Sort();      // ����  
    friend void FindName();  // ��������ѯ  
    friend void Statistic(); // ���Ա�ͳ��  
    friend void Display();   // ��ʾȫ����Ϣ  
} stu[MAX];  
int CStudent::num=0;  
CStudent::CStudent() {}  
// ������Ϣ  
void CStudent::InputData()  
{  
    int p;  
    char s[41];  
    cout<<"������ѧ����Ϣ��NO."<<num<<"����\n";  
    cout<<"������";  
    cin>>s;  
    name=new char[strlen(s)+1];  
    strcpy(name,s);  
    cout<<"�Ա�(1-�У�0-Ů)��";  
    cin>>p;  
    if (p)  sex=true;  
    else sex=false;  
    cin>>date;  
    cout<<endl;  
}  
// ����  
void Sort()  
{  
    int i,j,p,num;  
    char *tn;  
    bool ts;  
    CDate td;  
    num=CStudent::num;  
    for(i=1; i<num; i++)  
    {  
        p=i;  
        for(j=i+1; j<=num; j++)  
            if (stu[j].date<stu[p].date) p=j;//�ҵ���ǰδ����Ԫ����������С�Ķ�����±�  
        if (p==i) continue;  
        //���潻��stu[i]��stu[p]  
        tn=stu[i].name;  
        stu[i].name=stu[p].name;  
        stu[p].name=tn;  
        ts=stu[i].sex;  
        stu[i].sex=stu[p].sex;  
        stu[p].sex=ts;  
        td=stu[i].date;  
        stu[i].date=stu[p].date;  
        stu[p].date=td;  
    }  
}  
// ��������ѯ  
void FindName()  
{  
    char name[41];  
    int i,num;  
    cout<<"������������";  
    cin>>name;  
    num=CStudent::num;  
    for(i=1; i<=num; i++)  
        if (strcmp(stu[i].name,name)==0) break;  
    if (i>num)  
    {  
        cout<<"���޴���!"<<endl<<endl;  
        return;  
    }  
    //����鵽�ˣ���ʾѧ����Ϣ  
    cout<<"������"<<stu[i].name<<endl;  
    cout<<"�Ա�";  
    if (stu[i].sex)  
        cout<<"��"<<endl;  
    else  
    cout<<"Ů"<<endl;  
    cout<<"���գ�"<<stu[i].date<<endl;  
    cout<<endl;  
}  
// ���Ա�ͳ��  
void Statistic()  
{  
    int i,num,s1,s0;  
    num=CStudent::num;  
    s1=0;  
    s0=0;  
    for(i=1; i<=num; i++)  
        if (stu[i].sex==1)  
            s1++;  
        else  
            s0++;  
    cout<<"����������"<<s1<<endl;  
    cout<<"Ů��������"<<s0<<endl;  
    cout<<endl;  
}  
  
// ��ʾȫ����Ϣ  
void Display()  
{  
    int i,num;  
    num=CStudent::num;  
    for(i=1; i<=num; i++)  
    {  
        cout<<stu[i].name<<"\t";  
        if (stu[i].sex)  
            cout<<"��";  
        else  
            cout<<"Ů";  
        cout<<"\t"<<stu[i].date<<endl;  
    }  
    cout<<endl;  
}  
  
int main()  
{  
    string menu[]= { "","������Ϣ","����","��������ѯ","���Ա�ͳ��","��ʾȫ����Ϣ","�˳�" };  
    int i,p;  
    bool end;  
    end=false;  
    while(!end)  
    {  
        for(i=1; i<7; i++)  
            cout<<i<<"  "<<menu[i]<<endl;  
        cin>>p;  
        switch(p)  
        {  
        case 1:                          // ������Ϣ  
            CStudent::num++;  
            stu[CStudent::num].InputData();  
            break;  
        case 2:                          // ����  
            Sort();  
            break;  
        case 3:                          // ��������ѯ  
            FindName();  
            break;  
        case 4:                          // ���Ա�ͳ������  
            Statistic();  
            break;  
        case 5:                          // ��ʾȫ����Ϣ  
            Display();  
            break;  
        case 6:                          // �˳�  
            end=true;  
            break;  
        }  
    }  
    return 0;  
}  
