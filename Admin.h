//
// Created by sahejpal on 3/30/20.
//

#ifndef LIBRARY_ADMIN_H
#define LIBRARY_ADMIN_H


#include <string>
#include <iostream>
#include"User.h"


//inherits from user class
class Admin:public User
{
    public:

        void AddMember();
        void RemoveMember();
        void memberlist();
        void AddBooks();
        void ViewRequests();
        void ViewRecords();
};


#endif //LIBRARY_ADMIN_H
