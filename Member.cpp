//
// Created by sahejpal on 4/6/20.
//

#include "Member.h"
#include <iostream>
#include <fstream>
#include <string>
void Member::Record(string username, string name)
{
    fstream fhandle("Records.txt",ios::out|ios::app);
    file<<username<<' '<<name<<endl;
}

void Member::Request(string name = '0')
{
    string author,temp,atemp;
    bool flag= false;
    if(name == "0")
    {
        cout<<"Enter the name of the book"<<endl;
        getline(cin,name);
    }
    cout<<"Enter the name of the author"<<endl;
    getline(cin,author);
    transform(author.begin(), author.end(), author.begin(), ::toupper);
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    ifstream fhandle("Requests.txt",ios::in);
    while(getline(fhandle,temp,':') && getline(fhandle,atemp))
    {
        if(temp == name && atemp == author)
        {
            flag = true;
            cout<<"Request has been registered,Thank You!!"<<endl;
        }
    }
    fhandle.close();
    fstream file("Requests.txt", ios::out | ios::app);
    if(!flag)
    {

        file<<name<<':'<<author<<endl;
        cout<<"Request has been Registered , Thank You!!"<<endl;
    }
    file.close();
}

void Member::GetDetails()
{
    string name, temp, author, number;
    bool flag = false;
    cout << "Enter the name of the book" << endl;
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream fhandle("Books.txt", ios::in);
    while (getline(fhandle, temp, ':') && getline(fhandle, author, ':') && getline(fhandle, number)) {
        int num = stoi(number);
        if (name == temp) {
            cout << name << endl;
            cout << "By: " <<author << endl;
            flag =true;
            if (num > 0) {
                cout << "Available for Borrowing" << endl;
            } else {
                cout << "Not available for borrowing" << endl;
            }
        }
    }
    if(!flag)
    {
        char ch;
        cout << "Book not found" << endl;
        cout << "Press y to request the book" << endl;
        cout << "Press any other button to go back to the MENU" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            Request(name);
        }
    }
}

void Member::ChangePassword()
{
    bool flag = true;
    string User, pass, newpass;
    cout << "Enter your Username" << endl;
    getline (cin, User);
    cout << "Enter your current password" << endl;
    getline (cin, pass);
    cout << "Enter New Password" << endl;
    getline (cin, newpass);
    fstream fhandle ("Login.txt", ios::in);
    string temp, temp2;
    fstream file ("temp.txt", ios::out | ios::app);
    while (getline (fhandle, temp, ' ') && getline (fhandle, temp2)) {
        if (User == temp) {

            file << User << ' ' << newpass << endl;
            flag = false;
        }
    }
    if (flag) {
        cout << "User not found" << endl;
    }
    fhandle.close ();
    fstream fin ("Login.txt", ios::in);
    while (getline (fin, temp, ' ') && getline (fin, temp2)) {
        cout << "Open" << endl;
        if (User == temp) {
            continue;
        }
        file << temp << ' ' << temp2 << endl;
    }
    fin.close ();
    file.close ();
    remove ("Login.txt");
    rename ("temp.txt", "Login.txt");
}

void Member::Issue(string username)
{
    string name, author, number;
    int count = 1;
    bool flag = true;
    fstream fhandle("Books.txt", ios::in);
    cout << "The Library currently has the following books available for borrowing" << endl;
    while (getline(fhandle, name, ':') && getline(fhandle, author, ':') && getline(fhandle, number)) {
        int num = stoi(number);
        if (num > 0) {
            cout<<endl;cout << name << endl;
            cout << count<<'.'<<"By: " << author << endl;
            count++;
        }
    }
    fhandle.close();
    string temp;
    cout << "Enter the name of the book You want to borrow" << endl;
    getline(cin,name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream fin("Books.txt", ios::in);
    while (getline(fin, temp, ':') && getline(fin, author, ':') && getline(fin, number)) {
        ofstream file("temp.txt", ios::out | ios::app);
        int num = stoi(number);
        if (name == temp) {
            num = num - 1;
            file << temp << ':' << author << ':' << num << endl;
            Record(username,name);
            cout << "The book has been successfully borrowed" << endl;
            flag = false;
        }
        file.close();
    }
    if(flag)
    {
        cout<<"Choice is not available"<<endl;
    }
    fin.close();
    ofstream file("temp.txt", ios::out | ios::app);
    fstream fh("Books.txt", ios::in);
    while (getline(fh, temp, ':') && getline(fh, author, ':') && getline(fh, number)) {

        if (name == temp) {
            continue;
        }
        file << temp << ':' << author << ':' << number << endl;
    }
    fh.close();
    file.close();
    remove("Books.txt");
    rename("temp.txt", "Books.txt");
}

void Member::Return()
{


}