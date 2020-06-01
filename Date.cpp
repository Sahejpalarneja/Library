#include "Date.h"


//constructor
Date::Date(int date, int mon)
{
   this->day = date;
   this->month = mon;
}


//Copy Constructor
Date::Date(const Date &d)
{

    int day,month;
    this->day = d.day;
    this->month= d.month;

}



//Extends the date by 7 days
Date Date::Extend(Date &d)
{
    if(d.month == 1 || d.month == 3 ||d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month ==12)
    {
       for(int i=1;i<=7;i++)
       {

            if(d.day == 31)
            {
                d.day = 1;
                if(d.month == 12)
                    d.month = 1;
                else
                    d.month = d.month+1;
            }
            else
            {
                d.day = d.day+1;
            }
       }
    }
    else
    {
        for(int i = 1;i <= 7;i++)
        {
            if(d.day == 30)
            {
                d.day = 1;
                if(d.month == 12)
                   d.month = 1;
                else
                    d.month = d.month+1;
            }
            else
            {
                d.day = d.day + 1;
            }
        }
    }

    return d;
}

//Test function
void Date::display()
{
    std::cout<<this->day<<'/'<<this->month<<std::endl;
}
