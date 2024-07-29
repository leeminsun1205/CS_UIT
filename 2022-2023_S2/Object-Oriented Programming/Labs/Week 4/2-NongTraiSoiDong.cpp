#include <bits/stdc++.h>
using namespace std;
class GiaSuc
{
    private:
        int sl_ban_dau;
        int sl_sau_sinh;
        int lit_sua;
    public:
        GiaSuc(){
            sl_ban_dau=0;
            sl_sau_sinh=0;
            lit_sua=0;
        }
        void nhapSLBD(){
            cin >> this->sl_ban_dau;
            sl_sau_sinh=sl_ban_dau;
        }
        int getSLBD(){
            return this->sl_ban_dau;
        }
        void setSLBD(int SLBD)
        {
            this->sl_ban_dau=SLBD;
        }
        void setLitSua(int lit_sua){
            this->lit_sua+=lit_sua;
        }
        int getCon()
        {
            return sl_ban_dau/2;
        }
        void sinhCon(){
            sl_sau_sinh=sl_sau_sinh+getCon();
        }
        virtual void choSua(){
            this->lit_sua=0;
        }
        virtual void xuat(){
            cout << sl_sau_sinh << "," << lit_sua << endl;
        }
};
class Bo : public GiaSuc
{
    public:
    void choSua(){
        for (int i=1; i<=getSLBD(); i++)
            setLitSua(10);
    }
    void xuat()
    {
        cout << "Bo: ";
        GiaSuc::xuat();
    }
};

class Cuu : public GiaSuc
{
    public:
    void choSua(){
        for (int i=1; i<=getSLBD(); i++)
            setLitSua(5);
    }
    void xuat()
    {
        cout << "Cuu: ";
        GiaSuc::xuat();
    }
}; 

class De : public GiaSuc
{
    public:
    void choSua(){
        for (int i=1; i<=getSLBD(); i++)
            setLitSua(8);
    }
    void xuat()
    {
        cout << "De: ";
        GiaSuc::xuat();
    }
};
class Tho : public GiaSuc{
    void xuat()
    {
        cout << "Tho: ";
        GiaSuc::xuat();
    }
};
void luotSinhSan(vector <GiaSuc*> &gia_suc, int n)
{
    int con_TT;
    int con1[100][100];
    int con2[100];
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<4; j++)
        {
            
            con_TT=gia_suc[j]->getSLBD();
            if (i>=5 && j<3)
            {
                con_TT+=con1[i-5][j];
            }
            if (i>=3 && j==3)
            {
                con_TT+=con2[i-3];
            }
            gia_suc[j]->setSLBD(con_TT);
            gia_suc[j]->choSua();
            gia_suc[j]->sinhCon();
            if (i<=n-4 && j<3)
            {
                con1[i-1][j]=gia_suc[j]->getCon();
            }
            if (i<=n-2 && j==3)
            {
                con2[i-1]=gia_suc[3]->getCon();
            }
        }
    }
}
int main()
{
    vector <GiaSuc*> gia_suc;
    gia_suc.push_back(new Bo);
    gia_suc.push_back(new Cuu);
    gia_suc.push_back(new De);
    gia_suc.push_back(new Tho);
    for (int i=0; i<4; i++)
    {
        gia_suc[i]->nhapSLBD();
    }
    int n; cin >> n;
    luotSinhSan(gia_suc,n);
    for (int i=0; i<4; i++)
        gia_suc[i]->xuat();
    return 0;
}