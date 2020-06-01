//
// Created by sahejpal on 4/6/20.
//

#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H


#include<string>
#include "User.h"


//inherits form User class
class Member:public User
{
private:
    string username;
    string password;
public:
        Member(string username,string password);
        void GetDetails();
        void Issue(std::string &username);
        void Return();
        void ChangePassword();
        void LibraryCard(std::string username);
        void Request();
        void DateExtend(std::string username);
        void Record(const std::string& username,const std:: string& name,int day, int month);
};


#endif //LIBRARY_MEMBER_H
