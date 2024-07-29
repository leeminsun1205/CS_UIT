#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415
class Diem
{
    private:
        float _hoanhDo, _tungDo; 
    public:
        Diem(){}; // hàm khởi tạo
        ~Diem(){}; // hàm hủy
        friend istream &operator >> (istream &in, Diem &A); // nhập hoành độ, tung độ của điểm
        friend ostream &operator << (ostream &out, Diem A); // xuất hoành độ, tung độ của điểm
        int getHoanhDo(); // hàm lấy hoành độ của điểm
        int getTungDo(); // hàm lấy tung độ của điểm
        void setHoanhTung(float, float); // hàm thiết lập hoành độ và tung độ của điểm 
        void tinhTien(float, float); // hàm tịnh tiến điểm
        void quay(float, float, float); // hàm quay điểm
};
istream &operator >> (istream &in, Diem &A)
{
    in >> A._hoanhDo;
    in >> A._tungDo;
    return in;
}
ostream &operator << (ostream &out, Diem A)
{
    cout << "(" << A._hoanhDo << ";" << A._tungDo << ")";
    return out;
}
int Diem::getHoanhDo()
{
    return this->_hoanhDo;
}
int Diem::getTungDo()
{
    return this->_tungDo;
}
void Diem::setHoanhTung(float _hoanhDo, float _tungDo)
{
    this->_hoanhDo=_hoanhDo;
    this->_tungDo=_tungDo;
}
void Diem::tinhTien(float xV, float yV)
{
    this->_hoanhDo+=xV;
    this->_tungDo+=yV;
    // tịnh tiến hoành độ và tung độ của điểm theo vector v(xV,yV)
}
void Diem::quay(float a, float b, float degree)
{
    float rad=degree/180*PI; // đổi đơn vị từ độ sang radian phục vụ cho việc tính toán
    if (a==0 && b ==0) // tâm quay I(a, b) trùng với góc tọa độ O(0,0)
    {
        if (((int)degree-90)%360==0) // trường hợp góc quay là 90 độ
        {
            int _hoanhDoTemp=this->_hoanhDo;
            this->_hoanhDo=-this->_tungDo;
            this->_tungDo=_hoanhDoTemp;
        }
        else if (((int)degree+90)%360==0) // trường hợp góc quay là -90 độ
        {
            int _hoanhDoTemp=this->_hoanhDo;
            this->_hoanhDo=this->_tungDo;
            this->_tungDo=-_hoanhDoTemp;
        }
        else if ((int)degree%360==(int)abs(degree)) // trường hợp góc quay là +-180 độ
        {
            int _hoanhDoTemp=this->_hoanhDo;
            this->_hoanhDo=-this->_tungDo;
            this->_tungDo=-_hoanhDoTemp;
        }
        else // trường hợp các góc quay còn lại
        {
            int _hoanhDoTemp=this->_hoanhDo;
            this->_hoanhDo=_hoanhDo*cos(rad)-_tungDo*sin(rad);
            this->_tungDo=_hoanhDoTemp*sin(rad)+_tungDo*cos(rad);
        }
    }
    else // tâm quay I(a, b) không trùng với góc tọa độ
    {
        int _hoanhDoTemp=this->_hoanhDo;
        this->_hoanhDo=a+(_hoanhDo-a)*cos(rad)-(_tungDo-b)*sin(rad);
        this->_tungDo=b+(_hoanhDoTemp-a)*sin(rad)+(_tungDo+b)*cos(rad);
    }
}
class DaGiac
{
    private:
        int _soDinh;
        Diem *_dinh;
    public:
        DaGiac(){}; // hàm khởi tạo
        ~DaGiac(){}; // hàm hủy
        friend istream &operator >> (istream &in, DaGiac&); // hàm nhập các đỉnh của đa giác
        friend ostream &operator << (ostream &out, DaGiac); // hàm xuất các đỉnh của đa giác
        void tinhTien();
        void quay();
        void phongTo();
        void thuNho();
};
istream &operator >> (istream &in, DaGiac &A)
{
    while (1)
    {
        cout << "Nhap so dinh cua da giac: ";
        in >> A._soDinh;
        if (A._soDinh>=3) break;
        else cout << "Da giac phai co toi thieu 3 dinh, moi nhap lai so dinh!" << endl;
    }
    A._dinh =new Diem [A._soDinh]; // tạo mảng động chứa các đỉnh của đa giác
    for (int i=0; i<A._soDinh; i++) // duyệt qua mảng động và nhập lần lượt từng đỉnh của đa giác
    {
        cout << "Nhap dinh thu " << i+1 << ": ";
        in >> A._dinh[i];
    }
    return in;
}
ostream &operator << (ostream &out, DaGiac A)
{
    cout << "Da giac co " << A._soDinh << " dinh la:" << endl;
    for (int i=0; i<A._soDinh; i++)
    {   
        out << A._dinh[i];
        if (i<A._soDinh-1) cout << ", ";
        else cout << ".";
    }
    cout << endl;
    return out;
}
void DaGiac::tinhTien()
{
    float xV, yV;
    cout << "Nhap vector tinh tien v(xV,yV): " << endl;
    cin >> xV >> yV;
    for (int i=0; i<_soDinh; i++)
        _dinh[i].tinhTien(xV,yV);
}
void DaGiac::quay()
{
    float a,b,degree;
    cout << "Nhap toa do tam quay I(a,b): " << endl;
    cin >> a >> b;
    cout << "Nhap goc quay (don vi Do): " << endl;
    cin >> degree;
    for (int i=0; i<_soDinh; i++)
        _dinh[i].quay(a,b,degree);
}
void DaGiac::phongTo()
{
    int k;
    cout << "Nhap so k can phong to da giac: " << endl;
    cin >> k;
    for (int i=0; i<_soDinh; i++)
        _dinh[i].setHoanhTung(_dinh[i].getHoanhDo()*k, _dinh[i].getTungDo()*k);
}
void DaGiac::thuNho()
{
    int k;
    cout << "Nhap so k can thu nho da giac: " << endl;
    cin >> k;
    for (int i=0; i<_soDinh; i++)
        _dinh[i].setHoanhTung(_dinh[i].getHoanhDo()*(1.0/k), _dinh[i].getTungDo()*(1.0/k));
}
int main()
{
    DaGiac P;
    cin >> P;
    cout << P;
    P.tinhTien();
    P.quay();
    P.phongTo();
    P.thuNho();
    cout << P;
    return 0;
}