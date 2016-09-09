#include<iostream>
#include<conio.h> //����̨������������ĺ���
#include<fstream>//�ļ���
#include<iomanip>
#include<string.h>
using namespace std; 
const int Maxr=100 ;//���Ķ����� 
const int Maxb=100; //����ͼ����
const int Maxbor=5; //ÿλ�����������
 
 
 
class Book 
{//ͼ���࣬ʵ�ֶ�ͼ���������ͼ��ı�ţ����������������ȹ���
private: 
int tag; //ɾ����� 1:��ɾ 0:δɾ
int no; //ͼ����
char name[20]; //����     
char author[20];//����
char fenlei[20];//�����
char cbs[20]; //������
int cbtime;//����ʱ��
double bookprice;//ͼ��۸�
int onshelf; //�Ƿ��ټ� 1:�ټ� 2:�ѽ� 
public: 
Book(){;} 
char *getname()
{//��ȡ����
  return name; 
} 
char *getauthorname() 
{//��ȡ������
  return author;
} 
 
char *getfenlei()
{//��ȡ�����
 return fenlei;
}
char *getcbsname()
{//��ȡ�������� 
  return cbs; 
} 
int getcbtime()
{//��ȡ����ʱ��
 return cbtime;
}
double getbookprice()
{//��ȡͼ��۸�
 return bookprice;
}
int getno()
{//��ȡͼ����
  return no; 
}
int gettag()
{//��ȡɾ����� 
  return tag; 
}
 
void setname(char na[]) 
{//��������
  strcpy(name,na); 
} 
void setauthorname(char aa[])
{//����������
strcpy(author,aa);
}
void setfenlei(char fe[])
{//���÷����
 strcpy(fenlei,fe);
}
void setcbs(char ca[])
{//���ó�����
 strcpy(cbs,ca);
}
 
void setcbtime(int time) 
{//����ʱ��
  cbtime=time;
} 
void setbookprice(double price)
{//����ͼ��۸�
  bookprice=price;
}
void setonshelf(int oa) 
{
  onshelf=oa;
} 
void delbook()
{//ɾ��ͼ��
 char i;
 cout<<"ȷ��ɾ����Y/N ?"<<endl;
 cin>>i;
 if(i=='y'||i=='Y')
  tag=1;
} 
void addbook(int n,char *na,char *aa,char *fe,char *ca,int time,double price,int oa) 
{//����ͼ�� 
  tag=0; 
  no=n; 
  strcpy(name,na);
  strcpy(author,aa);
  strcpy(cbs,ca);
  strcpy(fenlei,fe);
  cbtime=time;
  bookprice=price;
  onshelf=oa; 
} 
int borrowbook() 
{//������� 
  if (onshelf>0) 
  { 
  onshelf--;
  return 1; 
  } 
  return 0; 
} 
void retbook()
{//�������
  onshelf++; 
} 
void disp() 
{//���ͼ�� 
  cout<<setw(3)<<no<<setw(10)<<name<<setw(10)<<author<<setw(10)<<fenlei<<setw(15)<<cbs<<setw(10)<<cbtime<<setw(10)<<bookprice<<setw(10)<<onshelf<<endl; 
} 
}; 
 
 
class BDatabase 
{//ͼ����࣬ʵ�ֶ�ͼ���ά�������ң�ɾ���� 
private: 
int top; //ͼ���¼ָ��
Book book[Maxb]; //ͼ���¼
public: 
BDatabase() 
{//���캯������book.txt����book[]�� 
  Book b; 
  top=-1; 
  fstream file("book.txt",ios::in); 
  while (1) 
  { 
  file.read((char *)&b,sizeof(b)); 
  if (!file) 
   break; 
  top++; 
  book[top]=b; 
  } 
  file.close(); 
} 
void clear() 
{//ȫɾ 
 char i;
 cout<<"ȷ��ȫ��ɾ����Y/N ?"<<endl;
 cin>>i;
 if(i=='y'||i=='Y')
  top=-1; 
} 
int addbook(int n,char *na,char *aa,char *fe,char *ca,int time, double price,int oa) 
{//����ͼ�� 
  Book *p=query1(n); 
  if (NULL==p) 
  { 
  top++; 
  book[top].addbook(n,na,aa,fe,ca,time,price,oa); 
  return 1; 
  } 
  return 0; 
} 
Book *query1(int bookid) 
{//����Ų���ͼ�� 
  for(int i=0;i<=top;i++) 
  if(book[i].getno()==bookid &&book[i].gettag()==0) 
  { 
   return &book[i]; 
  } 
  return NULL; 
}
Book *query2(char a[]) 
{//����������ͼ��
  Book *e;
  int r=0;
  for(int i=0;i<=top;i++)
  if(strcmp(book[i].getname(),a)==0 &&book[i].gettag()==0) 
  { 
   if(r==0)
   cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
   e=&book[i];
   e->disp();
   r++; 
  } 
  if(r==0)
   cout<<"�Ҳ�������!"<<endl;
   return NULL; 
} 
Book *query3(char a[]) 
{//�����߲���ͼ�� 
  Book *e;
  int r=0;
  for(int i=0;i<=top;i++) 
  if(strcmp(book[i].getauthorname(),a)==0 &&book[i].gettag()==0) 
  { 
   if(r==0)
   cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
    e=&book[i];
   e->disp();
   r++; 
  } 
  if(r==0)
   cout<<"�Ҳ�������!"<<endl;
   return NULL; 
}
Book *query4(char a[]) 
{//�����������ͼ�� 
  Book *e;
  int r=0;
  for (int i=0;i<=top;i++)
  if (strcmp(book[i].getcbsname(),a)==0 &&book[i].gettag()==0) 
  { 
   if(r==0)cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
   e=&book[i];
   e->disp();
   r++; 
  }
  if(r==0)
   cout<<"�Ҳ�������!"<<endl;
   return NULL; 
}   
void bookdata(); //ͼ�����Ϣ
void disp() 
{ 
  for(int i=0;i<=top;i++) 
  if(book[i].gettag()==0) 
   book[i].disp(); 
} 
~BDatabase() 
{//������������book[]д��book.txt�ļ��� 
  fstream file("book.txt",ios::out); 
  for(int i=0;i<=top;i++) 
  if(book[i].gettag()==0)
   file.write((char *)&book[i],sizeof(book[i])); 
  file.close(); 
} 
}; 
void BDatabase::bookdata() 
{ 
char choice3; 
char bname[40];//����
char auname[40];//������
char bfenlei[40];//�����
char cname[40];//������
int time;//����ʱ��
double price;//�۸�
char ch;
int choice4;
int bookid;
int bookod;
Book *b; 
while (choice3!='0') 
{ 
  cout<<"\n\t\t\t**  ͼ �� �� Ϣ **\n"<<endl; 
  cout<<"\t\t\t** 1.��    �� **"<<endl;
  cout<<"\t\t\t** 2.��    �� **"<<endl;
  cout<<"\t\t\t** 3.ɾ    �� **"<<endl;
  cout<<"\t\t\t** 4.��    �� **"<<endl;
  cout<<"\t\t\t** 5.��    ʾ **"<<endl;
  cout<<"\t\t\t** 6.ȫ    ɾ **"<<endl;
  cout<<"\t\t\t** 0.��    �� **"<<endl; 
  cout<<"\t\t\t ��ѡ��";
  cin>>choice3; 
  switch(choice3) 
  { 
  case '1': 
  cout<<"������������:"; 
  cin>>bookid;
  
  b=query1(bookid); 
  if(b!=NULL) 
  { 
   cout<<"�ñ���Ѿ����ڣ��������!"<<endl;
   break; 
  }
  cout<<"��������������:"; 
  cin>>bname;
  cout<<"����������������:"; 
  cin>>auname;
 cout<<"��������������:";
 cin>>bfenlei;
  cout<<"���������������:"; 
  cin>>cname;
 cout<<"�������������ʱ��:";
 cin>>time;
 cout<<"������ͼ��۸�:";
 cin>>price;
 
  cout<<"��������������:"; 
  cin>>bookod;
 addbook(bookid,bname,auname,bfenlei,cname,time,price,bookod);
  
 
 char choice2;
 {
 cout<<"\n\t\t\t** �� �� �� �� Y/N ?**\n"<<endl;
  cout<<"\t\t\t** 1. Y ��  �� **"<<endl;
  cout<<"\t\t\t** 0. N ��  ��  �� **"<<endl;
 cout<<"\t\t\t �� ѡ ��: ";
cin>>choice2;
switch(choice2)
{
case '1':
 
   
 cout<<"���ͼ��ɹ�!";
  
 break;
case '0':
  
 break;
}
 }
 getch(); 
  break; 
  case '2': 
  cout<<"������ͼ����:"; 
  cin>>bookid; 
  b=query1(bookid); 
  if(b==NULL) 
  { 
   cout<<"��ͼ�鲻����! "<<endl;
   break; 
  }
  cout<<"��ͼ�����Ϣ�ǣ�"<<endl;
  cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
  b->disp();
  cout<<"�Ƿ��޸�?( y/n ):";
  cin>>ch;
  if(ch=='y'||ch=='Y')
  {int a;
  cout<<"\n\t\t\t**  ͼ �� �� �� **\n"<<endl; 
  cout<<"\t\t\t** 1.�� �� �� ��   **"<<endl;
  cout<<"\t\t\t** 2.�� �� �� ��   **"<<endl;
  cout<<"\t\t\t** 3.�� �� �� �� ��  **"<<endl;
  cout<<"\t\t\t** 4.�� �� �� �� ��  **"<<endl;
  cout<<"\t\t\t** 5.�� �� �� �� ʱ ��**"<<endl;
  cout<<"\t\t\t** 6.�� �� ͼ �� �� ��**"<<endl;
  cout<<"\t\t\t** 7.�� �� ͼ �� �� ��**"<<endl;
  cout<<"\t\t\t** 0.��    �� **"<<endl; 
  cout<<"\t\t\t ��ѡ��";
  cin>>a; 
switch(a)
{
case 1: cout<<"�������µ�����:"; 
   cin>>bname; b->setname(bname); break;
case 2:  cout<<"�������µ�����:";
   cin>>auname; b->setauthorname(auname); break;
case 3: cout<<"�������µķ����:";
 cin>>bfenlei; b->setfenlei(bfenlei); break;
case 4: cout<<"���������������:";
   cin>>cname; b->setcbs(cname); break;
case 5: cout<<"�������������ʱ��:";
 cin>>time;b->setcbtime(time); break;
case 6: cout<<"������ͼ��۸�:";
 cin>>price; b->setbookprice(price); break;
case 7: cout<<"�������µĴ���:"; 
   cin>>bookod; b->setonshelf(bookod); break;
case 0: break;
 }
 }
  cout<<"�޸�ͼ��ɹ�!";
  getch(); 
   break;
  case '3':  
  cout<<"������ͼ����:"; 
  cin>>bookid; 
  b=query1(bookid); 
  if(b==NULL) 
  { 
   cout<<"��ͼ�鲻���ڣ��޷�ɾ��!"<<endl;
   break; 
  } 
  b->delbook();
  cout<<"ɾ���ɹ�!";
  getch();
  break; 
  case '4':  
  cout<<"\n\t\t\t** 1.��ͼ���Ų��� **"<<endl;
  cout<<"\t\t\t** 2.��ͼ���������� **"<<endl;
  cout<<"\t\t\t** 3.��ͼ�����߲��� **"<<endl;
  cout<<"\t\t\t** 4.��ͼ����������**"<<endl;
  cout<<"\t\t\t** 0. ��   ��  **"<<endl;
  cout<<"\t\t\t ��ѡ��:"; 
  cin>>choice4;
  switch(choice4)
  {
  case 1: 
   cout<<"������ͼ����:"; 
   cin>>bookid;
   b=query1(bookid);
   if(b==NULL) 
   { 
   cout<<"��ͼ�鲻����!";
   break; 
   }
   cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
   b->disp(); 
   break;   
  case 2: 
   cout<<"������ͼ������:"; 
   cin>>bname;
   b=query2(bname);
   break;
  case 3: 
   cout<<"������ͼ������:"; 
   cin>>auname;
   b=query3(auname);
   break;
  case 4: 
   cout<<"������ͼ�������:"; 
   cin>>cname;
   b=query4(cname);
   break;
  case 0: 
   break;
  }
       break;
  case '5': 
   cout<<setw(3)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(15)<<"������"<<setw(10)<<"����ʱ��"<<setw(10)<<"ͼ��۸�"<<setw(10)<<"����"<<endl;
   disp();
   getch(); 
   break; 
  case '6': 
   clear(); 
   break; 
  default: 
   break; 
  } 
} 
}
 
 
class Reader
{//���ߵ���Ϣ���� 
private: 
int tag; //ɾ����� 1��ʾ��ɾ 0��ʾδɾ 
int no; //���߱��
char name[20]; //�������� 
int borbook[Maxbor]; //����ͼ�� 
public: 
Reader() //���캯��
{ ; } 
friend ostream &operator<<(ostream &output,Reader &rd)
{output<<rd.no;
output<<"  ";
output<<endl;
return output;}
char *getname() 
{//��ȡ���� 
  return name;
 
} 
int gettag() 
{//��ȡɾ����� 
  return tag; 
} 
int getno() 
{//��ȡ���߱�� 
  return no; 
} 
void setname(char na[]) 
{//�������� 
  strcpy(name,na); 
}
void delbook() 
{//����ɾ����� 1:��ɾ 0:δɾ 
 char i;
 cout<<"ȷ��ɾ����Y/N ?"<<endl;
 cin>>i;
 if(i=='y'||i=='Y')
  tag=1; 
}  
void addreader(int n,char *na) 
{//���Ӷ��� 
  tag=0; 
  no=n; 
  strcpy(name,na); 
  for(int i=0;i<Maxbor;i++) 
  borbook[i]=0; 
} 
void borrowbook(int bookid) 
{//������� 
  for(int i=0;i<Maxbor;i++) 
  { 
  if (borbook[i]==0) 
  {
   borbook[i]=bookid;
   return ; 
  } 
  } 
} 
int retbook(int bookid) 
{//������� 
  for(int i=0;i<Maxbor;i++) 
  { 
      if(borbook[i]==bookid) 
  { 
        borbook[i]=0;
        cout<<"����ɹ�!"<<endl;
   return 1; 
  } 
  }
    cout<<"δ����飬����ʧ��!"<<endl;
  return 0; 
} 
void disp() 
{//����������Ϣ
  int have=0;
  int bz=0;
  cout<<setw(5)<<no<<setw(21)<<name<<setw(15);
  for(int i=0;i<Maxbor;i++) 
  if(borbook[i]!=0)
  { 
   if(bz==0)
   {
   have=1;
   cout<<"["<<borbook[i]<<"]\t\t"<<endl;      
   bz++;
   }
   else
   {
   cout<<"\r\t\t\t\t\t""["<<borbook[i]<<"]\t\t"<<setw(15)<<endl; 
   }
  }
  if(have==0)
   cout<<"\t   ��δ����"<<endl;
}
};
 
class RDatabase 
{//������⣬ʵ�ֽ������ߵĸ������� 
private: 
int top; //���߼�¼ָ�� 
  Reader read[Maxr]; //���߼�¼ 
public: 
RDatabase() 
{//���캯������reader.txt����read[]�� 
  Reader s; 
  top=-1;  
  fstream file("reader.txt",ios::in); //��һ�������ļ�
  while (1) 
  { 
  file.read((char *)&s,sizeof(s)); 
  if (!file)
   break; 
  top++; 
  read[top]=s; 
  } 
  file.close(); //�ر� reader.txt �ļ�
} 
void clear() 
{//ɾ�����ж�����Ϣ 
 char i;
 cout<<"ȷ��ȫ��ɾ����Y/N ?"<<endl;
 cin>>i;
 if(i=='y'||i=='Y')
  top=-1; 
} 
int addreader(int n,char *na) 
{//��Ӷ���ʱ�Ȳ����Ƿ���� 
  Reader *p=queryid(n); 
  if (p==NULL)
  {
  top++; 
  read[top].addreader(n,na); 
  return 1; 
  }
  else
  cout<<"�ñ���Ѿ�����!";
  return 0; 
}  
Reader *queryid(int readerid) 
{//�����߱�Ų���
  for (int i=0;i<=top;i++) 
  if (read[i].getno()==readerid&&read[i].gettag()==0) 
  { 
   return &read[i]; 
  } 
  return NULL;
}
Reader *queryname(char readername[10])            
{//��������������
  for (int i=0;i<=top;i++) 
  if (strcmp(read[i].getname(),readername)==0 && read[i].gettag()==0) 
  { 
   return &read[i]; 
  } 
  return NULL; 
}                               
void disp() 
{//������ж�����Ϣ 
  for(int i=0;i<=top;i++)
 if (read[i].gettag()==0)
  read[i].disp(); 
} 
void readerdata(); //���߿���Ϣ
~RDatabase() 
{//������������read[]д��reader.txt�ļ���
  fstream file("reader.txt",ios::out); 
  for (int i=0;i<=top;i++) 
  if (read[i].gettag()==0) 
   file.write((char *)&read[i],sizeof(read[i])); 
  file.close(); 
} 
};
 
void RDatabase::readerdata() 
{
char choice1; 
char rname[20]; 
int readerid;
char readername[10];
int choice2;
Reader *r; 
while(choice1!='0')
{
  cout<<"\n\t\t\t** �� �� �� Ϣ **\n"<<endl;
  cout<<"\t\t\t** 1. ��    �� **"<<endl;
  cout<<"\t\t\t** 2. ��    �� **"<<endl;
  cout<<"\t\t\t** 3. ɾ    �� **"<<endl;
  cout<<"\t\t\t** 4. ��    �� **"<<endl;
  cout<<"\t\t\t** 5. ��    ʾ **"<<endl;
  cout<<"\t\t\t** 6. ȫ    ɾ **"<<endl;
  cout<<"\t\t\t** 0. ��    �� **"<<endl; 
  cout<<"\t\t\t ��ѡ��";
  cin>>choice1; 
  switch(choice1) 
  { 
  case '1': 
  cout<<"��������߱��:"; 
  cin>>readerid;
  cout<<"�������������:"; 
  cin>>rname;
  addreader(readerid,rname);
  cout<<"��Ӷ��߳ɹ�!"<<endl;
  getch();
  break;
  case '2': 
  cout<<"��������߱��:"; 
  cin>>readerid; 
  r=queryid(readerid); 
  if(r==NULL) 
  { 
   cout<<"�ö��߲�����! "<<endl; 
   break; 
  } 
  cout<<"�������µ�����:"; 
  cin>>rname; 
  r->setname(rname); 
  cout<<"�޸Ķ��߳ɹ�!"<<endl;
  getch();
  break;
  case '3': 
  cout<<"��������߱��:"; 
  cin>>readerid; 
  r=queryid(readerid); 
  if(r==NULL) 
  { 
   cout<<"�ö��߲�����!" << endl; 
   break; 
  }    
  r->delbook();
  cout<<"ɾ���ɹ�!"<<endl;
  getch();
    break; 
  case '4':
     cout<<"\n\t\t\t** 1.�����߱�Ų��� **"<<endl;
  cout<<"\t\t\t** 2.�������������� **"<<endl;
  cout<<"\t\t\t** 0.��     �� **"<<endl;
  cout<<"\t\t\t ��ѡ��:"; 
  cin>>choice2;
  switch(choice2)
  {
  case 1: 
   cout<<"��������߱��:"; 
   cin>>readerid;
   r=queryid(readerid); 
   if(r==NULL) 
   { 
   cout<<"�ö��߲�����!"<< endl; 
   break; 
   }
   cout<<setw(10)<<"���߱��"<<setw(17)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
    r->disp();
   break;   
  case 2: 
   cout<<"�������������:"; 
   cin>>readername; 
   r=queryname(readername); 
   if(r==NULL) 
   { 
   cout<<"�ö��߲�����!"<<endl;
   break; 
   }
   cout<<setw(10)<<"���߱��"<<setw(17)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
    r->disp();
    break;
   case 0: 
   break;
  }
       break;
  case '5':
  cout<<setw(10)<<"���߱��"<<setw(17)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
  disp();
  getch(); 
  break; 
  case '6': 
  clear();
  break; 
  default: 
  break; 
  } 
} 
}
 
 
class maindesk //ʵ�ֳ���������� 
{ 
  char choice5; 
 char choice2;
 double xh,mm;
  int bookid,readerid; 
  RDatabase ReaderDB; 
  Reader *r; 
  BDatabase BookDB; 
  Book *b;
public:
maindesk() {;}
 
int denglu()
{
 
int k=0;
cout<<"\n\t\t\t �� ӭ �� �� ͼ �� �� �� �� ϵ ͳ!"<<endl;
cout<<"\t\t\t �� �� �� 3 �� �� ½ �� ��"<<endl;
while(choice2!='0')
 { ++k;
cout<<"\t\t\t ** 1. ��  ¼ **"<<endl;
cout<<"\t\t\t ** 0. ��  �� **"<<endl;
cout<<"\t\t\t �� ѡ ��:  ";
cin>>choice2;
switch (choice2)
{
  
case '1':
   
    cout<<"������ѧ�ź�����"<<endl;
  cin>>xh>>mm;
   
 
   
  if((xh>=138325039)&&(xh<=138325039)&&(xh==mm))
  {
   cout<<"��¼�ɹ�"<<endl; 
   enterdesk();
  }
   
  if((xh<138325039)||(xh>138325039)||(xh!=mm))
  {cout<<"��¼ʧ�ܣ�������"<<3-k<<"�ε�½����"<<endl;
   if(k>=3)
  { 
  cout<<"���ѳ�����¼�������ޣ�ϵͳ�Զ��˳�!"<<endl;
  return 1;
  
 }
 continue;
 }
  break;
 
case '0':
 break;}
return 1;
}
return 0;
}
 
 void enterdesk()
 {
while(choice5!='0') 
{  
  cout<<"\n\t\t\t**** ͼ �� �� �� ϵ ͳ****\n\n"; 
  cout<<"\t\t\t** 1.ͼ  ��  ��  Ϣ **"<<endl;
  cout<<"\t\t\t** 2.��  ��  ��  Ϣ **"<<endl;
  cout<<"\t\t\t** 3.��  ��  ͼ  �� **"<<endl;
  cout<<"\t\t\t** 4.��  ��  ͼ  �� **"<<endl;
  cout<<"\t\t\t** 0.   ��  ��   **"<<endl; 
  cout<<"\t\t\t ��ѡ��";
  cin>>choice5; 
    switch (choice5) 
  { 
  
   
  case '1':  
      BookDB.bookdata(); 
  break; 
  case '2': 
      ReaderDB.readerdata(); 
  break; 
  case '3':
  cout<<"\t\t\t\t�������"<<endl;
  cout<<"�����������߱��:"; 
  cin>>readerid;
  r=ReaderDB.queryid(readerid);      
  if(NULL==r)  
  {//����Ų����Ƿ��иö��� 
   cout<<"�����ڸö��ߣ����ܽ���!"<<endl;
   break; 
  } 
      cout<<"������Ҫ��ͼ����:"; 
      cin>>bookid;  
      b=BookDB.query1(bookid);       
      if(b==NULL)  
  {//����Ų����Ƿ��и�ͼ�� 
        cout<<"�����ڸ�ͼ�飬���ܽ���!"<<endl;
   break; 
  }   
  if(b->borrowbook()==0) 
  { 
        cout<<"��ͼ���ѽ��꣬���ܽ���!"<<endl;
   break; 
  }
  cout<<"���߽���ɹ�!"<<endl;
  r->borrowbook(b->getno());
    break;  
  case '4': 
  cout<<"\t\t\t\t�������"<<endl;
  cout<<"�����뻹����߱��:"; 
  cin>>readerid;
      r=ReaderDB.queryid(readerid);
  if(r==NULL) 
  { 
   cout<<"�����ڸö��ߣ����ܻ���"<<endl;
   break; 
  } 
  cout<<"������Ҫ�黹ͼ����:"; 
  cin>>bookid; 
  b=BookDB.query1(bookid); 
  if(b==NULL) 
  {
   cout<<"�����ڸ�ͼ�飬���ܻ���"<<endl; 
   break; 
  }
      b->retbook(); 
      r->retbook(b->getno());
  break;
  case '0':
  break;
  default: 
  
  break; 
  } 
} 
}
};
int main() //������
{
 maindesk yourDesk;
 if(yourDesk.denglu())
 cout<<"\t\t л л ʹ �� , �� �� !"<<endl;
 
}
