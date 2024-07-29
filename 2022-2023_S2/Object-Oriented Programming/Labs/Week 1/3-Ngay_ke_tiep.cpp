#include <bits/stdc++.h>
using namespace std;
struct Date
{
    int day,month,year;
};
bool leapYear(int year)
{
    if (year%100!=0 && year%4==0 || year%400==0) return true;
    return false;
}
void input(Date &date)
{   
    
    cin >> date.day >> date.month >> date.year;
    
}
void nextDay(Date date)
{
    if (date.month==1 || date.month==3 || date.month==5 || date.month==7 || date.month==8 || date.month==10 || date.month==12)
        if (date.day<=30) 
            date.day++;
        else{
            if (date.month!=12){
                date.day=1;
                date.month++;
            }
            else{
                date.day=1;
                date.month=1;
                date.year++;
            }
        }
    else if (date.month==4 || date.month==6 || date.month==9 || date.month==11)
        if (date.day<=29) 
            date.day++;
        else{
            date.day=1;
            date.month++;
        }
    else{
        if (leapYear(date.year))
            if (date.day<=28) 
                date.day++;
            else {
                date.day=1;
                date.month=3;
            }
        else {
            if (date.day<=27) 
                date.day++;
            else{
                date.day=1;
                date.month=3;
            }
        }
    }
    cout << date.day << "/" << date.month << "/" << date.year;
}
int main()
{
    Date date;
    input(date);
    if (date.month<1 || date.month >12) cout << "ERROR";
    else
        if (date.month==1 || date.month==3 || date.month==5 || date.month==7 || date.month==8 || date.month==10 || date.month==12)
            if (1<=date.day && date.day<=31) 
                nextDay(date);
            else 
                cout << "ERROR";
        else if (date.month==4 || date.month==6 || date.month==9 || date.month==11)
            if (1<=date.day && date.day<=30) 
                nextDay(date);
            else
                cout << "ERROR";
        else
            if (leapYear(date.year) && 1<=date.day && date.day<=29 || !leapYear(date.year && 1<=date.day && date.day<=28)) 
                nextDay(date);
            else cout << "ERROR";
    return 0;
}
