#include "User.h"

using namespace std;

int main()
{
    string password,name;
    cout << "Username:" << endl;
    cin >> name;
    cout << "Password:" << endl;
    cin >> password;
    User user(name, password);//Creates a user with name and password
    user.check();//checks for the username and password inside Login file
    return 0;
}
