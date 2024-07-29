#include <bits/stdc++.h>
using namespace std;
class CTimeSpan
{
    private:
        unsigned int lDays;
        short int nHours, nMinutes, nSeconds;
        static short int dem;
    public:
        CTimeSpan();
        ~CTimeSpan(){};
        void nhap();
        void xuat();
        CTimeSpan cong(const CTimeSpan) const;
        CTimeSpan tru(const CTimeSpan) const;
        bool nhoHon(const CTimeSpan) const;
        bool bang(const CTimeSpan) const;
        bool lonHon(const CTimeSpan) const;
        bool lonHonHoacBang(const CTimeSpan) const;
        bool nhoHonHoacBang(const CTimeSpan) const;
};
short int CTimeSpan::dem=0;
CTimeSpan::CTimeSpan()
{
    this->lDays=0;
    this->nHours=0;
    this->nMinutes=0;
    this->nSeconds=0;
}void CTimeSpan::nhap()
{
    dem++;
    while(1){
        cout << "- Nhap thoi gian t" << dem << " theo dinh dang _d,_h,_m,_s:" << endl;
        cin >> this->lDays >> this->nHours >>this->nMinutes >>this->nSeconds;
        if (this->nHours>=24 ||this->nMinutes>=60 ||this->nSeconds>=60)
            cout << "Thoi gian khong hop le moi nhap lai!" << endl;
        else break;
    }   
}
void CTimeSpan::xuat()
{
    cout << this->lDays << "d,";
    cout <<this->nHours << "h,";
    cout << setfill('0') << setw(2) << this->nMinutes << "m,";
    cout << setfill('0') << setw(2) << this->nSeconds << "s"; 
    cout << endl;
}
CTimeSpan CTimeSpan::cong(const CTimeSpan another) const {
    CTimeSpan Sum;
    Sum.nSeconds=this->nSeconds+another.nSeconds;
    Sum.nMinutes=this->nMinutes+another.nMinutes;
    Sum.nHours=this->nHours+another.nHours;
    Sum.lDays=this->lDays+another.lDays;
    if (Sum.nSeconds>=60) {
        Sum.nSeconds-=60;
        Sum.nMinutes++;
    }
    if (Sum.nMinutes>=60) {
        Sum.nMinutes-=60;
        Sum.nHours++;
    }
    if (Sum.nHours>=24)
    {
        Sum.nHours-=24;
        Sum.lDays++;
    }
    return Sum;
}
CTimeSpan CTimeSpan::tru(const CTimeSpan another) const {
    CTimeSpan Difference;
    Difference.nSeconds=this->nSeconds-another.nSeconds;
    Difference.nMinutes=this->nMinutes-another.nMinutes;
    Difference.nHours=this->nHours-another.nHours;
    Difference.lDays=this->lDays-another.lDays;
    if (this->nSeconds<another.nSeconds) {
        Difference.nSeconds+=60;
        Difference.nMinutes--;
    }
    if (this->nMinutes<another.nMinutes) {
        Difference.nMinutes+=60;
        Difference.nHours--;
    }
    if (this->nHours<another.nHours)
    {
        Difference.nHours+=24;
        Difference.lDays--;
    }
    return Difference;
}
bool CTimeSpan::bang(const CTimeSpan another) const {
    if (this->lDays != another.lDays) return 0;
    if (this->nHours != another.nHours) return 0;
    if (this->nMinutes != another.nMinutes) return 0;
    if (this->nSeconds != another.nSeconds) return 0;
    return 1;
}
bool CTimeSpan::lonHon(const CTimeSpan another) const {
    if (this->lDays > another.lDays) return 1;
    else if (this->lDays < another.lDays) return 0;
    else
        if (this->nHours > another.nHours) return 1;
        else if (this->nHours < another.nHours) return 0;
        else
            if (this->nMinutes > another.nMinutes) return 1;
            else if (this->nMinutes < another.nMinutes) return 0;
            else
                if (this->nSeconds > another.nSeconds) return 1;
                else if (this->nSeconds < another.nSeconds) return 0;
                else return 0;
}
bool CTimeSpan::nhoHon(const CTimeSpan another) const {
    if (this->lDays < another.lDays) return 1;
    else if (this->lDays > another.lDays) return 0;
    else
        if (this->nHours < another.nHours) return 1;
        else if (this->nHours > another.nHours) return 0;
        else
            if (this->nMinutes < another.nMinutes) return 1;
            else if (this->nMinutes > another.nMinutes) return 0;
            else
                if (this->nSeconds < another.nSeconds) return 1;
                else if (this->nSeconds > another.nSeconds) return 0;
                else return 0;
}
bool CTimeSpan::lonHonHoacBang(const CTimeSpan another) const {
    if (this->lDays > another.lDays) return 1;
    else if (this->lDays < another.lDays) return 0;
    else
        if (this->nHours > another.nHours) return 1;
        else if (this->nHours < another.nHours) return 0;
        else
            if (this->nMinutes > another.nMinutes) return 1;
            else if (this->nMinutes < another.nMinutes) return 0;
            else
                if (this->nSeconds > another.nSeconds) return 1;
                else if (this->nSeconds < another.nSeconds) return 0;
                else return 1;
}
bool CTimeSpan::nhoHonHoacBang(const CTimeSpan another) const {
    if (this->lDays < another.lDays) return 1;
    else if (this->lDays > another.lDays) return 0;
    else
        if (this->nHours < another.nHours) return 1;
        else if (this->nHours > another.nHours) return 0;
        else
            if (this->nMinutes < another.nMinutes) return 1;
            else if (this->nMinutes > another.nMinutes) return 0;
            else
                if (this->nSeconds < another.nSeconds) return 1;
                else if (this->nSeconds > another.nSeconds) return 0;
                else return 1;
}
int main()
{
    CTimeSpan t1,t2,sum,difference;
    t1.nhap(); t2.nhap();
    cout << "- Thoi gian t1 vua nhap la:\n";
    t1.xuat();
    cout << "- Thoi gian t2 vua nhap la:\n";
    t2.xuat();
    sum=t1.cong(t2);
    cout << "- t1 cong 2 la:\n";
    sum.xuat();
    if (t1.lonHon(t2)){
        difference=t1.tru(t2);
        cout << "- t1 tru t2 la:\n";
    }
    else{
        difference=t2.tru(t1);
        cout << "- t2 tru t1 la:\n";
    }
    difference.xuat();
    if (t1.bang(t2)) cout << "- t1 bang t2\n";
    else cout << "- t1 khong bang t2\n";
    if (t1.lonHon(t2)) cout << "- t1 lon hon t2\n";
    else cout << "- t1 khong lon hon t2\n";
    if (t1.nhoHon(t2)) cout << "- t1 nho hon t2\n";
    else cout << "- t1 khong nho hon t2\n";
    if (t1.lonHonHoacBang(t2)) cout << "- t1 lon hon hoac bang t2\n";
    else cout << "- t1 khong lon hon hoac bang t2\n";
    if (t1.nhoHonHoacBang(t2)) cout << "- t1 nho hon hoac bang t2\n";
    else cout << "- t1 khong nho hon hoac bang t2\n";
    return 0;
}