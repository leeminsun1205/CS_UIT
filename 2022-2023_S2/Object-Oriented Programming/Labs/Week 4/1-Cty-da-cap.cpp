#include <bits/stdc++.h>
using namespace std;
static int tong_SP=0;
static int tong_SNLV=0;
class NhanVien
{
    private:
        string ho_ten;
        float luong;
    public:
        NhanVien(){
            this->ho_ten="";
            this->luong=0;
        };
        ~NhanVien(){};
        virtual void nhapNV()
        {
            cin >> this->ho_ten;
        }
        void xuatNV()
        {
            cout << this->ho_ten << ": " << this->luong << endl;
        }
        void setLuong(float luong)
        {
            this->luong=luong;
        }
        virtual void tinhLuong()=0;
};
class NhanVienSX : public NhanVien
{
    private:
        float luong_CB;
        int so_SP;
    public:
        NhanVienSX():NhanVien(){
            this->luong_CB=0;
            this->so_SP=0;
        };
        ~NhanVienSX(){};
        void nhapNV()
        {
            NhanVien::nhapNV();
            cin >> this->luong_CB >> this->so_SP;
            tong_SP+=so_SP;
        }
        void tinhLuong(){
            setLuong(this->luong_CB+this->so_SP*5);
        }
};
class NhanVienVP : public NhanVien
{
    private:
        int so_ngay_LV;
    public:
        NhanVienVP():NhanVien(){
            this->so_ngay_LV=0;
        };
        ~NhanVienVP(){};
        void nhapNV()
        {
            NhanVien::nhapNV();
            cin >> this->so_ngay_LV;
            tong_SNLV+=so_ngay_LV;
        }
        void tinhLuong(){
        setLuong(this->so_ngay_LV*100);
        }
};
class Sep : public NhanVien
{
    public:
        Sep():NhanVien(){}
        ~Sep(){}
        void tinhLuong(){
            setLuong(100+tong_SP*2+tong_SNLV*40);
        }
};
void danhSachNhanVien(NhanVien** nhan_vien, int n)
{
    int loaiNV;
    nhan_vien=new NhanVien*[n];
    for (int i=0; i<n; i++)
    {
        cin >> loaiNV;
        if (loaiNV==1)
        {
            nhan_vien[i]=new NhanVienSX;
            nhan_vien[i]->nhapNV();
            nhan_vien[i]->tinhLuong();
        }
        else if (loaiNV==2)
        {
            nhan_vien[i]=new NhanVienVP;
            nhan_vien[i]->nhapNV();
            nhan_vien[i]->tinhLuong();
        }
        else if (loaiNV==3)
        {
            nhan_vien[i]=new Sep;
            nhan_vien[i]->nhapNV();
            nhan_vien[i]->tinhLuong();
        }
    }
    for (int i=0; i<n; i++)
        nhan_vien[i]->xuatNV();
}
int main()
{
    int n;
    cin >> n;
    NhanVien** nhan_vien;
    danhSachNhanVien(nhan_vien,n);
    return 0;
}