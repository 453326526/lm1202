#include<iostream>  
#include<vector>  
#include<string>  
#include<fstream>  
using namespace std;  
class employee  
{  
public:  
    int id ,salary;  
    string name,tele,address,office,sex;  
    employee(int id ,string name,string sex,string tele,string address,string office,int salary)  
    {  
        this->id=id;  
        this->salary=salary;  
        this->sex=sex;  
        this->name=name;  
        this->tele=tele;  
        this->address=address;  
        this->office=office;  
    }  
};  
int main()  
{  
    void Addemployee();  
    void Delectemployee();  
    void Updaemployee();  
    void reseacherstudentbyname();  
    void reseacherstudentbyoffice();  
    void add();  
    void SaveFile();  
    while(true)  
    {  
        cout<<"========================ְ�����ʹ���ϵͳ========================="<<'\n'  
            <<"1.���ְ��"<<'\n'  
            <<"2.ɾ�� ְ��"<<'\n'  
            <<"3.�޸�ְ��"<<'\n'  
            <<"4.��������ѯְ��"<<'\n'  
            <<"5.�����Ҳ�ѯְ��"<<'\n'  
            <<"6.���Ա�ͳ��ְ��ƽ������"<<'\n'  
            <<"0.�Ƴ�ְ�����ʹ���ϵͳ"<<'\n'  
            <<"========================ְ�����ʹ���ϵͳ========================="<<'\n';  
        cout<<"���������ѡ��"<<endl;  
        int input;  
        cin>>input;  
        switch(input)  
        {  
        case 1:Addemployee(); break;  
        case 2: Delectemployee();break;  
        case 3: Updaemployee();break;  
        case 4:reseacherstudentbyname() ;break;  
        case 5:reseacherstudentbyoffice(); break;  
        case 6: add();break;  
        case 0:exit(1);break;  
        }  
    }  
    return 0;  
}  
vector<employee>stu;  
  
void SaveFile()  
{  
    fstream file;  
    file.open("d:\\stuData.txt",ios::out);  
    vector<employee>::iterator itr=stu.begin();  
    while(itr!=stu.end())  
    {  
        file<<(*itr).id<<"\n";  
        file<<(*itr).name<<"\n";  
        file<<(*itr).sex<<"\n";  
        file<<(*itr).tele<<"\n";  
        file<<(*itr).address<<"\n";  
        file<<(*itr).office<<"\n";  
        file<<(*itr).salary<<"\n";  
        itr++;  
    }  
    file.close();  
}  
void Addemployee()  
{   
    int id,salary;  
    string name,tele,address,office,sex;  
    cout<<"������ְ�����\n";  
    cin>>id;  
    cout<<"������ְ������\n";  
    cin>>name;  
    cout<<"������ְ���Ա�\n";  
    cin>>sex;  
    cout<<"������ְ���绰����\n";  
    cin>>tele;  
    cout<<"������ְ����ַ\n";  
    cin>>address;  
    cout<<"������ְ������\n";  
    cin>>office; cout<<"������ְ��нˮ\n";  
    cin>>salary;  
    employee T(id,name,sex,tele,address,office,salary );  
    stu.push_back(T);  
    cout<<"���ѳɹ����ְ��������"<<stu.size()<<"��ְ��"<<endl;  
    SaveFile();  
}  
void Delectemployee()  
{  
    cout<<"������Ҫɾ����ְ����\n";  
    int id;  
    cin>>id;  
    vector<employee>::iterator p=stu.begin();  
    while(p!=stu.end())  
    {  
        if((*p).id==id)  
        {  
            stu.erase (p);  
            break;  
        }  
        p++;  
    }  
    cout<<"���ѳɹ�ɾ��ְ��"<<endl;  
    SaveFile();  
}  
void Updaemployee()  
{  
    int id ,salary;  
    string name,tele,address,office,sex;  
    cout<<"������Ҫ�޸ĵ�ְ����\n";  
    cin>>id;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).id=id)  
        {  
              
            cout<<"�������޸�ְ��������\n";  
            cin>>name;  
            cout<<"�������޸�ְ�����Ա�\n";  
            cin>>sex;  
            cout<<"�������޸�ְ���ĵ绰����\n";  
            cin>>tele;  
            cout<<"�������޸�ְ���ĵ�ַ\n";  
            cin>>address;  
            cout<<"�������޸�ְ���� ����\n";  
            cin>>office;  
            cout<<"�������޸�ְ����нˮ\n";  
            cin>>salary;  
            (*p).id=id;  
            (*p).name=name;  
            (*p).sex=sex;  
            (*p).tele=tele;  
            (*p).address=address;  
            (*p).office=office;  
            (*p).salary=salary;  
  
            break;  
        }  
        p++;  
    }  
    cout<<"�����޸ĳɹ�"<<endl;  
    SaveFile();  
}  
void reseacherstudentbyname()  
{  
    cout<<"��������Ҫ��ѯ���˵�����\n";  
    string name;  
    cin>>name;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).name==name)  
        {  
            cout<<"ְ���ı�ţ�\n"<<(*p).id<<endl;  
            cout<<"ְ����������\n"<<(*p).name<<endl;  
            cout<<"ְ�����Ա�\n"<<(*p).sex<<endl;  
            cout<<"ְ���ĵ绰���룺\n"<<(*p).tele<<endl;  
            cout<<"ְ���ĵ�ַ��\n"<<(*p).address<<endl;  
            cout<<"ְ���Ŀ��ң�\n"<<(*p).office<<endl;  
            cout<<"ְ����нˮ��\n"<<(*p).salary<<endl;  
  
            break;  
        }  
        p++;  
    }  
    SaveFile();  
}  
void reseacherstudentbyoffice()  
{  
    cout<<"��������Ҫ��ѯ���˵Ŀ���\n";  
    string office;  
    cin>>office;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).office==office)  
        {  
            cout<<"ְ���ı�ţ�\n"<<(*p).id<<endl;  
            cout<<"ְ����������\n"<<(*p).name<<endl;  
            cout<<"ְ�����Ա�\n"<<(*p).sex<<endl;  
            cout<<"ְ���ĵ绰���룺\n"<<(*p).tele<<endl;  
            cout<<"ְ���ĵ�ַ��\n"<<(*p).address<<endl;  
            cout<<"ְ���Ŀ��ң�\n"<<(*p).office<<endl;  
            cout<<"ְ����нˮ��\n"<<(*p).salary<<endl;  
        }  
        p++;  
    }  
      
}  
void add()  
{  
    int s=0,l=0,sum1=0,sum2=0;  
    vector<employee>::iterator  p=stu.begin();  
    while(p!=stu.end())  
    {  
        if((*p).sex=="man" ){s++;sum1=sum1+(*p).salary;}  
        else if((*p).sex=="woman" ){l++;sum2=sum2+(*p).salary;}  
        p++;  
          
    }  
    if(s==0)cout<<"��ְ����ƽ��нˮ��"<<"0"<<endl;  
    else cout<<"��ְ����ƽ��нˮ��"<<double(sum1)/s<<endl;  
    if(l==0)cout<<"Ůְ����ƽ��нˮ��"<<"0"<<endl;  
    else cout<<"Ůְ����ƽ��нˮ��"<<double(sum2)/l<<endl;  
}  


