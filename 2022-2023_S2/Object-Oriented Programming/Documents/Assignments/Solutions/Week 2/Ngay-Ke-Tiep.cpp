#include <bits/stdc++.h>
using namespace std;
struct Date
{
    int day,month,year;
};
bool leapYear(int year); // hàm kiểm tra năm nhuận
void input(Date &date); // nhập ngày tháng năm
void nextDay(Date date); // hàm in ra ngày kế tiếp
int main()
{
    Date date;
    input(date);
    cout << "Ngay hien tai la: " << date.day << "/" << date.month << "/" << date.year << endl;
    nextDay(date);
    return 0;
}
bool leapYear(int year)
{
    if (year%100!=0 && year%4==0 || year%400==0) return true;
    return false;
}
void input(Date &date)
{   
    cout << "Nhap nam: ";
    cin >> date.year; 
    while (1)
    {
        cout << "Nhap thang: ";
        cin >> date.month;
        if (1<=date.month && date.month<=12)  break;
        else cout << "Thang khong hop le! Moi nhap lai.";
        cout << endl;
    }
    while(1)
    {
        cout << "Nhap ngay: ";
        cin >> date.day;
        if (date.month==1 || date.month==3 || date.month==5 || date.month==7 || date.month==8 || date.month==10 || date.month==12)
            if (1<=date.day && date.day<=31) 
                break;
            else cout << "Ngay khong hop le! Moi nhap lai.";
        else if (date.month==4 || date.month==6 || date.month==9 || date.month==11)
            if (1<=date.day && date.day<=30) 
                break;
            else cout << "Ngay khong hop le! Moi nhap lai.";
        else{
            // Nếu năm nhuận thì tháng 2 có 29 ngày, không phải năm nhuận thì tháng 2 chỉ có 28 ngày
            if (leapYear(date.year) && 1<=date.day && date.day<=29 || !leapYear(date.year && 1<=date.day && date.day<=28)) 
                break;
            else cout << "Ngay khong hop le! Moi nhap lai.";
        }
        cout << endl;
    }
}
void nextDay(Date date)
{
    cout << "Ngay ke tiep la: ";
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