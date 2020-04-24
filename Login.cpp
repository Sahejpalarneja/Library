//
// Created by sahejpal on 3/24/20.
//
#include <iostream>
#include <string>
#include "Login.h"
#include "Admin.cpp"

Login::Login()
{
    ;
}
Login::Login(string username, string password)
{
    this->username = username;
    this->password = password;
}
void Login::check()
{
    string Uname,Upass;
    ifstream fhandle;
    fhandle.open("Login.txt",ios::in);
    while(fhandle)
    {
        fhandle>>Uname>>Upass;
        if(this->username == Uname && this->password == Upass)
        {
            memberpage();
            return;
        }
    }
    Uname="admin";
    Upass = "password";
    if(this->username == Uname && this->password == Upass)
    {
        adminpage();
    } else{
        cout<<"Wrong username or password"<<endl;
    }
    fhandle.close();
}
void Login:: adminpage()
{
    int choice;
    Login admin;
    while (true)
    {
        cout << "MENU" << endl;
        cout << "1.Add Members\n";
        cout << "2.Remove Members \n";
        cout << "3.Add books\n";
        cout << "4.View Requests\n";
        cout << "5.View Records\n";
        cout << "6.Logout\n";
        cout << "Enter the number of your choice" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                admin.AddMember();
                break;
            case 2:
                admin.RemoveMember();
                break;
            case 3:
                admin.AddBooks();
                break;
            case 4:
                admin.ViewRequests();
                break;
            case 5:
                admin.ViewRecords();
                break;
            case 6:
                cout<<"Logging out..."<<endl;
                exit(0);
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    }

}

void Login::memberpage()
{
    string choice;
    cout<<"Menu\n";
    cout<<"1.Get Details\n";
    cout<<"2.Issue\n";
    cout<<"3.Return\n";
    cout<<"4.Change Password\n";
    cout<<"5.Request Books\n";

}