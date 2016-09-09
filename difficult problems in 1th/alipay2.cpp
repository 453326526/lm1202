    #include <string>
    #include<iostream>
    #include<cstring>
    #include<stdio.h>
    using namespace std;
    namespace Alipay {
class user {
  char username[21];
  char password[21];
  double balance;
 
 public:
  user(const char* username, const char* password);
  ~user();
  const char* getUsername() const;
  const char* getPassword() const;
  const void setUsername(const char* username);
  const void setPassword(const char* password);
 
  double getBalance();
 
  bool withdraw(double amount);
  bool deposite(double amount);
};
}

    namespace Alipay {
class userController {
 private:
  double interest_rate;
  user* users[10000];
  int usercount;
  int getUserIndex(const char* username) const;
 
 public:
  userController(double interest_rate);
  ~userController();
  bool createUser(const char* username, const char* password);
  bool deposite(const char* username, double amount);
  bool withdraw(const char* username, double amount);
  std::string getUserInfoByName(const char* username) const;
  int getUserCount(void) const;
  bool removeUserByUsername(const char* username);
  bool setInterest(double interest);
  void payInterest(void);
};
}
      int Alipay:: userController:: getUserIndex(const char* username) const {
          int pos= 0;
          for (pos= 0; pos< usercount; pos++) {
              string s1, s2;
              s1.assign(users[pos]->getUsername());
              s2.assign(username);
              if (s1== s2)
                return pos;
          }
          return -1;
      }
      Alipay:: userController:: userController(double interest_rate) {
          this->interest_rate= interest_rate;
          for (int i= 0; i< 10000; i++)
             users[i]= NULL;
          usercount= 0;
      }
      Alipay:: userController:: ~userController() {
          for (int i= 0; i< usercount&&users[i]!= NULL; i++)
            delete users[i];
          interest_rate= 0;
      }
      bool Alipay:: userController:: createUser
      (const char* username, const char* password) {
          if (strlen(password)>= 8) {
              users[usercount]= new user(username, password);
              usercount++;
              return true;
          }
          return false;
      }
      bool Alipay:: userController:: deposite(const char* username, double amount) {
          int pos= getUserIndex(username);
          if (pos== -1) {
            return false;
          } else {
                  users[pos]->deposite(amount);
          }
      }
      bool Alipay:: userController:: withdraw(const char* username, double amount) {
          int pos= getUserIndex(username);
          if (pos== -1) {
            return false;
          } else {
                  users[pos]->withdraw(amount);
          }
      }
      std::string Alipay:: userController:: getUserInfoByName
      (const char* username) const {
          int pos= getUserIndex(username);
          if (pos!= -1) {
              string s1= "";
              char a[100];
              memset(a, 0, sizeof(a));
        snprintf(a, sizeof(a), "username:%s\npassword:*********\nbalance:%.6f",
              users[pos]->getUsername(), users[pos]->getBalance());
              s1.assign(a);
              return s1;
          } else {
              return "No such user!\n";
          }
      }
      int Alipay:: userController:: getUserCount(void) const {
          return usercount;
      }
      bool Alipay:: userController:: removeUserByUsername(const char* username) {
          int pos= getUserIndex(username);
          if (pos== -1) {
            return false;
          } else {
              delete users[pos];
              int i;
              usercount--;
              for (i= pos; i< usercount; i++) {
                  users[i]= users[i+ 1];
              }
              users[i]= NULL;
              return true;
          }
      }
      bool Alipay:: userController:: setInterest(double interest) {
          if (interest> 0) {
              this->interest_rate= interest;
              return true;
          }
          return false;
      }
      void Alipay:: userController:: payInterest(void) {
          int i;
          for (i= 0; i< usercount; i++) {
              users[i]->deposite(interest_rate* users[i]->getBalance());
          }
      }
      
      
    Alipay::user:: user(const char* username, const char* password) {
      memset(this->username, 0, sizeof(username));
      memset(this->password, 0, sizeof(password));
      strncpy(this->username, username, 21);
      strncpy(this->password, password, 21);
      balance= 0;
  }
  Alipay::user:: ~user() {
  }
  const char* Alipay::user:: getUsername() const {
      return username;
  }
  const char* Alipay::user:: getPassword() const {
      return password;
  }
  const void Alipay::user:: setUsername(const char* username) {
      memset(this->username, 0, sizeof(username));
      strncpy(this->username, username, 21);
  }
  const void Alipay::user:: setPassword(const char* password) {
       memset(this->password, 0, sizeof(password));
       strncpy(this->password, password, 21);
  }
  double Alipay::user:: getBalance() {
        return balance;
  }
  bool Alipay::user:: withdraw(double amount) {
      if (amount > 0.000001) {
      if (this->balance - amount >= 0.000001) {
        this->balance -= amount;
        return true;
      }
      return false;
    }
    return false;
  }
  bool Alipay::user:: deposite(double amount) {
      if (amount >= 0.000001) {
        this->balance += amount;
        return true;
      }
      return false;
  }
  namespace Alipay {
      #define boss "Mayun"
#define MAX_USER 10000
enum GENDER { MALE = 0, FEMALE = 1 };
 
const double PRECISION = 0.000001;
}


  void help() {
  cout << "Welcome to Alipay Managament System" << endl;
  cout << "Please select your service using the number:" << endl;
  cout << "[1] Create an user" << endl;
  cout << "[2] Get an user's info by username" << endl;
  cout << "[3] Get total user count" << endl;
  cout << "[4] Remove one user" << endl;
  cout << "[5] Set interest" << endl;
  cout << "[6] Pay interest" << endl;
  cout << "[7] withdraw(for one account)" << endl;
  cout << "[8] deposite(for one account)" << endl;
  cout << "[9] Display help info" << endl;
  cout << "[0] Quit" << endl;
}
 
int main() {
  help();
  Alipay::userController controller(0.005);
  while (true) {
    cout << "Alipay $ ";
    int choose;
    cin >> choose;
    switch (choose) {
      case 1:
        if (true) {
          char username[21];
          char password[21];
          cout << "please input [username] [password]" << endl;
          cin >> username >> password;
          if (controller.createUser(username, password)) {
            cout << "create user successfully!" << endl;
          } else {
            cout << "fail to create user with username:" << username
                 << " password:" << password << endl;
          }
          break;
        }
      case 2:
        if (true) {
          char username[21];
          cout << "please input username" << endl;
          cin >> username;
          cout << "user info:" << endl;
          cout << controller.getUserInfoByName(username) << endl;
          break;
        }
      case 3:
        cout << "Total user count: " << controller.getUserCount() << endl;
        break;
      case 4:
        if (true) {
          char username[21];
          cout << "please input username" << endl;
          cin >> username;
          if (controller.removeUserByUsername(username)) {
            cout << "remove user successfully!" << endl;
          } else {
            cout << "fail to reomove user with username:" << username << endl;
          }
          break;
        }
      case 5:
        if (true) {
          double newRate;
          cout << "please input the new interest rate:" << endl;
          cin >> newRate;
          if (controller.setInterest(newRate)) {
            cout << "set interest successfully" << endl;
          } else {
            cout << "set interest falied with interest rate:" << newRate
                 << endl;
          }
          break;
        }
      case 6:
        if (true) {
          controller.payInterest();
          cout << "pay interest compelete" << endl;
          break;
        }
      case 7:
        if (true) {
          cout << "please input [username] [withdraw_amount]" << endl;
          char username[21];
          double amount;
          cin >> username >> amount;
          if (controller.withdraw(username, amount)) {
            cout << "withdraw successfully!" << endl;
          } else {
            cout << "withdraw falied with amount:" << amount << endl;
          }
          break;
        }
      case 8:
        if (true) {
          cout << "please input [username] [deposite_amount]" << endl;
          char username[21];
          double amount;
          cin >> username >> amount;
          if (controller.deposite(username, amount)) {
            cout << "deposite successfully!" << endl;
          } else {
            cout << "deposite falied with amount:" << amount << endl;
          }
          break;
        }
      case 0:
        cout << "Tanks for using Alipay, Bye!" << endl;
        return 0;
      case 9:
        help();
        break;
      default:
        cout << "No suchu command! Please input again" << endl;
        help();
    }
  }
 
  return 0;
}

