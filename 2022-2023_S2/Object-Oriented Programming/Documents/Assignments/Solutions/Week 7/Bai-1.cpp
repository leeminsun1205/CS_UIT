#include <bits/stdc++.h>
using namespace std;

// Định nghĩa nhân viên
class NhanVien
{
    private:
        string ho_ten, ngay_sinh;
        int luong;
    public:
        // Hàm tạo và hàm hủy
        NhanVien(){
            this->ho_ten="";
            this->ngay_sinh="";
            this->luong=0;
        };
        ~NhanVien(){};
        // Hàm nhập và xuất
        virtual void nhapNV();
        virtual void xuatNV();
        // Hàm khác
        virtual int tinhLuong()=0;
};
void NhanVien::nhapNV()
{
    cout << "Nhap ten NV:\n";
    getline(cin,this->ho_ten);
    cout << "Nhap ngay sinh NV:\n";
    cin >> this->ngay_sinh;
}
void NhanVien::xuatNV()
{
    cout << "Ten: " << this->ho_ten << " | ";
    cout << "Ngay sinh: " << this->ngay_sinh << " | ";
}
// Định nghĩa nhân viên sản xuất
class NhanVienSX : public NhanVien
{
    private:
        int luong_CB;
        int so_SP;
    public:
    // Hàm tạo và hàm hủy
    NhanVienSX():NhanVien(){
        this->luong_CB=0;
        this->so_SP=0;
    };
    ~NhanVienSX(){};
    // Hàm nhập và xuất
    void nhapNV();
    void xuatNV();
    // Hàm khác
    int tinhLuong(){
        return this->luong_CB+this->so_SP*5000;
    }
};
void NhanVienSX::nhapNV()
{
    NhanVien::nhapNV();
    cout << "Nhap luong can ban:\n";
    cin >> this->luong_CB;
    cout << "Nhap so san pham:\n";
    cin >> this->so_SP;
}
void NhanVienSX::xuatNV()
{
    NhanVien::xuatNV();
    cout << "Luong: " << tinhLuong() << endl;
}
//Định nghĩa nhân viên văn phòng
class NhanVienVP : public NhanVien
{
    private:
        int so_ngay_LV;
    public:
    // Hàm tạo và hàm hủy
    NhanVienVP():NhanVien(){
        this->so_ngay_LV=0;
    };
    ~NhanVienVP(){};
    // Hàm nhập và hàm xuất
    void nhapNV();
    void xuatNV();
    int tinhLuong(){
        return this->so_ngay_LV*100000;
    }
};
void NhanVienVP::nhapNV()
{
    NhanVien::nhapNV();
    cout << "Nhap so ngay lam viec:\n";
    cin >> this->so_ngay_LV;
}
void NhanVienVP::xuatNV()
{
    NhanVien::xuatNV();
    cout << "Luong: " << tinhLuong() << endl;
}
//Quản lý nhân viên trong công ty
class QuanLy
{
    private:
        int so_luong_NV;
        NhanVien **NV;
    public:
    // hàm tạo và hàm hủy
    QuanLy(){};
    ~QuanLy(){};
    // hàm nhập xuất
    void nhapNV() {
        int loaiNV;
        cout << "Nhap so luong nhan vien: \n";
        cin >> this->so_luong_NV;
        NV = new NhanVien*[so_luong_NV];
        cout << "-Neu la nhan vien van phong thi nhap 0\n";
        cout << "-Neu la nhan vien san xuat thi nhap 1\n";
        for (int i=1; i<=so_luong_NV; i++)
        {
            cout << "Moi nhap nhan vien thu " << i << endl;
            cout << "Nhap loai nhan vien:\n";
            //Nếu là nhân viên văn phòng thì nhập 0, nếu là nhân viên sản xuất thì nhập 1
            cin >> loaiNV;
            cin.ignore();
            if (loaiNV==0)
            {
                NV[i]=new NhanVienVP();
                NV[i]->nhapNV();
            }
            else
            {
                NV[i]=new NhanVienSX();
                NV[i]->nhapNV();
            }
        }
    }
    void xuatNV(){
        cout << "Danh sach bao gom:\n";
        for (int i=1; i<=so_luong_NV; i++)
            NV[i]->xuatNV();
    }

};

int main()
{
    QuanLy cong_ty;
    cong_ty.nhapNV();
    cong_ty.xuatNV();
    return 0;
}