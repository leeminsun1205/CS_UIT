#include "Elipse.h"
//Dinh nghia hinh elip
Elipse::Elipse(){
    truc_dai=0;
    truc_ngan=0;
}
Elipse::~Elipse(){};
void Elipse::nhap()
{
    cout << "Nhap truc dai: ";
    cin >> truc_dai;
    cout << "Nhap truc ngan: ";
    cin >> truc_ngan;
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
HinhTron::~HinhTron(){}
void HinhTron::nhap()
{
    cout << "Nhap ban kinh: ";
    cin >> ban_kinh;
}
void HinhTron::xuat()
{
    cout << "Hinh tron co ban kinh la: " << ban_kinh << endl;
}
//Danh sach hinh
DanhSach::DanhSach()
{
    so_luong=0;
}
DanhSach::~DanhSach(){}
void DanhSach::nhap()
{
    cout << "Moi nhap so luong hinh trong danh sach: ";
    cin >> so_luong;
    hinh=new Elipse*[so_luong];
    for (int i=1; i<=so_luong; i++)
    {
        int type;
        cout << "Moi nhap kieu hinh can them" << endl << "Neu la hinh tron thi nhap 0, neu la hinh elip thi nhap 1: ";
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