//
// Created by sahejpal on 4/6/20.
//

#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H



class Member {
public:
    void GetDetails();
    void Issue(std::string &username);
    void Return();
    void ChangePassword();
    void Request(std::string name);
    void Record(std::string username,std:: string name);

};


#endif //LIBRARY_MEMBER_H
