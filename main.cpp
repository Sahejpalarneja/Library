
#include "Login.cpp"
using namespace std;


int main() {
    string username,password;
     cout<<"Username:"<<endl;
     cin>>username;
     cout<<"Password:"<<endl;
     cin>>password;
     Login User(username, password);
     User.check();
     return 0;

}
