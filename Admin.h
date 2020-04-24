//
// Created by sahejpal on 3/30/20.
//

#ifndef LIBRARY_ADMIN_H
#define LIBRARY_ADMIN_H
#include <string>
#include <iostream>

class Admin {
public:
    static void AddMember();
    static void RemoveMember();
    static void AddBooks();
    static void ViewRequests();
    void ViewRecords();
};


#endif //LIBRARY_ADMIN_H
