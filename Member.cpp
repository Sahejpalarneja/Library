//
// Created by sahejpal on 4/6/20.
//

#include "Member.h"
#include <iostream>
#include<bits/stdc++.h>
#include"Date.h"//for Extend function
#include <string>
using namespace std;


//constructor
Member::Member(string username,string password)
{
    this->username = username;
    this->password = password;

}


//Record function is called whenever the user issues a book
//the username and the name of the book is store in the Records.txt file
void Member::Record(const string &username,  const string &name,int day, int month)
{
    fstream fhandle("Records.txt",ios::out|ios::app);
    fhandle<<username<<' '<<name<<':'<<day<<'/'<<month<<endl;
}


/*Member can Request the admin to add a new book
 * by entering the name of the book and the author*/
void Member::Request()
{

    string  name,author,temp,atemp;
    bool flag= false;
    cout<<"Enter the name of the book"<<endl;
    getline(cin.ignore(),name);
    try{
        if(name.length() == 0 )
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect input"<<endl;
        return;
    }
    cout<<"Enter the name of the author"<<endl;
    getline(cin,author);
    try{
        if(author.length() == 0 )
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect input"<<endl;
        return;
    }
    //lowercase to upercase
    transform(author.begin(), author.end(), author.begin(), ::toupper);
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    ifstream fhandle("Requests.txt",ios::in);
    while(getline(fhandle,temp,':') && getline(fhandle,atemp))
    {
        //if the request of the book already exists the flag is turned true
        if(temp == name && atemp == author)
        {
            flag = true;
            cout<<"Request has been registered,Thank You!!"<<endl;
        }
    }
    fhandle.close();

    //new Requests are written in the Requests.txt file
    fstream file("Requests.txt", ios::out | ios::app);
    if(!flag)
    {

        file<<name<<':'<<author<<endl;
        cout<<"Request has been Registered , Thank You!!"<<endl;
    }
    file.close();
}


/* Member can ask for the deatisl of a book
 * by entering the name,if the book is in the library system
 * the name, author and avialabilty to borrow will be show.
 * if the book is not in the library system the member can request for it*/
void Member::GetDetails() {
    string name, temp, author, number;
    bool flag = false;
    cout << "Enter the name of the book" << endl;
    getline(cin.ignore(), name);
    try{
        if(name.length() == 0 )
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect input"<<endl;
        return;
    }

    //lowercase to uppercase
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream fhandle("Books.txt", ios::in);
    while (fhandle) {
        getline(fhandle, temp, ':');
        getline(fhandle, author, ':');
        getline(fhandle, number);


        if (name == temp) {
            cout << name << endl;
            cout << "By: " << author << endl;
            //boolen variable turned to true when book found in system
            flag = true;
            int *num = new int;
            *num = stoi(number);
            if (*num > 0) {
                cout << "Available for Borrowing" << endl;
            } else {
                cout << "Not available for borrowing" << endl;
            }
            delete [] num;
        }

    }
    if (!flag) {
        char ch;
        cout << "Book not found" << endl;
        cout << "Press y to request the book" << endl;
        cout << "Press any other button to go back to the MENU" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            //Calls Request function
            Request();
        }
    }
}


/* The Member can change the assigned password
 * user has to enter their username,new password and repeat it
 * if passwords match and the username is present in the login ile the password is changed*/
void Member::ChangePassword()
{
    bool flag = true;
    string username,pass,newpass;


    cout << "Enter your Username" << endl;
    cin>>username;
    cout << "Enter your new password" << endl;
    cin>>pass;
    cout << "Enter New Password" << endl;
    cin>>newpass;
    fstream fhandle ("Login.txt", ios::in);
    string temp, temp2;

    //temporary file is used to write the edited data
    fstream file ("temp.txt", ios::out | ios::app);
    while (fhandle)
    {
        getline (fhandle, temp, ' ');
        getline (fhandle, temp2);
        if (username == temp)
        {
            if(pass == newpass) {
                file << username << ' ' << newpass << endl;
                cout << "Password has been updated" << endl;
                flag = false;
            } else
                cout<<"The Passwords Don't match"<<endl;
        }
    }
    if (flag) {
        cout << "User not found" << endl;
    }
    fhandle.close ();
    fstream fin ("Login.txt", ios::in);
    while ( getline (fin, temp, ' ') && getline (fin, temp2))
    {

        if (username == temp && !flag) {
            continue;
        }
        file << temp << ' ' << temp2 << endl;
    }
    fin.close ();
    file.close ();

    //the Login.txt file is removed after transferring its contents to the temp file and
    // then the temp file is renamed as Login.txt
    remove ("Login.txt");
    rename ("temp.txt", "Login.txt");

}



/* The Member is shown all of the books avaiable for borrowing,
 * upon enter the name the book is issued and the name of the user and the book is stored in the records
 * and the number of the book is reduced in the Book.txt file*/
void Member::Issue(string &username)
{
    string name, author, number;
    int count = 1;
    bool flag = true;
    fstream fhandle("Books.txt", ios::in);
    cout << "The Library currently has the following books available for borrowing" << endl;
    while (getline(fhandle, name, ':') && getline(fhandle, author, ':') && getline(fhandle, number))
    {
        int *num = new int;
        *num = stoi(number);
        if (*num > 0) {
            cout<<endl;
            cout <<count<<'.'<< name << endl;
            cout <<"By: " << author << endl;
            count++;
        }
        delete [] num;
    }
    fhandle.close();
    string temp;
    cout << "Enter the name of the book You want to borrow" << endl;
    getline(cin.ignore(),name);
    try{
        if(name.length() == 0 )
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect input"<<endl;
        return ;
    }
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    int day,month;
    cout<<"Please add the Date of return"<<endl;
    cout<<"Enter the day"<<endl;
    cin>>day;
    cout<<"Enter the month"<<endl;
    cin>>month;
     try{

        if(month>12)
            throw 1;
        if(month == 1 ||month == 3 ||month == 5 || month == 7 || month == 8 || month == 10 || month ==12)
        {
            if(day>31)
                throw 2;
        }
        else
        {
            if(day>30)
                throw 2;
        }
    }
    catch (int a) {

        if(a == 1)
        {
            cout<<"Wrong input for months"<<endl;
            return;
        }
        else
        {
            cout<<"Wrong intput for days"<<endl;
            return;
        }
    }

    fstream fin("Books.txt", ios::in);
    while (fin)
    {
        getline(fin, temp, ':');
        getline(fin, author, ':');
        getline(fin, number);


        //temporary file is used to store the edited data
        ofstream file("temp.txt", ios::out | ios::app);

        //converting string to int
        int *num = new int;
        *num = stoi(number);
        if (name == temp) {
            *num = *num - 1;
            file << temp << ':' << author << ':' << *num << endl;
            Record(username,name,day,month);
            cout << "The book has been successfully borrowed" << endl;
            flag = false;
        }
        file.close();
        delete [] num;
    }
    if(flag)
    {
        cout<<"Choice is not available"<<endl;
    }
    fin.close();
    ofstream file("temp.txt", ios::out | ios::app);
    fstream fh("Books.txt", ios::in);

    //rest of the data is being copied to the temp file
    while (getline(fh, temp, ':') && getline(fh, author, ':') && getline(fh, number) )
    {


        if (name == temp) {
            continue;
        }
        file << temp << ':' << author << ':' << number<< endl;
    }
    fh.close();
    file.close();

    //the books.txt file is removed after transferring its contents to the temp file and
    // then the temp file is renamed as Books.txt
    remove("Books.txt");
    rename("temp.txt", "Books.txt");
}


/*Member when wanting to return a book has to write the name of the book
 * if the book is in the system the number will be updated ,else
 * a new book will be added*/
void Member::Return()
{
    string name,author,temp,number;
    cout<<"Enter the name of the book you want to return"<<endl;
    getline(cin.ignore(),name);
    try{
        if(name.length() == 0)
            throw 1;
    }
    catch (int a) {
        cout<<"Incorrect Input"<<endl;
        return;
    }
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream fhandle("Books.txt", ios::in);
    bool flag = true;
    while (getline(fhandle, temp, ':') && getline(fhandle, author, ':') && getline(fhandle, number))
    {

        //temp file is used to write the edited data
        ofstream file("temp.txt", ios::out | ios::app);

        //string is converted to int
        int *num = new int;
        *num = stoi(number);

        if (name == temp)
        {
            *num = *num + 1;
            file << temp << ':' << author << ':' << *num << endl;
            flag = false;
            cout<<"The book has been returned successfully"<<endl;
        }
        file.close();
        delete [] num;

    }
    fhandle.close();
    ofstream file("temp.txt", ios::out | ios::app);

    //if book does not exist in the system
    if (flag)
    {
        string author1;
        cout << "Enter the name of the author" << endl;
        getline(cin,author1);
        try{
            if(author1.length() == 0)
                throw 1;
        }
        catch(int a)
        {
            cout<<"Incorrect input"<<endl;
            return;
        }
        transform(author1.begin(), author1.end(), author1.begin(), ::toupper);
        cout<<"The book has been returned successfully"<<endl;
        file << name << ':' << author1 << ':' << '1'<< endl;
    }
    fstream fin("Books.txt", ios::in);

    //rest of the file is written to temp.txt
    while (getline(fin, temp, ':') && getline(fin, author, ':') && getline(fin, number))
    {

        if (name == temp)
        {
            continue;
        }
        file << temp << ':' << author << ':' << number<< endl;
    }
    fin.close();
    file.close();

    //the books.txt file is removed after transferring its contents to the temp file and
    // then the temp file is renamed as Books.txt
    remove("Books.txt");
    rename("temp.txt","Books.txt");
}


/*Member can view all the books he/she has borrowed and the due date for each book */
void Member::LibraryCard(string username)
{
    int count=1;
    bool flag = false;
    fstream fhandle("Records.txt",ios::in);
    string temp,name,date;
    cout<<"Borowed Books:"<<endl;
    while(getline(fhandle,temp,' ') && getline(fhandle,name,':') && getline(fhandle,date))
    {
        if(username == temp)
        {
            cout<<count<< '.' <<name<<endl;
            cout<<"Date of return: "<<date<<endl;
            cout<<endl;
            count++;
            flag = true;
        }
    }
    if(!flag)
    {
        cout<<"You have no borrwed books"<<endl;
    }
}


/*Member ca extend the date of returning of a book fromthe ooks he/she has borrowed
 *the member has to input the name of the book whose due date he/she has to increase and the Extend function from the Date class
 adds 7 days as a default extention to the existing due date*/
void Member::DateExtend(string username)
{

    int count=1;
    bool flag = false;
    fstream fhandle("Records.txt",ios::in);
    string temp,name,date;
    cout<<"Borowed Books:"<<endl;
    while(getline(fhandle,temp,' ') && getline(fhandle,name,':') && getline(fhandle,date))
    {
        if(username == temp)
        {
            cout<<count<< '.' <<name<<endl;
            cout<<"Date of return: "<<date<<endl;
            cout<<endl;
            count++;
            flag = true;
        }
    }
    if(!flag)
    {
        cout<<"You have no borrwed books"<<endl;
        return;
    }
    fhandle.close();
    string t2,day,month;
    cout<<"Enter the name of the book whose return date you want to extend"<<endl;
    getline(cin.ignore(),name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    fstream file("Records.txt",ios::in);
    fstream fh("temp.txt",ios::app);
    while(getline(file,temp,' ') && getline(file,t2,':') && getline(file,day,'/') && getline(file,month))
    {
        //temp file to write edited date

        if(temp == username && name == t2)
        {
            //convertiing string to integer
            int da = stoi(day);
            int mon = stoi(month);

            //creating a date object
            Date d1(da,mon);
            //storing new date in another object
            Date d2 = d1.Extend(d1);
            //updating the new date
            fh<<temp<<' '<<t2<<':'<<d2.day<<'/'<<d2.month<<endl;
            d2.display();

            flag = false;
        }
        else
        {
            fh<<temp<<' '<<t2<<':'<<day<<'/'<<month<<endl;

        }
    }
    file.close();
    fh.close();
    if(flag)
    {
        cout<<"Book does not exist"<<endl;

    }
    else
    {
        cout<<"The date has been updated"<<endl;
        }

    //Removing the records file and renaming the temp file to take its place
    remove("Records.txt");
    rename("temp.txt","Records.txt");
}
