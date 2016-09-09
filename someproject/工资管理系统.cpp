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
        cout<<"========================职工工资管理系统========================="<<'\n'  
            <<"1.添加职工"<<'\n'  
            <<"2.删除 职工"<<'\n'  
            <<"3.修改职工"<<'\n'  
            <<"4.按姓名查询职工"<<'\n'  
            <<"5.按科室查询职工"<<'\n'  
            <<"6.按性别统计职工平均工资"<<'\n'  
            <<"0.推出职工工资管理系统"<<'\n'  
            <<"========================职工工资管理系统========================="<<'\n';  
        cout<<"请输入你的选择："<<endl;  
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
    cout<<"请输入职工编号\n";  
    cin>>id;  
    cout<<"请输入职工名字\n";  
    cin>>name;  
    cout<<"请输入职工性别\n";  
    cin>>sex;  
    cout<<"请输入职工电话号码\n";  
    cin>>tele;  
    cout<<"请输入职工地址\n";  
    cin>>address;  
    cout<<"请输入职工科室\n";  
    cin>>office; cout<<"请输入职工薪水\n";  
    cin>>salary;  
    employee T(id,name,sex,tele,address,office,salary );  
    stu.push_back(T);  
    cout<<"你已成功添加职工，现有"<<stu.size()<<"个职工"<<endl;  
    SaveFile();  
}  
void Delectemployee()  
{  
    cout<<"请输入要删除的职工号\n";  
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
    cout<<"你已成功删除职工"<<endl;  
    SaveFile();  
}  
void Updaemployee()  
{  
    int id ,salary;  
    string name,tele,address,office,sex;  
    cout<<"输入你要修改的职工号\n";  
    cin>>id;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).id=id)  
        {  
              
            cout<<"请输入修改职工的姓名\n";  
            cin>>name;  
            cout<<"请输入修改职工的性别\n";  
            cin>>sex;  
            cout<<"请输入修改职工的电话号码\n";  
            cin>>tele;  
            cout<<"请输入修改职工的地址\n";  
            cin>>address;  
            cout<<"请输入修改职工的 科室\n";  
            cin>>office;  
            cout<<"请输入修改职工的薪水\n";  
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
    cout<<"你已修改成功"<<endl;  
    SaveFile();  
}  
void reseacherstudentbyname()  
{  
    cout<<"请输入你要查询的人的名字\n";  
    string name;  
    cin>>name;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).name==name)  
        {  
            cout<<"职工的编号：\n"<<(*p).id<<endl;  
            cout<<"职工的姓名：\n"<<(*p).name<<endl;  
            cout<<"职工的性别：\n"<<(*p).sex<<endl;  
            cout<<"职工的电话号码：\n"<<(*p).tele<<endl;  
            cout<<"职工的地址：\n"<<(*p).address<<endl;  
            cout<<"职工的科室：\n"<<(*p).office<<endl;  
            cout<<"职工的薪水：\n"<<(*p).salary<<endl;  
  
            break;  
        }  
        p++;  
    }  
    SaveFile();  
}  
void reseacherstudentbyoffice()  
{  
    cout<<"请输入你要查询的人的科室\n";  
    string office;  
    cin>>office;  
    vector<employee>::iterator  p=stu.begin ();  
    while(p!=stu.end())  
    {  
        if((*p).office==office)  
        {  
            cout<<"职工的编号：\n"<<(*p).id<<endl;  
            cout<<"职工的姓名：\n"<<(*p).name<<endl;  
            cout<<"职工的性别：\n"<<(*p).sex<<endl;  
            cout<<"职工的电话号码：\n"<<(*p).tele<<endl;  
            cout<<"职工的地址：\n"<<(*p).address<<endl;  
            cout<<"职工的科室：\n"<<(*p).office<<endl;  
            cout<<"职工的薪水：\n"<<(*p).salary<<endl;  
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
    if(s==0)cout<<"男职工的平均薪水："<<"0"<<endl;  
    else cout<<"男职工的平均薪水："<<double(sum1)/s<<endl;  
    if(l==0)cout<<"女职工的平均薪水："<<"0"<<endl;  
    else cout<<"女职工的平均薪水："<<double(sum2)/l<<endl;  
}  


