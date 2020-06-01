//
// Created by sahejpal on 3/30/20.
//
#include "Admin.h"
#include<bits/stdc++.h>
#include<fstream>
using namespace std;



/*  Asks the admin for the username of the new user and checks
    whether the username is taken or not , if the username is free it
    writes the username and password(the username in Uppercase) on to the login file
    and displays the login details
    */
void Admin::AddMember()
{
    string username,password;
    fstream fhandle;
    cout << "Enter the name of the member" << endl;
    cin>>username;
    bool flag = true;
    fhandle.open("Login.txt", ios::in | ios::out | ios::app);
    while (fhandle) {
        string temp, tempp;
        fhandle >> temp >> tempp;
        if (username == temp) {
            cout << "The user already exists" << endl;
            //turns boolean variable to false
            flag = false;
        }
    }
    fhandle.close();
    fhandle.open("Login.txt", ios::in | ios::out | ios::app);
    //if user not found, username and password are written to Login.txt file,
    // and Login Details displayed
    if (flag && fhandle) {
        password = username;

        //lowercase to upercase
        transform(password.begin(), password.end(), password.begin(), ::toupper);

        fhandle<< username << ' ' << password<<endl;
        cout << "User has been added\n"
                "Login Details:\n"
                "Username:" << username <<
             "\nPassword:" << password << endl;
        fhandle.close();
    }

}



/* Admin can add books to the Library,
 * the admin enter the name of the book and the author,
 * if the book already exists in the txt file the number of the book is updated
 * else the new books name and author are written to the file*/
void Admin::AddBooks()
{

    string name, temp, author, number;
    cout << "Enter the name of the book" << endl;
    getline(cin.ignore(), name);
    //throws an exception if enter is pressed without any input
    try{
        if(name.length() == 0 )
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect input"<<endl;
        return ;
    }
    //lowercase to upercase
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    fstream fhandle("Books.txt", ios::in);
    bool flag = true;
    while (fhandle)
    {
        getline(fhandle, temp, ':') ;
        getline(fhandle, author, ':');
        getline(fhandle, number);

        //temporary file has been used to edit the number
        ofstream file("temp.txt", ios::out | ios::app);
         int *num = new int;
        *num = stoi(number);
        //int num = stoi(number);
        if (name == temp)
        {
            *num = *num + 1;
            file << temp << ':' << author << ':' << *num<< endl;
            //boolean variable turned false when book already exists
            flag = false;
            cout<<"The book already exists the number has been updated"<<endl;
        }
        file.close();
        delete [] num;

    }
    fhandle.close();

    //temporary file has been used to add the new book
    ofstream file("temp.txt", ios::out | ios::app);

    //if book is not already in the file it is added
    if (flag)
    {
        string author1;
        cout << "Enter the name of the author" << endl;
        getline(cin,author1);
        //throws an exception if enter is pressed without any input
        try{
            if(author1.length() == 0 )
                throw 1;
        }
        catch (int a) {
            cout<<"Incorrect input"<<endl;
            return;
        }

        //lowercase to upercase
        transform(author1.begin(), author1.end(), author1.begin(), ::toupper);

        cout<<"The book has been added"<<endl;
        file << name << ':' << author1 << ':' << '1'<< endl;
    }
    fstream fin("Books.txt", ios::in);

    //the rest of the books in the Books.txt file are written to the temp file
    while (getline(fin, temp, ':') && getline(fin, author, ':') && getline(fin, number) )
    {
        if (name == temp)
        {
            continue;
        }
        file << temp << ':' << author << ':' << number<<endl;
    }
    fin.close();
    file.close();


    //the books.txt file is removed after transferring its contents to the temp file and
    // then the temp file is renamed as Books.txt
    remove("Books.txt");
    rename("temp.txt","Books.txt");

}



//Admin is asked for the username of the member he wants to remove
//if user is found he/she is removed and else error message is displayed
void Admin::RemoveMember()
{


    string name,temp,password;
    cout<<"Enter the name of the member to be removed"<<endl;
    cin>>name;
    fstream fhandle("Login.txt", ios::in);
    bool flag = true;
    while (getline(fhandle,temp,' ') && getline(fhandle,password))
    {
        //Temporary file is used to store the modified data
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


    //the Login.txt file is removed after transferring its contents to the temp file and
    // then the temp file is renamed as Login.txt
    remove("Login.txt");
    rename("temp.txt","Login.txt");

}



//Admin can view the requests for new books to be added by the members
void Admin::ViewRequests()
{
    string name,author;
    int count = 1;
    ifstream fhandle("Requests.txt",ios::in);
    while( getline(fhandle,name,':') && getline(fhandle,author))
    {
        cout<<count<<'.';
        cout<<"Name: "<<name<<endl;
        cout<<"  By:   "<<author<<endl;
        count++;
    }
}



//Admin can view the records as to which member had borrowed which book
void Admin::ViewRecords()
{
    string username,name,date;
    int count = 1;
    fstream fhandle("Records.txt",ios::in);
    while(getline(fhandle,username,' ')&& getline(fhandle,name,':') && getline(fhandle,date))
    {
        cout<<count<<'.'<<username<<endl;
        cout<<"  "<<name<<endl;
        cout<<"Date of return:"<<date<<endl;
        cout<<endl;
        count++;
    }
    fhandle.close();
}


//Displays the List of cuurernt Library members
void Admin::memberlist()
{
    string username, password;
    int count =1;
    fstream fhandle("Login.txt",ios::in);
    while(getline(fhandle,username,' ') && getline(fhandle,password))
    {
        cout<<count<<'.'<<username<<endl;
        cout<<endl;
        count++;


    }
    fhandle.close();
}


