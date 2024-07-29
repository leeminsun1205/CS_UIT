#include <bits/stdc++.h>
using namespace std;
class ConNguoi
{
    private:
        string ho_ten, ngay_sinh, noi_o, gioi_tinh;
    public:
    ConNguoi(){
        ho_ten="";
        ngay_sinh="";
        noi_o="";
        gioi_tinh="";
    };
    ~ConNguoi(){};
    virtual void nhap(){
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

class SinhVien : public ConNguoi
{
    private:
        int nam_hoc, nien_khoa;
        string ten_truong, nganh_hoc;
    public:
    SinhVien():ConNguoi(){
        nam_hoc=0;
        nien_khoa=0;
    };
    ~SinhVien(){};
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
        cout << "Nhap nganh hoc: ";
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

class HocSinh : public ConNguoi
{
    private:
        string ten_truong;
        int lop;
    public:
    HocSinh():ConNguoi(){
        ten_truong="";
        lop=0;
    };
    ~HocSinh(){};
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

class CongNhan : public ConNguoi
{
    private:
        string noi_LV;
        int luong;
    public:
    CongNhan():ConNguoi(){
        noi_LV="";
        luong=0;
    };
    ~CongNhan(){};
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

class NgheSi : public ConNguoi
{
    private:
        string nghe_danh, linh_vuc;
    public:
    NgheSi():ConNguoi(){
        nghe_danh="";
        linh_vuc="";
    };
    ~NgheSi(){};
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

class CaSi : public ConNguoi
{
    private:
        string nghe_danh, linh_vuc;
    public:
    CaSi():ConNguoi(){
        nghe_danh="";
        linh_vuc="";
    };
    ~CaSi(){};
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

class DanhSach
{
    private:
        int so_luong;
        ConNguoi **CN;
    public:
        DanhSach(){
            so_luong=0;
        }
        ~DanhSach(){};
        void nhap(){
            cout << "Nhap so luong doi tuong trong danh sach:\n";
            cin >> so_luong;
            CN=new ConNguoi*[so_luong];
            int lua_chon;
            cout << "-Neu la sinh vien thi nhap 1\n";
            cout << "-Neu la hoc sinh thi nhap 2\n";
            cout << "-Neu la cong nhan thi nhap 3\n";
            cout << "-Neu la nghe si thi nhap 4\n";
            cout << "-Neu la ca si thi nhap 5\n";
            for (int i=1; i<=so_luong; i++)
            {    
                cout << "Moi nhap doi tuong thu " << i << endl;
                cout << "Nhap loai doi tuong: ";
                cin >> lua_chon;
                cin.ignore();
                if (lua_chon==1)
                {
                    CN[i]=new SinhVien();
                    CN[i]->nhap();
                }
                else if (lua_chon==2)
                {
                    CN[i]=new HocSinh();
                    CN[i]->nhap();
                }
                else if (lua_chon==3)
                {
                    CN[i]=new CongNhan();
                    CN[i]->nhap();
                }
                else if (lua_chon==4)
                {
                    CN[i]=new NgheSi();
                    CN[i]->nhap();
                }
                else 
                {
                    CN[i]=new CaSi();
                    CN[i]->nhap();
                }
            }
        }
        void xuat()
        {
            cout << "Danh sach bao gom:\n";
            for (int i=0; i<so_luong; i++)
            {
                CN[i]->xuat();
                cout << endl;
            }
        }
};

int main()
{
    DanhSach DS;
    DS.nhap();
    DS.xuat();
    return 0;
}