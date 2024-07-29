#include <bits/stdc++.h>
// Định nghĩa cấu trúc Điểm
using namespace std;
struct Diem{
    float x;
    float y;
};
// nạp chồng toán tử nhập xuất điểm
istream &operator >> (istream &in, Diem &A)
{
    cin >> A.x;
    cin >> A.y;
    return in;
}
ostream &operator << (ostream &out, Diem A)
{
    cout << "(" << A.x << "," << A.y << ")";
    return out;
}
double tichVoHuong(Diem A, Diem B)
{
    return A.x*B.x+A.y*B.y;
}
double doLon(Diem A, Diem B)
{
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}
Diem vectorDiem(Diem A, Diem B)
{
    Diem C;
    C.x=A.x-B.x;
    C.y=A.y-B.y;
    return C;
}
// Định nghĩa khái niệm tứ giác
class TuGiac{
private:
    Diem dinh[4];
public:
    // hàm tạo và hàm hủy
    TuGiac();
    ~TuGiac();
    // hàm setter
    Diem* getDiem(){return dinh;}
    // hàm nhập và xuất
    virtual void nhap();
    virtual void xuat();
    // hàm khác
    virtual bool check()=0;
};
//Hàm tạo và hủy
TuGiac::TuGiac(){
    for (int i=0; i<4; i++)
    {
        dinh[i].x=0;
        dinh[i].y=0;
    }
}
TuGiac::~TuGiac(){
}
//Hàm nhập và xuất
void TuGiac::nhap(){
    do{
        for (int i=0; i<4; i++)
        {
            cout << "Nhap dinh thu " << i+1 << " (x,y)=";
            cin >> this->dinh[i];
        }
        cout << endl;
    }
    while(check()==0);
}
void TuGiac::xuat()
{
    for (int i=0; i<4; i++)
    {
        cout << this->dinh[i];
        if (i<3) cout << ";";
        else cout << " co:\n";
    }
}
// Định nghĩa khái niệm hình thang
class HinhThang : public TuGiac {
private:
    float day_lon;
    float day_be;
    float chieu_cao;
public:
    //Hàm tạo và hủy
    HinhThang();
    ~HinhThang();
    //Hàm getter
    float getDayLon(){return day_lon;}
    float getDayBe(){return day_be;}
    float getChieuCao(){return chieu_cao;}
    //Hàm nhập và xuất
    void nhap();
    void xuat();
    bool check();
};
HinhThang::HinhThang():TuGiac(){
    day_lon=0;
    day_be=0;
    chieu_cao=0;
}
HinhThang::~HinhThang(){};
void HinhThang::nhap()
{
    cout << "Nhap toa do cac dinh cua hinh thang:\n";
    TuGiac::nhap();
}
void HinhThang::xuat()
{
    cout << "Hinh thang voi cac dinh:\n";
    TuGiac::xuat();
    cout << "-Day lon la " << day_lon <<endl;
    cout << "-Day be la " << day_be << endl;
    cout << "-Chieu cao la " << chieu_cao << endl;
}

bool HinhThang::check()
{
    Diem truc_tung={0,1};
    Diem *A=getDiem();
    vector<float> gia_tri;
    float h;
    gia_tri.resize(0);
    for (int i=0; i<3; i++)
    {
        for (int j=i+1; j<4; j++)
        {
            if(tichVoHuong(vectorDiem(A[i],A[j]),truc_tung)==0)
            {
                gia_tri.push_back(doLon(A[i],A[j]));
                for (int m=0; m<4; m++)
                {
                    if (m!=i && m!=j)
                    {
                        h=abs(A[m].y-A[i].y);
                    }
                }
            }
        }
    }
    if (gia_tri.size()!=2){
        cout << "Cac diem nay khong tao thanh mot hinh thang!\n";
        cout << "Moi nhap lai.\n";
        return false;
    }
    else
    {
        if (gia_tri[0]>gia_tri[1]) 
        {
            this->day_lon=gia_tri[0];
            this->day_be=gia_tri[1];
        }
        else
        {
            this->day_lon=gia_tri[1];
            this->day_be=gia_tri[0];
        }
        this->chieu_cao=h;
        return true;
    }
}
// Định nghĩa khái niệm hình bình hành
class HinhBinhHanh : public TuGiac {
private:
    float day_lon;
    float day_be;
    float chieu_cao;
public:
    // Hàm tạo và hủy
    HinhBinhHanh();
    ~HinhBinhHanh();
    // Hàm getter
    float getDayLon(){return day_lon;}
    float getDayBe(){return day_be;}
    float getChieuCao(){return chieu_cao;}
    // Hàm nhập và xuât
    void nhap();
    void xuat();
    bool check();
};
HinhBinhHanh::HinhBinhHanh():TuGiac()
{
    day_lon=0;
    day_be=0;
}
HinhBinhHanh::~HinhBinhHanh(){}
void HinhBinhHanh::nhap(){
    cout << "Nhap toa do cac dinh cua hinh binh hanh:\n";
    TuGiac::nhap();
}
void HinhBinhHanh::xuat(){
    cout << "Hinh binh hanh voi cac dinh:\n";
    TuGiac::xuat();
    cout << "-Day lon la " << day_lon <<endl;
    cout << "-Day be la " << day_be << endl;
    cout << "-Chieu cao la " << chieu_cao << endl;
}
bool HinhBinhHanh::check()
{
    Diem truc_tung={0,1};
    Diem *A=getDiem();
    vector<float> gia_tri;
    float h, s;
    gia_tri.resize(0);
    for (int i=0; i<3; i++)
    {
        for (int j=i+1; j<4; j++)
        {
            if(tichVoHuong(vectorDiem(A[i],A[j]),truc_tung)==0)
            {
                gia_tri.push_back(doLon(A[i],A[j]));
                for (int m=0; m<4; m++)
                {
                    if (m!=i && m!=j)
                    {
                        h=abs(A[m].y-A[i].y);
                        float d1=doLon(A[m],A[i]);
                        float d2=doLon(A[m],A[j]);
                        if (d1<d2)
                        {
                            s=d1;
                        }
                        else s=d2;
                    }
                }
            }
        }
    }
    if (gia_tri.size()==2&& gia_tri[0]==gia_tri[1]){
        if(gia_tri[0]>s){
            day_lon=gia_tri[0];
            day_be=s;
        }
        else
        {
            day_lon=s;
            day_be=gia_tri[0];
        }
        this->chieu_cao=h;
        return true;
    }
    else
    {
        cout << "Cac diem nay khong tao thanh hinh binh hanh!\n";
        cout << "Moi nhap lai.\n";
        return false;
    }
}
// Định nghĩa khái niệm hình chữ nhật
class HinhChuNhat : public TuGiac {
private:
    float chieu_rong;
    float chieu_dai;
public:
    //Hàm tạo và hủy
    HinhChuNhat();
    ~HinhChuNhat();
    //Hàm getter
    float getChieuRong(){return chieu_rong;}
    float getChieuDai(){return chieu_dai;}
    //Hàm nhập và xuất
    virtual void nhap();
    virtual void xuat();
    virtual bool check();
};
HinhChuNhat::HinhChuNhat():TuGiac()
{
    chieu_rong=0;
    chieu_dai=0;
}
HinhChuNhat::~HinhChuNhat(){}
void HinhChuNhat::nhap()
{
    cout << "Nhap toa do cac dinh cua hinh chu nhat:\n";
    TuGiac::nhap();
}
void HinhChuNhat::xuat(){
    cout << "Hinh chu nhat voi cac dinh:\n";
    TuGiac::xuat();
    cout << "-Chieu rong la " << chieu_rong << endl;
    cout << "-Chieu dai la " << chieu_dai << endl;
}
bool HinhChuNhat::check()
{
    Diem truc_tung={0,1};
    Diem truc_hoanh={1,0};
    Diem *A=getDiem();
    vector<float> gia_tri_X;
    vector<float> gia_tri_Y;
    float h, s;
    gia_tri_X.resize(0);
    gia_tri_Y.resize(0);
    for (int i=0; i<3; i++)
    {
        for (int j=i+1; j<4; j++)
        {
            if(tichVoHuong(vectorDiem(A[i],A[j]),truc_tung)==0)
            {
                gia_tri_X.push_back(doLon(A[i],A[j]));
            }
            else if (tichVoHuong(vectorDiem(A[i],A[j]),truc_hoanh)==0)
            {
                gia_tri_Y.push_back(doLon(A[i],A[j]));
            }
        }
    }
    if (gia_tri_X.size()==gia_tri_Y.size()){
        if (gia_tri_X[0]>gia_tri_Y[0])
        {
            this->chieu_dai=gia_tri_X[0];
            this->chieu_rong=gia_tri_Y[0];
        }
        else
        {
            this->chieu_dai=gia_tri_Y[0];
            this->chieu_rong=gia_tri_X[0];
        }
        return true;
    }
    else
    {
        cout << "Cac diem nay khong tao thanh hinh chu nhat!\n";
        cout << "Moi nhap lai.\n";
        return false;
    }
}
// Định nghĩa khái niệm hình vuông
class HinhVuong : public HinhChuNhat {
private:
    float canh;
public:
    //hàm tạo và hủy
    HinhVuong();
    ~HinhVuong();
    //hàm getter
    float getCanh(){return canh;}
    //hàm nhập và xuất
    void nhap();
    void xuat();
    bool check();
};
HinhVuong::HinhVuong():HinhChuNhat()
{
    canh=0;
}
HinhVuong::~HinhVuong(){}
void HinhVuong::nhap(){
    cout << "Nhap toa do cac dinh cua hinh vuong:\n";
    TuGiac::nhap();
}
void HinhVuong::xuat(){
    cout << "Hinh vuong voi cac dinh:\n";
    TuGiac::xuat();
    cout << "-Cac canh la " << canh << endl;
}
bool HinhVuong::check()
{
    if (HinhChuNhat::check()==1 && HinhChuNhat::getChieuRong()==HinhChuNhat::getChieuRong())
    {
        canh=HinhChuNhat::getChieuDai();
        return true;
    }
    else {
        cout << "Cac diem nay khong tao thanh mot hinh vuong!\n";
        cout << "Moi nhap lai.\n";
        return false;
    }
}
class ThongTin{
private:
    int loai_hinh;
    TuGiac *tu_giac;
public:
    ThongTin(){};
    ~ThongTin(){};
    void nhap()
    {
        cout << "-----------MENU-----------\n";
        cout << "-Neu hinh thang nhap 1\n";
        cout << "-Neu hinh binh hanh nhap 2\n";
        cout << "-Neu hinh chu nhat nhap 3\n";
        cout << "-Neu hinh vuong nhap 4\n";
        cout << "Nhap loai hinh can xuat thong tin:\n";
        while (1){
            cin >> loai_hinh;
            if (1<=loai_hinh && loai_hinh<=5) break;
            cout << "Loai hinh khong hop le! Moi nhap lai.\n";
        }
        if (loai_hinh==1)
        {
            tu_giac=new HinhThang();
            tu_giac->nhap();
        }
        else if (loai_hinh==2)
        {
            tu_giac=new HinhBinhHanh();
            tu_giac->nhap();
        }
        else if (loai_hinh==3)
        {
            tu_giac=new HinhChuNhat();
            tu_giac->nhap();
        }
        else
        {
            tu_giac=new HinhVuong();
            tu_giac->nhap();
        }
    }
    void xuat()
    {
        tu_giac->xuat();
    }
};
int main()
{
    ThongTin tu_giac;
    tu_giac.nhap();
    tu_giac.xuat();
    return 0;
}