#include <bits/stdc++.h>
using namespace std;
class DongHo
{
    private:
        int hours, minutes, seconds;
    public:
        DongHo(){
            int hours=0;
            int minutes=0;
            int seconds=0;
        };
        ~DongHo(){};
        friend istream &operator >> (istream &in, DongHo& A)
        {
            in >> A.hours >> A.minutes >> A.seconds;
            A.hours=abs(A.hours);
            A.minutes=abs(A.minutes);
            A.seconds=abs(A.seconds);
            A.hours=A.hours%24;
            A.minutes=A.minutes%60;
            A.seconds=A.seconds%60;
            return in;
        }
        friend ostream &operator << (ostream &out, DongHo A)
        {
            cout << A.hours << " " << A.minutes << " " << A.seconds;
            return out;
        } 
        DongHo operator ++ ()
        {
            if (this->seconds<59) this->seconds++;
            else {       
                this->seconds=0;
                if (this->minutes<59) this->minutes++;
                else 
                {
                    this->minutes=0;
                    this->hours++;
                }
            }
            if (this->hours==24) this->hours=0;
            return DongHo();
        }
        DongHo operator -- ()
        {
            if (this->seconds>0) this->seconds--;
            else {       
                this->seconds=59;
                if (this->minutes>0) this->minutes--;
                else 
                {
                    this->minutes=59;
                    this->hours--;
                }
            }
            if (this->hours==-1) this->hours=23;
            return DongHo();
        }
        DongHo operator + (int x)
        {
            DongHo A;
            if(x>=0){
                A.hours=x/3600;
                A.minutes=x%3600/60;
                A.seconds=x%3600%60;
                if (this->seconds+A.seconds>59)
                {
                    A.seconds=(this->seconds+A.seconds)-60;
                    A.minutes++;
                }
                else A.seconds=(this->seconds+A.seconds);
                if (this->minutes+A.minutes>59)
                {
                    A.minutes=(this->minutes+A.minutes)-60;
                    A.hours++;
                }
                else A.minutes=(this->minutes+A.minutes);
                A.hours=this->hours+A.hours;
                if (A.hours>=24) A.hours=A.hours%24;
                }
            else
            {
                A.hours=abs(x)/3600;
                A.minutes=abs(x)%3600/60;
                A.seconds=abs(x)%3600%60;
                if (this->seconds<A.seconds)
                {
                    A.seconds=(this->seconds-A.seconds)+60;
                    A.minutes++;
                }
                else A.seconds=(this->seconds-A.seconds);
                if (this->minutes<A.minutes)
                {
                    A.minutes=(this->minutes-A.minutes)+60;
                    A.hours++;
                }
                else A.minutes=(this->minutes-A.minutes);
                A.hours=this->hours-A.hours;
                if (A.hours<0) A.hours+=24;
            }
            return A;
        }
        DongHo operator - (int x)
        {
            DongHo A;
            
            if (x>=0){
                A.hours=x/3600;
                A.minutes=x%3600/60;
                A.seconds=x%3600%60;
                if (this->seconds<A.seconds)
                {
                    A.seconds=(this->seconds-A.seconds)+60;
                    A.minutes++;
                }
                else A.seconds=(this->seconds-A.seconds);
                if (this->minutes<A.minutes)
                {
                    A.minutes=(this->minutes-A.minutes)+60;
                    A.hours++;
                }
                else A.minutes=(this->minutes-A.minutes);
                A.hours=this->hours-A.hours;
                if (A.hours<0) A.hours+=24;
            }
            else{
                A.hours=abs(x)/3600;
                A.minutes=abs(x)%3600/60;
                A.seconds=abs(x)%3600%60;
                if (this->seconds+A.seconds>59)
                {
                    A.seconds=(this->seconds+A.seconds)-60;
                    A.minutes++;
                }
                else A.seconds=(this->seconds+A.seconds);
                if (this->minutes+A.minutes>59)
                {
                    A.minutes=(this->minutes+A.minutes)-60;
                    A.hours++;
                }
                else A.minutes=(this->minutes+A.minutes);
                A.hours=this->hours+A.hours;
                if (A.hours>=24) A.hours=A.hours%24;
            }
            return A;
        }
};
int main()
{
    DongHo clock;
    cin >> clock;
    int n; cin >> n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        if (s=="++") ++clock;
        if (s=="--") --clock;
        if (s=="+")
        {
            int x;
            cin >> x;
            clock=clock+x;
        }
        if (s=="-")
        {
            int x;
            cin >> x;
            clock=clock-x;
        }
    }
    cout << clock;
    return 0;
}