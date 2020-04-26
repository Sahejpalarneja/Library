//
// Created by sahejpal on 4/6/20.
//

#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H



class Member {
public:
    static void GetDetails();
    static void Issue(std::string &username);
    static void Return();
    static void ChangePassword();
    static void Request();
    static void Record(const std::string& username,const std:: string& name);

};


#endif //LIBRARY_MEMBER_H
