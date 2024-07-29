#include <bits/stdc++.h>
using namespace std;
#define PI 3.14 
static float tong_DT=0;
static float tong_TT=0;
class Chai
{
    private: 
        float dien_tich;
        float the_tich;
    public:
        Chai()
        {
            dien_tich=0;
            the_tich=0;
        }
        ~Chai(){}
        virtual void nhap()=0;
        void setDienTich(float dien_tich)
        {
            this->dien_tich=dien_tich;
            tong_DT+=this->dien_tich;
        }
        void setTheTich(float the_tich)
        {
            this->the_tich=the_tich;
            tong_TT+=this->the_tich;
        }
        virtual void dienTich() = 0;
        virtual void theTich() = 0;
        void xuat()
        {
            cout << "Dien tich chai vo: " << dien_tich << endl;
            cout << "Luong nuoc tren mat dat: " << the_tich << endl;
        }
};
class TruTron : public Chai
{
    private:
        int chieu_cao;
        int BK_day;
    public:
        void nhap()
        {
            cin >> chieu_cao;
            cin >> BK_day;
        }
        void dienTich()
        {   
            setDienTich(2*PI*BK_day*chieu_cao);
        }
        void theTich()
        {
            setTheTich(PI*BK_day*BK_day*chieu_cao);
        }
};
class HopChuNhat : public Chai
{
    private:
        int chieu_cao;
        int chieu_dai;
        int chieu_rong;
    public:
        void nhap()
        {
            cin >> chieu_cao;
            cin >> chieu_dai;
            cin >> chieu_rong;
        }
        void dienTich()
        {
            setDienTich(2*(chieu_cao*chieu_dai+chieu_dai*chieu_rong+chieu_rong*chieu_cao));
        }
        void theTich()
        {
            setTheTich(chieu_cao*chieu_dai*chieu_rong);
        }
};
class LapPhuong : public Chai
{
    private:
        int canh;
    public:
        void nhap()
        {
            cin >> canh;
        }
        void dienTich()
        {
            setDienTich(6*canh*canh);
        }
        void theTich()
        {
            setTheTich(pow(canh,3));
        }
};
int main()
{
    int n; cin >> n;
    Chai** c=new Chai*[n];
    int lua_chon;
    for (int i=0; i<n; i++)
    {
        cin >> lua_chon;
        if (lua_chon==1)
        {
            c[i]=new TruTron;
            c[i]->nhap();
            c[i]->dienTich();
            c[i]->theTich();
        }
        if (lua_chon==2)
        {
            c[i]=new HopChuNhat;
            c[i]->nhap();
            c[i]->dienTich();
            c[i]->theTich();
        }
        if (lua_chon==3)
        {
            c[i]=new LapPhuong;
            c[i]->nhap();
            c[i]->dienTich();
            c[i]->theTich();
        }
    }
    cout << "Dien tich chai vo: " << tong_DT << endl;
    cout << "Luong nuoc tren mat dat: " << tong_TT/10 << endl;
}