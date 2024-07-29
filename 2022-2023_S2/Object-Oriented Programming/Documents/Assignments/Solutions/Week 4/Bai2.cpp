#include <bits/stdc++.h>
using namespace std;
class CTime
{
    private:
        int hours, minutes, seconds; // khai báo biến giờ phút giây
    public:
        // hàm khởi tạo
        CTime(int hours, int minutes, int seconds){
            this->hours=hours;
            this->minutes=minutes;
            this->seconds=seconds;
        }
        // hàm khởi tạo
        CTime(){
            this->hours=0;
            this->minutes=0;
            this->seconds=0;
        };
        ~CTime(){}; // hàm hủy
        void nhap(); // nhập CTime
        void xuat(); // xuất CTime
        void tangGiay(); // tăng CTime thêm 1 giây
        void giamGiay(); // giảm CTime đi 1 giây
        void congGiay(int); // cộng thêm CTime 1 số nguyên giây
        void truGiay(int); // trừ đi CTime 1 số nguyên giây
        CTime truCTime(CTime); // tính thời gian giữ 2 CTime
};
void CTime::nhap()
{ 
    while(1)
    {
        char a;
        cout << "Nhap lan luot gio phut giay theo dinh dang H:M:S:\n";
        cin >> this->hours >> a >> this->minutes >> a >> this->seconds;
        if (0<=this->hours && this->hours<=23 && 
            0<=this->minutes && this->minutes <=59 &&
            0<=this->seconds && this->seconds <=59) break;
        else cout << "Thoi gian khong hop le, moi nhap lai!\n";
    }
}
void CTime::xuat()
{
    // Xuât CTime theo định dạng H:M:S;
    cout <<this->hours << ":";
    cout << setfill('0') << setw(2) << this->minutes << ":";
    cout << setfill('0') << setw(2) << this->seconds;
    cout << endl;
}
void CTime::tangGiay()
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
}
void CTime::giamGiay()
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
}
void CTime::congGiay(int x)
{
     if(x>=0){
        int Hours=x/3600;
        int Minutes=x%3600/60;
        int Seconds=x%3600%60;
        if (this->seconds+Seconds>59)
        {
            Seconds=(this->seconds+Seconds)-60;
            Minutes++;
        }
        else Seconds=(this->seconds+Seconds);
        if (this->minutes+Minutes>59)
        {
            Minutes=(this->minutes+Minutes)-60;
            Hours++;
        }
        else Minutes=(this->minutes+Minutes);
        Hours=this->hours+Hours;
        if (Hours>=24) Hours=Hours%24;
        this->seconds=Seconds;
        this->minutes=Minutes;
        this->hours=Hours;
    }
    else
    {
        int Hours=abs(x)/3600;
        int Minutes=abs(x)%3600/60;
        int Seconds=abs(x)%3600%60;
        if (this->seconds<Seconds)
        {
            Seconds=(this->seconds-Seconds)+60;
            Minutes++;
        }
        else Seconds=(this->seconds-Seconds);
        if (this->minutes<Minutes)
        {
            Minutes=(this->minutes-Minutes)+60;
            Hours++;
        }
        else Minutes=(this->minutes-Minutes);
        Hours=this->hours-Hours;
        if (Hours<0) Hours+=24;
        this->seconds=Seconds;
        this->minutes=Minutes;
        this->hours=Hours;
    }
}
void CTime::truGiay(int x)
{
    if (x>0)
    {
        int Hours=x/3600;
        int Minutes=x%3600/60;
        int Seconds=x%3600%60;
        if (this->seconds<Seconds)
        {
            Seconds=(this->seconds-Seconds)+60;
            Minutes++;
        }
        else Seconds=(this->seconds-Seconds);
        if (this->minutes<Minutes)
        {
            Minutes=(this->minutes-Minutes)+60;
            Hours++;
        }
        else Minutes=(this->minutes-Minutes);
        Hours=this->hours-Hours;
        if (Hours<0) Hours+=24;
        this->seconds=Seconds;
        this->minutes=Minutes;
        this->hours=Hours;
    }
    else
    {
        int Hours=abs(x)/3600;
        int Minutes=abs(x)%3600/60;
        int Seconds=abs(x)%3600%60;
        if (this->seconds+Seconds>59)
        {
            Seconds=(this->seconds+Seconds)-60;
            Minutes++;
        }
        else Seconds=(this->seconds+Seconds);
        if (this->minutes+Minutes>59)
        {
            Minutes=(this->minutes+Minutes)-60;
            Hours++;
        }
        else Minutes=(this->minutes+Minutes);
        Hours=this->hours+Hours;
        if (Hours>=24) Hours=Hours%24;
        this->seconds=Seconds;
        this->minutes=Minutes;
        this->hours=Hours;
    }
}
CTime CTime::truCTime(CTime t2)
{
    CTime t1;
    t1.seconds=t2.seconds;
    t1.minutes=t2.minutes;
    t1.hours=t2.hours;
    if (this->seconds<t1.seconds)
        {
            t1.seconds=(this->seconds-t1.seconds)+60;
            t1.minutes++;
        }
        else t1.seconds=(this->seconds-t1.seconds);
        if (this->minutes<t1.minutes)
        {
            t1.minutes=(this->minutes-t1.minutes)+60;
            t1.hours++;
        }
        else t1.minutes=(this->minutes-t1.minutes);
        t1.hours=this->hours-t1.hours;
        if (t1.hours<0) t1.hours+=24;
    return t1;
}
int main()
{
    CTime t1;
    t1.nhap();
    cout << "----------CHI-THI---------\n";
        cout << "-Neu n=1 tang thoi gian them 1 giay\n";
        cout << "-Neu n=2 giam thoi gian di 1 giay\n";
        cout << "-Neu n=3 cong thoi gian them x giay\n";
        cout << "-Neu n=4 tru thoi gian di x giay\n";
        cout << "-Neu n=5 tinh khoang thoi gian giua t1 va t2\n";
        cout << "-Neu n=0 ket thuc chuong trinh\n";
    while (1)
    {
        cout << "Moi nhap chi thi n: ";
        int n; cin >> n;
        if (n==1) 
        {
            t1.tangGiay();
            cout << "Thoi gian sau khi tang them 1 giay la:\n";
            t1.xuat();
        }
        else if (n==2)
        {
            t1.giamGiay();
            cout << "Thoi gian sau khi giam di 1 giay la:\n";
            t1.xuat();
        }
        else if (n==3)
        {
            int x;
            cout << "Nhap thoi gian x can tang: ";
            cin >> x;
            t1.congGiay(x);
            cout << "Thoi gian sau khi tang them " << x << " giay la:\n";
            t1.xuat();
        }
        else if (n==4)
        {
            int x; 
            cout << "Nhap thoi gian x can giam: ";
            cin >> x; 
            t1.truGiay(x);
            cout << "Thoi gian sau khi giam di " << x << " giay la:\n";
            t1.xuat();
        }
        else if (n==5)
        {
            CTime t2;
            t2.nhap();
            cout << "Khoang thoi gian giua t1 va t2 la:\n";
            t1.truCTime(t2).xuat();
        }
        else if (n==0){
            cout << "Chuong trinh ket thuc!";
            break;
        }
    }
}