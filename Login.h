//
// Created by sahejpal on 3/24/20.
//

#ifndef LIBRARY_LOGIN_H
#define LIBRARY_LOGIN_H

#include <iostream>
#include <string>
#include "Admin.h"
#include "Member.h"
using namespace std;
class Login: public Admin, public Member {
    string username;
    string password;
public:
    Login(string username, string password);
    Login();
    static void adminpage();
    static void memberpage();
    void check();
};

#endif //LIBRARY_LOGIN_H
