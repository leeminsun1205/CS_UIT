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
        friend istream &operator >> (istream & in, CDate&);
        void tangNgay(int);
        void giamNgay(int);
        int spaceTime(CDate);
        bool operator >= (CDate t2);
};
int leapYear(int year)
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
istream &operator >> (istream &in, CDate & another)
{
    cin >> another.days >> another.months >> another.years;
    another.days=abs(another.days);
    another.months=abs(another.months);
    another.years=abs(another.years);
    another.months=(another.months)%12;
    if (another.months == 0) another.months=12;
    if (another.days > DayOfMonth(another.months, another.years))
    {
        another.days=1;
    }
    return in;
}
void CDate::tangNgay(int x)
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
void CDate::giamNgay(int x)
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
int CDate::spaceTime(CDate t2)
{
    if (years==t2.years)
    {
        int day1=0;
        if (months==1) day1+=days;
        else {
            for (int i=1; i<months; i++)
                day1+=DayOfMonth(i,years);
            day1+=days;
        }
        int day2=0;
        if (t2.months==1) day2+=t2.days;
        else {
            for (int i=1; i<t2.months; i++)
                day2+=DayOfMonth(i,t2.years);
            day2+=t2.days;
        }
        return day2-day1;
    }
    else if (years<t2.years)
    {
        int day1=0;
        if (months==12) day1+=31-days;
        else {
            for (int i=12; i>=months+1; i--)
                day1+=DayOfMonth(i,years);
            day1+=DayOfMonth(months,years)-days;
        }
        int day2=0;
        if (t2.months==1) day2+=t2.days;
        else {
            for (int i=1; i<t2.months; i++)
                day2+=DayOfMonth(i,t2.years);
            day2+=t2.days;
        }
        int day3=0;
        for (int i=years+1; i<t2.years; i++)
            day3+=DayOfYear(i);
        return day1+day2+day3;
    }
    return 0;
}
bool CDate::operator >= (CDate t2)
{
    if (this->years>t2.years) return 1;
    else if (this->years==t2.years)
    {
        if (this->months>t2.months) return 1;
        else if (this->months==t2.months) 
        {
            if (this->days>=t2.days) return 1;
            else return 0;
        }
    }
    return 0;
};
int main()
{
    CDate t;
    cin >> t;
    while(1){
        int n; cin >> n;
        if (n==1){
            int x;
            cin >> x;
            t.tangNgay(x);
        }
        if (n==2){
            int x;
            cin >> x;
            t.giamNgay(x);
        }
        if (n==3)
        {
            CDate t2;
            cin >> t2;
            if (t>=t2)
                cout << t2.spaceTime(t);
            else 
                cout << t.spaceTime(t2);
            break;
        }
    }
    return 0;
}