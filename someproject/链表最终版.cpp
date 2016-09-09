
#include<string>
#include<iostream>
#include<cstdio>
#include<sstream>
 
struct DouListNode {
  int elem;
  DouListNode *prev, *next;
  DouListNode(int e = 0, DouListNode *p = 0, DouListNode *n = 0) {
    elem = e;
    prev = p;
    next = n;
  }
};
 
class DouList {
  private:
    DouListNode *m_head, *m_tail;
  public:
    DouList();
    DouList(const DouList &src);
    ~DouList();
    void clear();
    bool empty() const;
    std::string to_str() const;
    int front() const;
    int back() const;
    void push_front(const int &e);
    void push_back(const int &e);
    void pop_front();
    void pop_back();
    void operator=(const DouList &other);
    friend std::ostream& operator<<(std::ostream &out,
           const DouList &list);
    // non-meaning static value
    static int _error_sign;  // for illegal front()/back()
};
using namespace std;
    DouListNode *m_head, *m_tail;
    DouList:: DouList() {
        m_head= NULL;
        m_tail= NULL;
    }
    DouList:: DouList(const DouList &src) {
        DouListNode *temp= src.m_head;
        m_head= NULL;
        m_tail= NULL;
        while (temp!= NULL) {
            push_back(temp->elem);
            temp= temp->next;
        }
    }
    DouList:: ~DouList() {
          clear();
    }
    void DouList:: clear() {
        DouListNode *p = m_head;
          DouListNode *q = NULL;
          while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
          }
          m_head= NULL;
          m_tail= NULL;
    }
    bool DouList:: empty() const {
        return (m_head== NULL);
    }
    std::string DouList:: to_str() const {
        string s1= "";
        s1+= "[";
        DouListNode *temp = m_head;
        stringstream t;
        string s3= "";
        if (temp!= NULL) {
            t<< temp->elem;
            t>> s3;
            s1+= s3;
            temp= temp-> next;
        }
            while (temp!= NULL) {
                stringstream h;
                string s2= "";
                s1+= ", ";
                h<< temp->elem;
                h>> s2;
                s1+= s2;
                temp= temp->next;
            }
        s1+= "]";
        return s1;
    }
    int DouList:: front() const {
        return m_head->elem;
    }
    int DouList:: back() const {
        return m_tail->elem;
    }
    void DouList:: push_front(const int &e) {
        DouListNode *temp = new DouListNode(e, NULL, m_head);
        if (m_head== NULL) {
          m_head= temp;
          m_tail = m_head;
        } else {
          m_head= temp;
          m_head->next->prev = m_head;
        }
    }
    void DouList:: push_back(const int &e) {
        DouListNode *temp = new DouListNode(e, m_tail, NULL);
        if (m_head== NULL) {
          m_head= temp;
          m_tail = m_head;
        } else {
          m_tail= temp;
          m_tail->prev->next = m_tail;
        }
    }
    void DouList:: pop_front() {
        DouListNode *temp= m_head;
        m_head= m_head->next;
        m_head->prev= NULL;
        delete temp;
    }
    void DouList:: pop_back() {
        DouListNode *temp= m_tail;
        m_tail= m_tail->prev;
        m_tail->next= NULL;
        delete temp;
    }
    void DouList:: operator=(const DouList &other) {
        clear();
        DouListNode *temp= other.m_head;
        while (temp!= NULL) {
            push_back(temp->elem);
            temp= temp->next;
        }
    }
    std::ostream& operator<<(std::ostream &out,
           const DouList &list) {
               cout<< list.to_str();
               return out;
           }
DouList list1, list2;
 
void display() {
  cout << list1.empty() << ':' << list1 << endl;
  cout << list2.empty() << ':' << list2.to_str() << endl;
}
 
int main() {
  display();
  list1.push_front(894);
  list2.push_back(2136);
  cout << list1.front() << ',' << list1.back() << endl;
  cout << list2.front() << ',' << list2.back() << endl;
  display();
  list1.push_back(214);
  list2.push_front(931);
  cout << list1.front() << ',' << list1.back() << endl;
  cout << list2.front() << ',' << list2.back() << endl;
  display();
  for (int i = 0; i < 10; ++i) {
    int t;
    cin >> t;
    list1.push_back(t);
    list2.push_front(t);
  }
  display();
  for (int i = 0; i < 5; ++i) {
    list1.pop_front();
    list2.pop_back();
  }
  display();
 
  DouList list3(list1);
  list1 = list2;
  cout << list1 << endl;
  //cout << list3 << endl;
  return 0;
}

