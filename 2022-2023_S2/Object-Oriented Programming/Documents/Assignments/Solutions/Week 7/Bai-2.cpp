#include <bits/stdc++.h>
using namespace std;
//Định nghĩa con người
class ConNguoi
{
    private:
        string ho_ten, ngay_sinh, noi_o, gioi_tinh;
    public:
    // hàm tạo và hủy
    ConNguoi(){
        ho_ten="";
        ngay_sinh="";
        noi_o="";
        gioi_tinh="";
    };
    ~ConNguoi(){};
    // hàm nhập và xuất
    virtual void nhap(){
        cin.ignore();
        cout << "Nhap ho va ten: ";
        getline(cin,ho_ten);
        cout << "Nhap ngay sinh: ";
        getline(cin,ngay_sinh);
        cout << "Nhap noi o: ";
        getline(cin,noi_o);
        cout << "Nhap gioi tinh: ";
        getline(cin,gioi_tinh);
    }
    virtual void xuat(){
        cout << "Ten: " << ho_ten << " | ";
        cout << "Ngay sinh: " << ngay_sinh << " | ";
        cout << "Noi o: " << noi_o << " | ";
        cout << "Gioi tinh: " << gioi_tinh  << " | ";
    }
};
//Định nghĩa sinh viên
class SinhVien : public ConNguoi
{
    private:
        int nam_hoc, nien_khoa;
        string ten_truong, nganh_hoc;
    public:
    // hàm tạo và hủy
    SinhVien():ConNguoi(){
        nam_hoc=0;
        nien_khoa=0;
    };
    ~SinhVien(){};
    // hàm nhập và xuất
    void nhap()
    {
        ConNguoi::nhap();
        cout << "Nhap nam hoc: ";
        cin >> nam_hoc;
        cout << "Nhap nien khoa: ";
        cin >> nien_khoa;
        cin.ignore();
        cout << "Nhap ten truong: ";
        getline(cin,ten_truong);
        cout << "Nhap nganh_hoc: ";
        getline(cin,nganh_hoc);
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Nam hoc: " << nam_hoc << " | ";
        cout << "Nien khoa: " << nien_khoa << " | ";
        cout << "Ten truong: " << ten_truong << " | ";
        cout << "Nganh hoc: " << nganh_hoc;
    }
};
//Định nghĩa học sinh
class HocSinh : public ConNguoi
{
    private:
        string ten_truong;
        int lop;
    public:
    // hàm tạo và hủy
    HocSinh():ConNguoi(){
        ten_truong="";
        lop=0;
    };
    ~HocSinh(){};
    // hàm nhập và xuất
    void nhap(){
        ConNguoi::nhap();
        cout << "Nhap ten truong: ";
        getline(cin,ten_truong);
        cout << "Nhap lop: ";
        cin >> lop;
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Ten truong: "  << ten_truong << " | ";
        cout << "Lop: " << lop;
    }
};
//Định nghĩa công nhân
class CongNhan : public ConNguoi
{
    private:
        string noi_LV;
        int luong;
    public:
    // hàm tạo và hủy
    CongNhan():ConNguoi(){
        noi_LV="";
        luong=0;
    };
    ~CongNhan(){};
    // hàm nhập và xuất
    void nhap(){
        ConNguoi::nhap();
        cout << "Nhap noi lam viec: ";
        getline(cin,noi_LV);
        cout << "Nhap muc luong: ";
        cin >> luong;
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Noi lam viec: " << noi_LV << " | ";
        cout << "Muc luong: " << luong;
    }
};
//Định nghĩa nghệ sĩ
class NgheSi : public ConNguoi
{
    private:
        string nghe_danh, linh_vuc;
    public:
    // hàm tạo và hủy
    NgheSi():ConNguoi(){
        nghe_danh="";
        linh_vuc="";
    };
    ~NgheSi(){};
    // hàm nhập và xuất
    void nhap(){
        ConNguoi::nhap();
        cout << "Nhap nghe danh: ";
        getline(cin,nghe_danh);
        cout << "Nhap linh vuc: ";
        getline(cin,linh_vuc);
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Nghe danh: " << nghe_danh << " | ";
        cout << "Linh vuc: " << linh_vuc;
    }
};
//Định nghĩa ca sĩ
class CaSi : public ConNguoi
{
    private:
        string nghe_danh, linh_vuc;
    public:
    // hàm tạo và hủy
    CaSi():ConNguoi(){
        nghe_danh="";
        linh_vuc="";
    };
    ~CaSi(){};
    // hàm nhập và xuất
    void nhap(){
        ConNguoi::nhap();
        cout << "Nhap nghe danh: ";
        getline(cin,nghe_danh);
        cout << "Nhap linh vuc: ";
        getline(cin,linh_vuc);
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Nghe danh: " << nghe_danh << " | ";
        cout << "Linh vuc: " << linh_vuc;
    }
};
// Lớp nhập xuất thông tin đối tượng
class ThongTin
{
    private:
        int lua_chon;
        ConNguoi *CN;
    public:
        // hàm tạo và hủy
        ThongTin(){
            lua_chon=0;
        }
        ~ThongTin(){};
        // hàm nhập và xuất
        void nhap(){
            cout << "-Neu la sinh vien thi nhap 1\n";
            cout << "-Neu la hoc sinh thi nhap 2\n";
            cout << "-Neu la cong nhan thi nhap 3\n";
            cout << "-Neu la nghe si thi nhap 4\n";
            cout << "-Neu la ca si thi nhap 5\n";
            cout << "Nhap lua chon: ";
            cin >> lua_chon;
            if (lua_chon==1)
            {
                CN=new SinhVien();
                CN->nhap();
            }
            else if (lua_chon==2)
            {
                CN=new HocSinh();
                CN->nhap();
            }
            else if (lua_chon==3)
            {
                CN=new CongNhan();
                CN->nhap();
            }
            else if (lua_chon==4)
            {
               CN=new NgheSi();
                CN->nhap();
            }
            else 
            {
                CN=new CaSi();
                CN->nhap();
            }
        }
        void xuat()
        {
            CN->xuat();
        }
};

int main()
{
    ThongTin TT;
    TT.nhap();
    TT.xuat();
    return 0;
}