#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct DMY {
    int _d, _m, _y;
};

class PhuongTien {
    private:
        int _maPT;
        string _loaiXe;
        long double _trongTai;
        string _xuatXu;
        int _namSX;
    public:
        PhuongTien(){}
        virtual ~PhuongTien(){}

        int getMaPT() const { return _maPT; }
        string getLoaiXe() const { return _loaiXe; }
        long double getTrongTai() const { return _trongTai; }
        string getXuatXu() const { return _xuatXu; }
        int getNamSX() const { return _namSX; }

        void setMaPT(int maPT) { _maPT = _maPT; }
        void setLoaiXe(string loaiXe) { _loaiXe = loaiXe; }
        void setTrongTai(long double trongTai) { _trongTai = trongTai; }
        void setXuatXu(string xuatXu) { _xuatXu = xuatXu; } 

        virtual void Nhap() {
            cout << "Nhap ma phuong tien: "; cin >> _maPT;
            cout << "Nhap noi xuat xu: "; cin.ignore();
            getline(cin, _xuatXu);
            cout << "Nhap thoi gian san xuat: "; cin >> _namSX;
        }
        virtual void Xuat() {
            cout << "Ma phuong tien: " << _maPT << endl;
            cout << "Xuat xu: " << _xuatXu << endl;
            cout << "Thoi gian san xuat: " << _namSX << endl;
        }

        virtual long double getNhienLieuTH(int) = 0;
        virtual long double getTienCuoc(int) = 0;
};

class Container final : public PhuongTien {
    private:
        string _loaiContainer;
    public:
        Container() {
            setLoaiXe("Container");
        }
        ~Container(){}

        void Nhap() override {
            int trongTai;
            PhuongTien::Nhap();
            cout << "Nhap loai container: "; cin.ignore(); getline(cin, _loaiContainer);
            cout << "Nhap trong tai(lon hon 0 va toi da la 35): ";
            cin >> trongTai;
            while(trongTai < 0 || trongTai > 35) {
                cout << "Nhap sai, nhap lai trong tai(lon hon 0 va toi da la 35): ";
                cin >> trongTai;
            }
            setTrongTai(trongTai);
        }
        void Xuat() override {
            PhuongTien::Xuat();
            cout << "Loai xe: " << getLoaiXe() << " " << _loaiContainer << endl;
            cout << "Trong tai: " << getTrongTai() << " tan" << endl;
        }

        long double getNhienLieuTH(int km) {
            return 0.4 * km;
        }

        long double getTienCuoc(int km) {
            return getTrongTai() * 1000 * 150 * km;
        }
};

class XeBen final : public PhuongTien {
    public:
        XeBen(){ 
            setLoaiXe("Xe ben");
        }
        ~XeBen(){}
        void Nhap() override {
            int trongTai;
            PhuongTien::Nhap();
            cout << "Nhap trong tai(lon hon 0 va toi da la 20): ";
            cin >> trongTai;
            while(trongTai < 0 || trongTai > 20) {
                cout << "Nhap sai, nhap lai trong tai(lon hon 0 va toi da la 20): ";
                cin >> trongTai;
            }
            setTrongTai(trongTai);
        }
        void Xuat() override {
            PhuongTien::Xuat();
            cout << "Loai xe: " << getLoaiXe() << endl;
            cout << "Trong tai: " << getTrongTai() << "m^3" << endl;
        }
        long double getNhienLieuTH(int km) {
            return 0.4 * km;
        }

        long double getTienCuoc(int km) {
            return getTrongTai() * 5000 * km;
        }
};

class XeDL final : public PhuongTien {
    public:
        XeDL() {
            setLoaiXe("Xe dong lanh");
        }
        ~XeDL(){}
        void Nhap() override {
            int trongTai;
            PhuongTien::Nhap();
            cout << "Nhap trong tai(lon hon 0 va toi da la 3.5): ";
            cin >> trongTai;
            while(trongTai < 0 || trongTai > 20) {
                cout << "Nhap sai, nhap lai trong tai(lon hon 0 va toi da la 3.5): ";
                cin >> trongTai;
            }
            setTrongTai(trongTai);
        }
        void Xuat() override {
            PhuongTien::Xuat();
            cout << "Loai xe: " << getLoaiXe() << endl;
            cout << "Trong tai: " << getTrongTai() << " tan" << endl;
        }
        long double getNhienLieuTH(int km) {
            return 0.25 * km;
        }

        long double getTienCuoc(int km) {
            return getTrongTai() * 1000 * 200 * km;
        }
};

class TuyenDuong {
    private:
        int _maTuyen;
        string _tenTuyen;
        int _doDai;
    public:
        int getMaTuyen() const{ return _maTuyen; }
        string getTenTuyen() const{ return _tenTuyen; }
        int getDoDai() const{ return _doDai; }

        void setMaTuyen(int maTuyen) { _maTuyen = maTuyen; }
        void setTenTuyen(string tenTuyen) { _tenTuyen = tenTuyen; }
        void setDoDai(int doDai ) { _doDai = doDai; } 
        
        void Nhap() {
            cout << "Nhap ma tuyen: "; cin >> _maTuyen;
            cout << "Nhap ten tuyen: "; cin.ignore(); getline(cin, _tenTuyen);
            cout << "Nhap do dai tuyen: "; cin >> _doDai;
        }

        void Xuat() {
            cout << "Ma tuyen: " << _maTuyen << endl;
            cout << "Ten tuyen: " << _tenTuyen << endl;
            cout << "Do dai tuyen: " << _doDai << endl;
        }
};

class QuanLyXe{ 
    private:
        int _maChuyen;
        int _maTuyen;
        int _maPT;
        DMY _tgChay;
    public:
        void setMaChuyen(int maChuyen) { _maChuyen = maChuyen; }
        void setMaTuyen(int maTuyen) { _maTuyen = maTuyen; }
        void setMaPT(int maPT) { _maPT = maPT; }
        void setTGChay(DMY tgChay) { _tgChay = tgChay; }

        int getMaChuyen() const { return _maChuyen; }
        int getMaTuyen() const { return _maTuyen; }
        int getMaPT() const { return _maPT; }
        DMY gettgChay() const { return _tgChay; }

        void Nhap() {
            cout << "Nhap ma chuyen: "; cin >> _maChuyen;
            cout << "Nhap thoi gian chay: " << endl;
            cout << "Nhap ngay: "; cin >> _tgChay._d;
            cout << "Nhap thang: "; cin >> _tgChay._m;
            cout << "Nhap nam: "; cin >> _tgChay._y;
        }

        void Xuat() {
            cout << "______________________________________________" << endl;
            cout << "Ma chuyen: " << _maChuyen << endl;
            cout << "Ma tuyen: " << _maTuyen << endl;
            cout << "Ma phuong tien: " << _maPT << endl;
            cout << "Thoi gian chay: " << _tgChay._d << "/" << _tgChay._m << "/" <<_tgChay._y << endl;
            cout << "______________________________________________" << endl;
        }
};

class QuanLy {
    private:
        vector<PhuongTien*> _xe;
        vector<TuyenDuong*> _tuyen;
        vector<QuanLyXe*> _quanly;
    public:
        QuanLy(){}
        ~QuanLy(){}
        void Menu() {
            int choice;
            while(1) {
                cout << "-------------------- Menu -------------------" << endl;
                cout << "1. Nhap." << endl;
                cout << "2. Tien cuoc van tai cho moi chuyen xe." << endl;
                cout << "3. Tong tien cuoc thu duoc cho tung xe" << endl;
                cout << "Lua chon: ";
                cin >> choice;
                if(choice == 1) {
                    int n, m, choiceXe;
                    cout << "Nhap so tuyen duong: ";
                    cin >> m;
                    for(int i = 0; i < m; i++) {
                        _tuyen.push_back(new TuyenDuong);
                        _tuyen[i]->Nhap();
                    }
                    cout << "Nhap so xe: ";
                    cin >> n;
                    for(int i = 0; i < n; i++) {
                        cout << "Nhap loai xe: " << endl;
                        cout << "1. Xe container." << endl;
                        cout << "2. Xe ben." << endl;
                        cout << "3. Xe dong lanh." << endl;
                        cin >> choiceXe;
                        if(choiceXe == 1) {
                            _xe.push_back(new Container);
                        }
                        else if(choiceXe == 2) {
                            _xe.push_back(new XeBen);
                        }
                        else if(choiceXe == 3) {
                            _xe.push_back(new XeDL);
                        }
                        else {
                            cout << "Nhap sai!";
                            break;
                        }
                        _xe[i]->Nhap();
                    }
                    int k;
                    cout << "Nhap so chuyen hang can quan ly: "; cin >> k;
                    int maPT;
                    int maTuyen;
                    for(int i = 0; i < k; i++) {
                        int flagPT = 0;
                        int flagTD = 0;
                        _quanly.push_back(new QuanLyXe);
                        _quanly[i]->Nhap();
                        PhuongTien *pt;
                        TuyenDuong *td;
                        while(1) {
                            cout << "Nhap ma phuong tien: ";
                            cin >> maPT;
                            for(auto it : _xe) {
                                if(it->getMaPT() == maPT) {
                                    pt = it;
                                    flagPT = 1;
                                    break;
                                }
                            }
                            if(flagPT == 0) cout << "Khong ton tai ma phuong tien! Nhap lai!" << endl;
                            else break;
                        }
                        while(1) {
                            cout << "Nhap ma tuyen duong: ";
                            cin >> maTuyen;
                            for(auto it : _tuyen) {
                                if(it->getMaTuyen() == maTuyen) {
                                    td = it;
                                    flagTD = 1;
                                    break;
                                }
                            }
                            if(flagTD == 0)
                                cout << "Khong ton tai ma tuyen duong! Nhap lai!" << endl;
                            else break;
                        }
                        _quanly[i]->setMaPT(pt->getMaPT());
                        _quanly[i]->setMaTuyen(td->getMaTuyen());
                        }
                    }
                else if(choice == 2) {
                    for(int i = 0; i < _quanly.size(); i++) {
                        _quanly[i]->Xuat();
                        PhuongTien *pt;
                        TuyenDuong *td;
                        for(auto it : _xe) {
                            if(it->getMaPT() == _quanly[i]->getMaPT()) {
                                pt = it;
                                break;
                            }
                        }
                        for(auto it : _tuyen) {
                            if(it->getMaTuyen() == _quanly[i]->getMaTuyen()) {
                                td = it;
                            }
                        }
                        cout << "Chuyen nay co tien cuoc la: " << fixed << setprecision(0) << pt->getTienCuoc(td->getDoDai()) << " Dong" << endl;
                    }
                }
                else if(choice == 3) {
                        int maPT;
                        long double sum = 0;
                        cout << "Nhap ma phuong tien can kiem tra: ";
                        cin >> maPT;
                        for(int i = 0; i < _quanly.size(); i++) {
                            if(_quanly[i]->getMaPT() != maPT) {
                                continue;
                            }
                            PhuongTien *pt;
                            TuyenDuong *td;
                            for(auto it : _xe) {
                                if(it->getMaPT() == _quanly[i]->getMaPT()) {
                                    pt = it;
                                    break;
                                }
                            }
                            for(auto it : _tuyen) {
                                if(it->getMaTuyen() == _quanly[i]->getMaTuyen()) {
                                    td = it;
                                    break;
                                }
                            }
                            sum += pt->getTienCuoc(td->getDoDai());
                            if(i == _quanly.size() - 1) cout << "Khong ton tai ma phuong tien: " << maPT << endl;
                        }
                        cout << "Tong gia tri cua phuong tien co ma phuong tien: " << maPT << " la: " << sum << endl;
                    }
                }
            }
};

int main() {
    QuanLy a;
    a.Menu();
    return 0;
}
