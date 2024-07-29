#include <bits/stdc++.h>
using namespace std;
class CDate
{
    private:
        int days, months, years;
    public:
        CDate(){
            this->days=0;
            this->months=0;
            this->years=0;
        }
        ~CDate(){};
        void nhap();
        void xuat();
        void tangMotNgay();
        void giamMotNgay();
        void tangNhieuNgay(int);
        void giamNhieuNgay(int);
        int spaceTime(CDate);
        bool lonHon(CDate);
};
bool leapYear(int year)
{
    if (((year%100!=0) && (year%4==0)) || (year%400==0)) return 1;
    return 0;
}
int DayOfMonth(int month, int year)
{
    if (month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month ==9 || month ==11)
        return 30;
    else {
        if (leapYear(year)) return 29;
        else return 28;
    }
}
int DayOfYear(int year)
{
    if (leapYear(year)==1) return 366;
    return 365;
}
bool checkNgayHopLe(int day, int month, int year)
{
    if ((month == 1 || month == 3 || month ==5 || month ==7 || month ==8 || month == 10 || month == 12) && (0< day && day <=31))
        return 1;
    if ((month == 4 || month == 6 || month ==9 || month ==11) && (0<day && day<=30)) return 1;
    if (month==2)
    {
        if (leapYear(year) && 0<day && day<=29) return 1;
        else return 0;
        if (!leapYear(year) && 0<day && day<=28) return 1;
        else return 0;
    }
    return 0;
}
void CDate::nhap()
{
    while (1){
        cout << "Nhap ngay thang nam theo dinh dang d/m/y:" << endl;
        char c;
        cin >> this->days >> c >> this->months >> c >> this->years;
        if (checkNgayHopLe(days,months,years)) break;
        cout << "Ngay thang nam khong hop le! Moi nhap lai." << endl;
    }
}
void CDate::xuat()
{
    cout << this->days << "/" << this->months << "/" << this->years;
}
void CDate::tangMotNgay()
{
    if (this->days<DayOfMonth(months,years)) 
        this->days++;
    else{
        if (this->months!=12){
            this->days=1;
            this->months++;
        }
        else{
            this->days=1;
            this->months=1;
            this->years++;
        }
    }
}
void CDate::giamMotNgay()
{
    if (this->days>=2) 
        this->days--;
    else{
        if (this->months!=1){
            this->days=DayOfMonth(months-1,years);
            this->months--;
        }
        else{
            this->days=31;
            this->months=12;
            this->years--;
        }
    }
}
void CDate::tangNhieuNgay(int x)
{
    if (x>0){
        int DOM=DayOfMonth(months,years);
        int rest_of_month=DOM-days;
        if (x<=rest_of_month) days+=x;
        else{
            days=DOM;
            x=x-rest_of_month;
            int rest_of_year=0;
            for (int i=months+1; i<=12; i++)
                rest_of_year+=DayOfMonth(i,years);
            if (x<=rest_of_year)
            {
                while(x>=DayOfMonth(months+1, years))
                {
                    x-=DayOfMonth(months+1,years);
                    months++;
                }
                if (x==0) days=DayOfMonth(months,years);
                else {
                    days=x;
                    months++;
                }
            } 
            else 
            {
                x=x-rest_of_year;
                while (x>=DayOfYear(years+1))
                {
                    x-=DayOfYear(years+1);
                    years++;
                }
                if (x==0) {
                    days=31;
                    months=12;
                }
                else{
                    months=0;
                    years++;
                    while(x>=DayOfMonth(months+1, years))
                    {
                        x-=DayOfMonth(months+1,years);
                        months++;
                    }
                    if (x==0) days=DayOfMonth(months,years);
                    else {
                        days=x;
                        months++;
                    }
                }
            }      
        }
    }
    else
    {
        x=abs(x);
        if (x<days)
            days-=x;
        else {
            x=x-days;
            int rest_of_year=0;
            for (int i=1; i<=months-1; i++)
                rest_of_year+=DayOfMonth(i,years);
            if (x<rest_of_year)
            {
                while(x>=DayOfMonth(months-1, years))
                {
                    x-=DayOfMonth(months-1,years);
                    months--;
                }
                if (x==0) days=1;
                else {
                    days=DayOfMonth(months-1,years)-x;
                    months--;
                }
            }
            else 
            {
                x=x-rest_of_year;
                while (x>=DayOfYear(years-1))
                {
                    x-=DayOfYear(years-1);
                    years--;
                }
                if (x==0) {
                    days=1;
                    months=1;
                }
                else{
                    months=13;
                    while(x>=DayOfMonth(months-1, years))
                    {
                        x-=DayOfMonth(months-1,years);
                        months--;
                    }
                    if (x==0) days=1;
                    else {
                        days=DayOfMonth(months-1,years)-x;
                        months--;
                    }
                    years--;
                }
            }      
        }
    }
}
void CDate::giamNhieuNgay(int x)
{
    if (x>0){
        if (x<days)
            days-=x;
        else {
            x=x-days;
            int rest_of_year=0;
            for (int i=1; i<=months-1; i++)
                rest_of_year+=DayOfMonth(i,years);
            if (x<rest_of_year)
            {
                while(x>=DayOfMonth(months-1, years))
                {
                    x-=DayOfMonth(months-1,years);
                    months--;
                }
                if (x==0) days=1;
                else {
                    days=DayOfMonth(months-1,years)-x;
                    months--;
                }
            }
            else 
            {
                x=x-rest_of_year;
                while (x>=DayOfYear(years-1))
                {
                    x-=DayOfYear(years-1);
                    years--;
                }
                if (x==0) {
                    days=1;
                    months=1;
                }
                else{
                    months=13;
                    while(x>=DayOfMonth(months-1, years))
                    {
                        x-=DayOfMonth(months-1,years);
                        months--;
                    }
                    if (x==0) days=1;
                    else {
                        days=DayOfMonth(months-1,years)-x;
                        months--;
                    }
                    years--;
                }
            }      
        }
    }
    else
    {
        x=abs(x);
        int DOM=DayOfMonth(months,years);
        int rest_of_month=DOM-days;
        if (x<=rest_of_month) days+=x;
        else{
            days=DOM;
            x=x-rest_of_month;
            int rest_of_year=0;
            for (int i=months+1; i<=12; i++)
                rest_of_year+=DayOfMonth(i,years);
            if (x<=rest_of_year)
            {
                while(x>=DayOfMonth(months+1, years))
                {
                    x-=DayOfMonth(months+1,years);
                    months++;
                }
                if (x==0) days=DayOfMonth(months,years);
                else {
                    days=x;
                    months++;
                }
            } 
            else 
            {
                x=x-rest_of_year;
                while (x>=DayOfYear(years+1))
                {
                    x-=DayOfYear(years+1);
                    years++;
                }
                if (x==0) {
                    days=31;
                    months=12;
                }
                else{
                    months=0;
                    years++;
                    while(x>=DayOfMonth(months+1, years))
                    {
                        x-=DayOfMonth(months+1,years);
                        months++;
                    }
                    if (x==0) days=DayOfMonth(months,years);
                    else {
                        days=x;
                        months++;
                    }
                }
            }      
        }
    }
}
int CDate::spaceTime(CDate date)
{
    if (years==date.years)
    {
        int day1=0;
        if (months==1) day1+=days;
        else {
            for (int i=1; i<months; i++)
                day1+=DayOfMonth(i,years);
            day1+=days;
        }
        int day2=0;
        if (date.months==1) day2+=date.days;
        else {
            for (int i=1; i<date.months; i++)
                day2+=DayOfMonth(i,date.years);
            day2+=date.days;
        }
        return day2-day1;
    }
    else if (years<date.years)
    {
        int day1=0;
        if (months==12) day1+=31-days;
        else {
            for (int i=12; i>=months+1; i--)
                day1+=DayOfMonth(i,years);
            day1+=DayOfMonth(months,years)-days;
        }
        int day2=0;
        if (date.months==1) day2+=date.days;
        else {
            for (int i=1; i<date.months; i++)
                day2+=DayOfMonth(i,date.years);
            day2+=date.days;
        }
        int day3=0;
        for (int i=years+1; i<date.years; i++)
            day3+=DayOfYear(i);
        return day1+day2+day3;
    }
    return 0;
}
bool CDate::lonHon(CDate date)
{
    if (this->years>date.years) return 1;
    else if (this->years==date.years)
    {
        if (this->months>date.months) return 1;
        else if (this->months==date.months) 
        {
            if (this->days>=date.days) return 1;
            else return 0;
        }
    }
    return 0;
}
int main()
{
    CDate date1;
    date1.nhap();
    while (1)
    {
        int n; cin >> n;
        if (n==1)
        {
            date1.tangMotNgay();
            cout << "Ngay vua tang la: " << endl;
            date1.xuat();
        }
        else if (n==2)
        {
            date1.giamMotNgay();
            cout << "Ngay vua giam la: " << endl;
            date1.xuat();
        }
        else if (n==3)
        {
            int x;
            cin >> x;
            date1.tangNhieuNgay(x);
            cout << "Ngay vua tang la: " << endl;
            date1.xuat();
        }
        else if (n==4)
        {
            int x; 
            cin >> x;
            date1.giamNhieuNgay(x);
            cout << "Ngay vua giam la: " << endl;
            date1.xuat();
        }
        else if (n==5)
        {
            CDate date2;
            date2.nhap();
            cout << "Khoang cach giua 2 ngay la: ";
            if (date1.lonHon(date2))
                cout << date1.spaceTime(date2) << " ngay";
            else
                cout << date2.spaceTime(date1) << " ngay";
        }
        else if (n==0) break;
    }
    return 0;
}