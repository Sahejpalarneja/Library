//
// Created by sahejpal on 3/24/20.
//
#include <iostream>
#include <string>
#include<fstream>
#include "User.h"
#include"Admin.h"
#include"Member.h"


/*Empty Constructor for admin as a User*/
User::User()
{
    ;
}


//Constructor
User::User(string username,string password)
{
    this->username = username;
    this->password = password;
}


/*Method reads the file for the username and password,
 * if he username and password match the Member Menu is displayed
 * if username or password does not match, method checks for admin login and Admin Menu is displayed
 * upon not finding any of the above programme quits with error message */
void User::check()
{
    string Upass,Uname;
    std::ifstream fhandle;//FILE variable
    fhandle.open("Login.txt",ios::in);
    while(fhandle)
    {
        fhandle>>Uname>>Upass;
        if(this->username == Uname && this->password == Upass)
        {
            //Member Menu call
            User user(this->username,this->password);
            page(user);
        }
    }
    if(this->username =="admin" && this->password == "password")
    {
       //Admin menu
        page();
    }
    else{
        cout<<"Wrong username or password"<<endl;
    }
    fhandle.close();
}


/* page:
 *      Menu with switch case displays the options and ask for the admins choice,
 *      Depending on the admins choice the respective function is called,
 *      if choice is wrong , error message is displayed. admin has to logout to quit program
 *      */
void User:: page()
{
    int choice;
    //Object to call functions from subclass class
    Admin admin;
    
    while (true)
    {
        cout << "MENU" << endl;
        cout << "1.Add Members\n";
        cout << "2.Remove Members \n";
        cout << "3.Add books\n";
        cout << "4.View Requests\n";
        cout << "5.View Records\n";
        cout << "6.View Member List\n";
        cout << "7.Logout\n";
        cout << "Enter the number of your choice" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                admin.AddMember ();
                break;
            case 2:
                admin.RemoveMember ();
                break;
            case 3:
                admin.AddBooks ();
                break;
            case 4:
                admin.ViewRequests ();
                break;
            case 5:
                admin.ViewRecords ();
                break;
            case 6:
                admin.memberlist();
                break;
            case 7:
                cout << "Logging out..." << endl;
                exit (0);
            default:
                cout << "Wrong choice" << endl;
                //to clear the input stream for the loop to wait for input
                cin.clear();
                cin.ignore();
                break;
        }

    }
}


/*Page:
 *        Menu with switch case displays the options and ask for the users choice,
 *        Depending on the users choice the respective function is called,
 *        if choice is wrong , error message is displayed. User has to logout to quit program*/
void User::page(User &user)
{
    int choice;
    //Object to call functions from subclass class
   Member *member = static_cast<Member*>(&user);//static cast
    while (true)
    {
        cout<<"Menu\n";
        cout<<"1.Get Details\n";
        cout<<"2.Issue\n";
        cout<<"3.Return\n";
        cout<<"4.Change Password\n";
        cout<<"5.Request Books\n";
        cout<<"6.View Library Card\n";
        cout<<"7.Extend Return date\n";
        cout<<"8.Logout\n";
        cout<<"Enter the number of your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
                member->GetDetails();
                break;
            case 2:
                member->Issue(username);
                break;
            case 3:
                member->Return();
                break;
            case 4:
                member->ChangePassword();
                break;
            case 5:
                member->Request();
                break;
            case 6:
                member->LibraryCard(username);
                break;
            case 7:
                member->DateExtend(username);
                break;
            case 8:
                cout << "Logging out..." << endl;
                exit(0);
            default:
                cout << "Wrong choice" << endl;
                //to clear the input stream for the loop to wait for input
                cin.clear();
                cin.ignore();
                break;
        }
    }
}
