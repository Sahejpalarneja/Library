//
// Created by sahejpal on 3/24/20.
//

#ifndef LIBRARY_LOGIN_H
#define LIBRARY_LOGIN_H

#include <iostream>
#include <string>




using namespace std;
//Base class for Admin and Member
class User
 {
    string username;
    string password;
public:
    User();
    User(string username, string password);
    void page();
    void page(User &user);
    void check();
    };
#endif //LIBRARY_LOGIN_H
