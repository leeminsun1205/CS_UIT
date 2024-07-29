#include <bits/stdc++.h>
using namespace std;
class Elipse
{
    private:
        double truc_dai;
        double truc_ngan;
    public:
        Elipse();
        Elipse(double, double);
        ~Elipse();
        virtual void nhap();
        virtual void xuat();
};

class HinhTron : public Elipse
{
    private:
        double ban_kinh;
    public:
        HinhTron();
        HinhTron(double);
        ~HinhTron();
        void getBanKinh();
        void nhap();
        void xuat();
};

class DanhSach
{
    private:
        int so_luong;
        Elipse **hinh;
    public:
        DanhSach();
        ~DanhSach();
        void nhap();
        void xuat();
};
using namespace std;
//Dinh nghia hinh elip
Elipse::Elipse(){
    truc_dai=0;
    truc_ngan=0;
}
Elipse::Elipse(double truc_dai, double truc_ngan)
{
    this->truc_dai=truc_dai;
    this->truc_ngan=truc_ngan;
}
Elipse::~Elipse(){};
void Elipse::nhap()
{
    while (1){
        cout << "Nhap truc dai:\n";
        cin >> truc_dai;
        cout << "Nhap truc ngan:\n";
        cin >> truc_ngan;
        if (truc_dai>=truc_ngan) break;
        cout << "Do dai 2 truc khong hop le, moi nhap lai!\n";
    }
}
void Elipse::xuat()
{
    cout << "Elip co truc dai la " << truc_dai;
    cout << " va truc ngan la " << truc_ngan << endl;
}
//Dinh nghia hinh tron 
HinhTron::HinhTron()
{
    ban_kinh=0;
}
HinhTron::HinhTron(double ban_kinh):Elipse(ban_kinh, ban_kinh)
{
    this->ban_kinh=ban_kinh;
}
HinhTron::~HinhTron(){}
void HinhTron::nhap()
{
    cout << "Nhap ban kinh:\n";
    cin >> ban_kinh;
}
void HinhTron::xuat()
{
    cout << "Hinh tron co ban kinh la " << ban_kinh << endl;
}
//Danh sach hinh
DanhSach::DanhSach()
{
    so_luong=0;
}
DanhSach::~DanhSach(){}
void DanhSach::nhap()
{
    cout << "Moi nhap so luong hinh tron va elip trong danh sach:\n";
    cin >> so_luong;
    cout << "Neu la hinh tron thi nhap 0.\n";
    cout << "Neu la hinh elip thi nhap 1.\n";
    hinh=new Elipse*[so_luong];
    for (int i=1; i<=so_luong; i++)
    {
        int type;
        cout << "Moi nhap kieu hinh can them:" << endl;
        cin >> type;
        if (type==0)
        {
            hinh[i]=new HinhTron();
            hinh[i]->nhap();
        }
        else
        {
            hinh[i]=new Elipse();
            hinh[i]->nhap();
        }
    }
}
void DanhSach::xuat()
{
    cout << "Danh sach bao gom:\n";
    for (int i=1; i<=so_luong; i++)
        hinh[i]->xuat();
}
int main()
{
    DanhSach hinh;
    hinh.nhap();
    hinh.xuat();
    return 0;
}