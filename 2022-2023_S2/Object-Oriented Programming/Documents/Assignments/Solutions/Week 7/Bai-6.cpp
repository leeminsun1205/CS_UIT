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
    ~GiaSuc(){};
    virtual void nhapSoLuongBanDau()
    {
        cin >> this->sl_ban_dau;
        this->sl_sau_sinh=this->sl_ban_dau;
    }
    int getSoLuongBanDau()
    {
        return this->sl_ban_dau;
    }
    void soLuongSauSinh(int so_luong)
    {
        this->sl_sau_sinh+=so_luong;
    };
    int getSoLuongSauSinh()
    {
        return this->sl_sau_sinh;
    }
    void litSua(int lit_sua)
    {
        this->lit_sua+=lit_sua;
    }
    int getLitSua()
    {
        return this->lit_sua;
    }
    virtual void sinhCon()=0;
    virtual void choSua()=0;
    virtual void tiengKeu()=0;
};

class Bo : public GiaSuc
{
    public:
    void nhapSoLuongBanDau()
    {
        cout << "Nhap so luong BO ban dau:\n";
        GiaSuc::nhapSoLuongBanDau();
    }
    void sinhCon(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            soLuongSauSinh(rand()%2+1);
    }
    void choSua(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            litSua(rand()%21);
    }
    void tiengKeu(){
        cout << "Umm boooooo!" << endl;
    }
};

class Cuu : public GiaSuc
{
    public:
    void nhapSoLuongBanDau()
    {
        cout << "Nhap so luong CUU ban dau:\n";
        GiaSuc::nhapSoLuongBanDau();
    }
    void sinhCon(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            soLuongSauSinh(rand()%3+1);
    }
    void choSua(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            litSua(rand()%6);
    }
    void tiengKeu(){
        cout << "Meeeeeee!" << endl;
    }
}; 

class De : public GiaSuc
{
    public:
    void nhapSoLuongBanDau()
    {
        cout << "Nhap so luong DE ban dau:\n";
        GiaSuc::nhapSoLuongBanDau();
    }
    void sinhCon(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            soLuongSauSinh(rand()%3+1);
    }
    void choSua(){
        for (int i=1; i<=getSoLuongBanDau(); i++)
            litSua(rand()%11);
    }
    void tiengKeu(){
        cout << "Beeeeeee!" << endl;
    }
};
void tiengKeuDoi(){
    cout << "Nhung tieng keu nghe duoc trong nong trai la:\n";
    GiaSuc *bo=new Bo();
    bo->tiengKeu();
    GiaSuc *cuu=new Cuu();
    cuu->tiengKeu();
    GiaSuc *de=new De();
    de->tiengKeu();
}
void thongKe(){
    GiaSuc *bo=new Bo();
    bo->nhapSoLuongBanDau();
    GiaSuc *cuu=new Cuu();
    cuu->nhapSoLuongBanDau();
    GiaSuc *de=new De();
    de->nhapSoLuongBanDau();
    bo->sinhCon();
    cuu->sinhCon();
    de->sinhCon();
    cout << "-So luong BO sau mot lua sinh la: " << bo->getSoLuongSauSinh() << endl;
    cout << "-So luong CUU sau mot lua sinh la: " << cuu->getSoLuongSauSinh() << endl;
    cout << "-So luong DE sau mot lua sinh la: " << de->getSoLuongSauSinh() << endl;
    bo->choSua();
    cuu->choSua();
    de->choSua();
    cout << "-Tong so lit sua thu duoc la: " << bo->getLitSua()+de->getLitSua()+cuu->getLitSua();
}
int main()
{
    srand(time(NULL));
    tiengKeuDoi();
    thongKe();
    return 0;
}