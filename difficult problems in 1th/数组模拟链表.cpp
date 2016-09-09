#include<string>
#include<iostream>
#include<memory>
#include<sstream>
#ifndef LIST_H_
#define LIST_H_
#define MAX_STORAGE 1000
using namespace std; 
class list{
    typedef int data_type;
    typedef int pointer;
    typedef unsigned int size_type;
    static const pointer nullpointer = -1;
    typedef struct node {
        data_type data;
        pointer next;
        node(const node &another) {
          this->operator=(another);
        }
        node& operator=(const node &another) {
          this->data = another.data;
          this->next = another.next;
        }
        node(data_type data = 0, pointer next = nullpointer) : data(data), next(next) {}
    } node;
    node storage[MAX_STORAGE];
    size_type _size;
    pointer head;
    pointer empty_head;
 
public:
    list();
    list(const list& another);
    list& operator=(const list&);
    ~list();
 
    // Capacity
    bool empty(void) const;
    size_type size(void) const;
 
    // output
    // list: [1,2,3,4,5]
    // output: 1->2->3->4->5->NULL
    std::string toString(void) const;
 
    void insert(int position, const int& data);
    void erase(int position);
    void clear(void);
    list& sort(void);
};
 
#endif // !LIST_H_

    list:: list() {
        clear();
    }
    list:: list(const list& another) {
         clear();
         _size= another._size;
         head= another.head;
         empty_head= another.empty_head;
         int i;
         for (i= 0; i< _size; i++) {
            storage[i]= another.storage[i];
         }
    }
    list& list:: operator=(const list&another) {
         clear();
         _size= another._size;
         head= another.head;
         empty_head= another.empty_head;
         int i;
         for (i= 0; i< _size; i++) {
            storage[i]= another.storage[i];
         }
         return *this;
    }
    list:: ~list() {
    }
    bool list:: empty(void) const {
        if (_size== 0)
            return true;
        return false;
    }
    list:: size_type list:: size(void) const {
        return _size;
    }
    // output
    // list: [1,2,3,4,5]
    // output: 1->2->3->4->5->NULL
    std::string list:: toString(void) const {
        int i= head;
        string s1= "";
        while (i!= -1) {
            stringstream h1;
            string s3;
            h1<< storage[i].data;
            h1>> s3;
            s1+= s3;
            s1+= "->";
            i= storage[i].next;
        }
        s1+= "NULL";
        return s1;
    }
    void list:: insert(int position, const int& data) {
        if (position< 0|| position> _size)
            return;
        if (_size+ 1<= 1000) {
            int temp= empty_head;
            empty_head= storage[empty_head].next;
            storage[temp].data= data;
            if (position== 0) {
                storage[temp].next= head;
                head= temp;
            } else {
                int p= head;
                for (int i= 0; i< position- 1; i++) {
                    p= storage[p].next;
                }
                storage[temp].next= storage[p].next;
                storage[p].next= temp;
            }
            _size++;
        }
    }
    void list:: erase(int position) {
        if (position< 0|| position>= _size)
            return;
        if (position== 0) {
            int temp= head;  // ¼ÇÂ¼headÔ­Î»ÖÃ
            head= storage[head].next;
            storage[temp].next= empty_head;
            empty_head= temp;
        } else {
            int p= head;
                for (int i= 0; i< position- 1; i++) {
                    p= storage[p].next;
                }
                int q= storage[p].next;
                storage[p].next= storage[storage[p].next].next;
                storage[q].next= empty_head;
                empty_head= q;
        }
        _size--;
    }
    void list:: clear(void) {
        _size= 0;
        head= nullpointer;
        empty_head= 0;
        for (int i= 0; i< 1000; i++) {
            storage[i].data= 0;
            storage[i].next= i+ 1;
        }
    }
    list& list:: sort(void) {
        int temp= head;
        int a[1001]= {0};
        int k= 0;
        int i, j;
        while (temp!= -1) {
            a[k++]= storage[temp].data;
            temp= storage[temp].next;
        }
        if (_size!= 0) {
            for (i= 0; i< _size- 1; i++) {
                for (j= i+ 1; j< _size; j++) {
                    if (a[j]< a[i]) {
                        int t= a[i];
                        a[i]= a[j];
                        a[j]= t;
                    }
                }
            }
        }
        k= 0;
        temp= head;
        while (temp!= -1) {
            storage[temp].data= a[k++];
            temp= storage[temp].next;
        }
        return *this;
    }
int main() {
    list li;
 
    int n;
    cin >> n;
 
    for (int i = 0, data, pos; i < n; i++) {
        cin >> pos >> data;
        li.insert(pos, data);
    }
 
    cout << li.toString() << " size: " << li.size() << endl;
 
    list li2(li);
    list li3;
 
    li = li3 = li2 = li;
 
    cout << li.toString() << " size: " << li.size() << endl;
    cout << li2.toString() << " size: " << li2.size() << endl;
    cout << li3.toString() << " size: " << li3.size() << endl;
 
    int m;
    cin >> m;
 
    for (int i = 0, pos; i < m; i++) {
        cin >> pos;
        li.erase(pos);
    }
 
    for (int i = 0, temp; i < m; i++) {
      cin >> temp;
      li.insert(0, temp);
    }
 
    cout << li.toString() << endl;
 
    cout << li.sort().toString() << endl;
    cout << li2.sort().toString() << endl;
    cout << li3.sort().toString() << endl;
 
    return 0;
}
