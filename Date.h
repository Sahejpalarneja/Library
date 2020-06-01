#ifndef DATE_H
#define DATE_H

#include<iostream>

class Date
{
    public:
        int day;
        int month;
        Date(int day,int month);
        Date Extend(Date &d);
        Date(const Date &d);
        void display();

};

#endif // DATE_H
