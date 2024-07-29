#include <iostream>
#include <vector>
#include <map>
using namespace std;
class SanPham{
protected:
    int maSP;
    string tieuDe;
    long long giaBan;
public:
    SanPham(){}
    ~SanPham(){}
    virtual void Nhap(){
        cout << "Nhap ma san pham: ";
        cin >> maSP;
        cin.ignore();
        cout << "Nhap tieu de: ";
        getline(cin, tieuDe);
        cout << "Nhap gia ban: ";
        cin >> giaBan;
    }
    virtual void Xuat(){
        cout << "Ma san pham: " << maSP << endl;
        cout << "Tieu de: " << tieuDe << endl;
        cout << "Gia ban: " << giaBan << endl;
    }
    long long getGiaBan(){
        return giaBan;
    }
};
class TranhAnh : public SanPham{
private:
    float chieuCao, chieuRong;
    string tenHoaSi;
public:
    TranhAnh(){}
    ~TranhAnh(){}
    void Nhap(){
        SanPham::Nhap();
        cout << "Nhap chieu cao: ";
        cin >> chieuCao;
        cout << "Nhap chieu rong: ";
        cin >> chieuRong;
        cin.ignore();
        cout << "Nhap ten hoa si: ";
        getline(cin, tenHoaSi);
    }
    void Xuat(){
        SanPham::Xuat();
        cout << "Chieu cao: " << chieuCao << ", chieuRong: " << chieuRong << endl;
        cout << "Ten hoa si:" << tenHoaSi;
    }
};
class CD : public SanPham{
private:
    string tenCaSi;
    string tenDviSX;
public:
    CD(){}
    ~CD(){}
    void Nhap(){
        SanPham::Nhap();
        cin.ignore();
        cout << "Nhap ten ca si: ";
        cin >> tenCaSi;
        cout << "Nhap ten don vi san xuat: ";
        cin >> tenDviSX;
    }
    void Xuat(){
        SanPham::Xuat();
        cout << "Ten ca si: " << tenCaSi << endl;
        cout << "Ten don vi san xuat: " << tenDviSX << endl;
    }
};
class KhachHang{
public:
    int maKH;
    string tenKH;
    string SDT;
    KhachHang(){}
    ~KhachHang(){}
    void Nhap(){
        cout << "Nhap ma khach hang: ";
        cin >> maKH;
        cin.ignore();
        cout << "Nhap ten khach hang: ";
        getline(cin, tenKH);
        cout << "Nhap so dien thoai: ";
        cin >> SDT;
    }
    void Xuat(){
        cout << "Ma khach hang: " << maKH << endl;
        cout << "Ten khach hang: " << tenKH << endl;
        cout << "So dien thoai: " << SDT << endl;
    }
};
class HoaDon{
public:
    int maHD;
    KhachHang TTKH;
    string ngay;
    vector<SanPham*> SP;
    long long tongGia;
    HoaDon(){}
    ~HoaDon(){}
    void Nhap(){
        cout << "Nhap ma hoa don: ";
        cin >> maHD;
        cout << "Nhap thong tin khach hang: ";
        TTKH.Nhap();
        cout << "Nhap ngay lap hoa don: ";
        cin >> ngay;
        cout << "Nhap danh sach san pham: ";
        int luaChon;
        int i=0;
        while(1){
            cout << "Nhap lua chon: ";
            cin >> luaChon;
            if (luaChon==1){
                SP.push_back(new TranhAnh);
                SP[i++]->Nhap();
            }
            else if (luaChon==2){
                SP.push_back(new CD);
                SP[i++]->Nhap();
            }
            else if (luaChon==0){
                break;
            }
        }
        tongGia=0;
        for (int i=0; i<SP.size(); i++){
            tongGia+=SP[i]->getGiaBan();
        }
    }
    void Xuat(){
        cout << "Ma hoa don: " << maHD << endl;
        cout << "Thong tin khach hang: " << endl;
        TTKH.Xuat();
        cout << "Ngay lap hoa don: " << ngay << endl;
        cout << "Danh sach san pham: " << endl;
        for(int i=0; i<SP.size(); i++){
            SP[i]->Xuat();
        }
        cout << "Tong gia: " << tongGia << endl;
    }
};
int main(){
    int n;
    cin >> n;
    vector <HoaDon> cuaHang(n);
    for (int i=0; i<n; i++){
        cuaHang[i].Nhap();
    }
    for (int i=0; i<n; i++){
        cuaHang[i].Xuat();
    }
    cout << "Tong thu nhap cua cua hang la: ";
    int tongThuNhap=0;
    for (int i=0; i<n; i++){
        tongThuNhap+=cuaHang[i].tongGia;
    }
    cout << tongThuNhap;
    map <int, int> KhachHang;
    for (int i=0; i<cuaHang.size(); i++){
        KhachHang[cuaHang[i].TTKH.maKH]+=cuaHang[i].tongGia;
    }
    return 0;
}