#include <bits/stdc++.h>
using namespace std;
map<int, long double> tongCuoc; // tongCuoc({maPT,tongTienCuoc})
class Date{
        int ngay, thang, nam;
    public:
        friend istream & operator >> (istream &in, Date &date){
            char dauXet;
            in >> date.ngay >> dauXet >> date.thang >> dauXet >> date.nam;
            return in;
        }
        friend ostream & operator << (ostream &out, Date date){
            out << date.ngay << "/" << date.thang << "/" << date.nam;
            return out;
        }
};
class XeVanChuyen{
    protected:
        int maPT;
        int loaiXe;
        long double trongTai;
        string xuatXu;
        int TGSX; // nam san xuat
    public:
        XeVanChuyen(){}
        ~XeVanChuyen(){}
        virtual void nhap(){
            cout << "Ma phuong tien: ";
            cin >> maPT;
            while(1){
                cout << "Trong tai: ";
                cin >> trongTai;
                if (loaiXe==1 && trongTai<=35) break;
                if (loaiXe==2 && trongTai<=20) break;
                if (loaiXe==3 && trongTai<=3.5) break;
                cout << "Trong tai vua qua muc cho phep! Moi nhap lai!\n";
            }
            cin.ignore();
            cout << "Xuat xu: ";
            getline(cin,xuatXu);
            cout << "Thoi gian san xuat: ";
            cin >> TGSX;
        }
        void setLoai(int loaiXe){
            this->loaiXe=loaiXe;
        }
        virtual int nhienLieuTieuHao()=0;
        int getMaPT(){
            return maPT;
        }
        virtual long double tinhTienCuoc(int nKm)=0;
};
class XeCTN : public XeVanChuyen{
    private:
        string loaiCTN;
    public:
        XeCTN(){}
        ~XeCTN(){}
        void nhap(){
            cout << "Loai xe con-tai-no: ";
            getline(cin,loaiCTN);
            XeVanChuyen::nhap();
        }
        int nhienLieuTieuHao(){
            return 40;
        }
        long double tinhTienCuoc(int nKm){
            return (trongTai*1000)*150*nKm;
        }
};
class XeBen : public XeVanChuyen{
    private:
        string loaiBen;
    public:
        XeBen(){}
        ~XeBen(){}
        void nhap(){
            cout << "Loai xe ben: ";
            getline(cin,loaiBen);
            XeVanChuyen::nhap();
        }
        int nhienLieuTieuHao(){
            return 40;
        }
        long double tinhTienCuoc(int nKm){
            return trongTai*5000*nKm;
        }
};
class XeDongLanh : public XeVanChuyen{
    private:
        string loaiDL;
    public:
        XeDongLanh(){}
        ~XeDongLanh(){}
        void nhap(){
            cout << "Loai xe dong lanh: ";
            getline(cin,loaiDL);
            XeVanChuyen::nhap();
        }
        int nhienLieuTieuHao(){
            return 25;
        }
        long double tinhTienCuoc(int nKm){
            return (trongTai*1000)*200*nKm;
        }
};
class TuyenDuong{
    private:
        int maTD;
        string tenTD;
        int nKm;
    public:
        TuyenDuong(){}
        ~TuyenDuong(){}
        void nhap(){
            cout << "Ma tuyen duong: ";
            cin >> maTD;
            cin.ignore();
            cout << "Ten tuyen duong: ";
            getline(cin,tenTD);
            cout << "So ki-lo-met: ";
            cin >> nKm;
        }
        int getKm(){
            return nKm;
        }
        int getMaTD(){
            return maTD;
        }
};
class QuanLiChuyenHang{
    private:
        int maCH;
        int maPT;
        int maTD;
        Date TGXC;
    public:
        QuanLiChuyenHang(){}
        ~QuanLiChuyenHang(){}
        void nhap(){
            cout << "Ma chuyen hang: ";
            cin >> maCH;
            cout << "Ma phuong tien: ";
            cin >> maPT;
            cout << "Ma tuyen duong: ";
            cin >> maTD;
            cout << "Thoi gian xe chay: ";
            cin >> TGXC;
        }
        int getMaPT(){
            return maPT;
        }
        int getMaTD(){
            return maTD;
        }
        void xuat(){
            cout << "Ma chuyen hang: " << maCH;
            cout << " | Ma phuong tien: " << maPT;
            cout << " | Ma tuyen duong: " << maTD;
            cout << " | Thoi gian xe chay: " << TGXC;
        }
};
class CongTy{
    private:
        int n, m, l;
        vector <XeVanChuyen*> xe;
        vector <TuyenDuong*> tuyenDuong;
        vector <QuanLiChuyenHang*> chuyenHang;
    public:
        CongTy(){}
        ~CongTy(){}
        void nhapPhuongTien(){
            int loaiXe;
            cout << "-Nhap so luong xe cua cong ty: ";
            cin >> n;
            for (int i=0; i<n; i++){
                cout << "Nhap 1 de them thong tin xe con-tai-no.\n";
                cout << "Nhap 2 de them thong tin xe ben.\n";
                cout << "Nhap 3 de them thong tin xe dong lanh.\n";
                cout << "Moi nhap: ";
                cin >> loaiXe;
                cin.ignore();
                if (loaiXe==1){
                    xe.push_back(new XeCTN);
                    xe[i]->setLoai(1);
                }
                else if (loaiXe==2){
                    xe.push_back(new XeBen);
                    xe[i]->setLoai(2);
                }
                else if (loaiXe==3){
                    xe.push_back(new XeDongLanh);
                    xe[i]->setLoai(3);
                }
                cout << "+Nhap thong tin phuong tien thu: " << i+1 << endl;
                xe[i]->nhap();
            }
            cout << endl;
        }
        void nhapTuyenDuong(){
            cout << "-Nhap so luong tuyen duong: ";
            cin >> m;
            for (int i=0; i<m; i++){
                tuyenDuong.push_back(new TuyenDuong);
                cout << "+Nhap thong tin tuyen duong thu: " << i+1 << endl;
                tuyenDuong[i]->nhap();
            }
            cout << endl;
        }
        void nhapChuyenHang(){
            cout << "-Nhap so luong chuyen hang can quan li: ";
            cin >> l;
            for (int i=0; i<l; i++){
                chuyenHang.push_back(new QuanLiChuyenHang);
                cout << "+Nhap thong tin chuyen hang thu: " << i+1 << endl;
                chuyenHang[i]->nhap();
            }
            cout << endl;
        }
        int indexMaPT(int maPT){ // lấy chỉ số của phương tiện cần quản lí
            for (int i=0; i<xe.size(); i++){
                if (maPT==xe[i]->getMaPT()) return i;
            }
        }
        int indexMaTD(int maTD){ // lấy chỉ số của tuyến đường cần quản lí
            for (int i=0; i<tuyenDuong.size(); i++){
                if (maTD==tuyenDuong[i]->getMaTD()) return i;
            }
        }
        void tienCuocChuyenHang(){
            for (int i=0; i<chuyenHang.size(); i++){
                int j=indexMaPT(chuyenHang[i]->getMaPT());
                int k=indexMaTD(chuyenHang[i]->getMaTD());
                long double tienCuoc=xe[j]->tinhTienCuoc(tuyenDuong[k]->getKm());
                chuyenHang[i]->xuat();
                cout << " | Tien cuoc la: " << static_cast<long long>(tienCuoc) << endl;
                tongCuoc[chuyenHang[i]->getMaPT()]+=tienCuoc;
            }
            cout << endl;
        }
        void tongCuocThang(){
            for (auto it : tongCuoc){
                cout << "Ma phuong tien " << it.first;
                cout << " co tong cuoc thang la: " << static_cast<long long>(it.second);
                cout << endl;
            }
        }
};
int main(){
    CongTy congTy;
    congTy.nhapPhuongTien();
    congTy.nhapTuyenDuong();
    congTy.nhapChuyenHang();
    congTy.tienCuocChuyenHang(); 
    congTy.tongCuocThang();
    return 0;
}