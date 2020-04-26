//
// Created by sahejpal on 3/30/20.
//
#include "Admin.h"
#include<bits/stdc++.h>


void Admin::AddMember()
{
    string username,password;
    fstream fhandle;
    cout << "Enter the name of the member" << endl;
    getline(cin.ignore(),username);
    bool flag = true;
    fhandle.open("Login.txt", ios::in | ios::out | ios::app);
    while (fhandle) {
        string temp, tempp;
        fhandle >> temp >> tempp;
        if (username == temp) {
            cout << "The user already exists" << endl;
            flag = false;
        }
    }
    fhandle.close();
    fhandle.open("Login.txt", ios::in | ios::out | ios::app);
    if (flag && fhandle) {
        password = username;
        transform(password.begin(), password.end(), password.begin(), ::toupper);
        fhandle<< username << ' ' << password<<endl;
        cout << "User has been added\n"
                "Login Details:\n"
                "Username:" << username <<
             "\nPassword:" << password << endl;
        fhandle.close();
    }

}

void Admin::AddBooks()
{
    string name, temp, author, number;
    cout << "Enter the name of the book" << endl;
    getline(cin.ignore(), name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream fhandle("Books.txt", ios::in);
    bool flag = true;
    while (getline(fhandle, temp, ':') && getline(fhandle, author, ':') && getline(fhandle, number))
    {

        ofstream file("temp.txt", ios::out | ios::app);
        int num = stoi(number);
        if (name == temp)
        {
            num = num + 1;
            file << temp << ':' << author << ':' << num << endl;
            flag = false;
            cout<<"The book already exists the number has been updated"<<endl;
        }
        file.close();

    }
    fhandle.close();
    ofstream file("temp.txt", ios::out | ios::app);
    if (flag)
    {
        string author1;
        cout << "Enter the name of the author" << endl;
        getline(cin,author1);
        transform(author1.begin(), author1.end(), author1.begin(), ::toupper);
        cout<<"The book has been added"<<endl;
        file << name << ':' << author1 << ':' << '1' << endl;
    }
    fstream fin("Books.txt", ios::in);
    while (getline(fin, temp, ':') && getline(fin, author, ':') && getline(fin, number))
    {

        if (name == temp)
        {
            continue;
        }
        file << temp << ':' << author << ':' << number << endl;
    }
    fin.close();
    file.close();
    remove("Books.txt");
    rename("temp.txt","Books.txt");

}

void Admin::RemoveMember()
{
    string name,temp,password;
    cout<<"Enter the name of the member to be removed"<<endl;
    getline(cin.ignore(),name);
    fstream fhandle("Login.txt", ios::in);
    bool flag = true;
    while (getline(fhandle,temp,' ') && getline(fhandle,password))
    {

        ofstream file("temp.txt",ios::out|ios::app);
        if(name == temp )
        {
            flag = false;
            cout<<"The user has been removed"<<endl;
            continue;
        }
        else
        {
            file<<temp<<' '<<password<<endl;
        }
        file.close();
    }
    if(flag)
    {
        cout<<"The username does not exist"<<endl;
    }
    fhandle.close();
    remove("Login.txt");
    rename("temp.txt","Login.txt");


}

void Admin::ViewRequests()
{
    string name,author;
    int count = 1;
    ifstream fhandle("Requests.txt",ios::in);
    while(getline(fhandle,name,':') && getline(fhandle,author))
    {
        cout<<count<<'.';
        cout<<"Name: "<<name<<endl;
        cout<<"  By:   "<<author<<endl;
        count++;
    }
}

void Admin::ViewRecords()
{
    string username,name;
    int count = 1;
    fstream fhandle("Records.txt",ios::in);
    while(getline(fhandle,username,' ') && getline(fhandle,name))
    {
        cout<<count<<'.'<<username<<endl;
        cout<<"  "<<name<<endl;
        cout<<endl;
        count++;
    }
    fhandle.close();
}