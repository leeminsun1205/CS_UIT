#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415;
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
class TamGiac
{
    private:
        Diem A,B,C; // A,B,C là 3 đỉnh của tam giác ABC
    public:
        TamGiac(){}; // hàm khởi tạo
        ~TamGiac(){}; // hàm hủy
        friend istream &operator >> (istream &in, TamGiac &TG); // nhập 3 đỉnh của tam giác
        friend ostream &operator << (ostream &out, TamGiac TG); // xuất 3 đỉnh của tam giác
        void tinhTien();
        void quay();
        void phongTo();
        void thuNho();
};
istream &operator >> (istream &in, TamGiac &TG)
{
    while(1){
    cout << "Nhap diem A: ";
    in >> TG.A;
    cout << "Nhap diem B: ";
    in >> TG.B;
    cout << "Nhap diem C: ";
    in >> TG.C;
    float AB=sqrt(pow(TG.A.getHoanhDo()-TG.B.getHoanhDo(),2)+pow(TG.A.getTungDo()-TG.B.getTungDo(),2));
    float AC=sqrt(pow(TG.A.getHoanhDo()-TG.C.getHoanhDo(),2)+pow(TG.A.getTungDo()-TG.C.getTungDo(),2));
    float BC=sqrt(pow(TG.C.getHoanhDo()-TG.B.getHoanhDo(),2)+pow(TG.C.getTungDo()-TG.B.getTungDo(),2));
    if (AB+AC>BC && AB+BC>AC && AC+BC>AB) break;
    else cout << "3 diem A, B, C khong tao thanh tam giac, moi nhap lai!" << endl;
    }
    return in;
}
ostream &operator << (ostream &out, TamGiac TG)
{
    cout << "Tam giac ABC gom 3 diem: " << endl;
    cout << "A"; out << TG.A << ", ";
    cout << "B"; out << TG.B << ", ";
    cout << "C"; out << TG.C << endl;
    return out;
}
void TamGiac::tinhTien()
{
    float xV, yV; // hoành độ và tung độ của vector tịnh tiến v
    cout << "Nhap vector tinh tien v(xV,yV): " << endl;
    cin >> xV >> yV; 
    A.tinhTien(xV,yV); 
    B.tinhTien(xV,yV);
    C.tinhTien(xV,yV);
    // các hàm tịnh tiến từng điểm A, B, C theo vector v(xV,yV)
}
void TamGiac::quay()
{
    float a,b,degree; // khai báo tọa độ tâm quay I(a,b) và góc quay degree đơn vị là Độ
    cout << "Nhap toa do tam quay I(a,b): " << endl;
    cin >> a >> b;
    cout << "Nhap goc quay: " << endl;
    cin >> degree;
    A.quay(a,b,degree);
    B.quay(a,b,degree);
    C.quay(a,b,degree);
    // các hàm quay từng điểm A, B, C theo tâm quay I(a,b) và góc quay degree
}
void TamGiac::phongTo()
{
    float k; // k là số lần phóng to tam giác
    cout << "Nhap so lan k can phong to tam giac: "<< endl;
    cin >> k;
    A.setHoanhTung(A.getHoanhDo()*k, A.getTungDo()*k);
    B.setHoanhTung(B.getHoanhDo()*k, B.getTungDo()*k);
    C.setHoanhTung(C.getHoanhDo()*k, C.getTungDo()*k);
    // các hàm thiết lập hoành độ và tung độ của A, B, C lên k lần để phóng to
}
void TamGiac::thuNho()
{
    float k;
    cout << "Nhap so lan k can thu nho tam giac: " << endl;
    cin >> k;
    A.setHoanhTung(A.getHoanhDo()*(1.0/k), A.getTungDo()*(1.0/k));
    B.setHoanhTung(B.getHoanhDo()*(1.0/k), B.getTungDo()*(1.0/k));
    C.setHoanhTung(C.getHoanhDo()*(1.0/k), C.getTungDo()*(1.0/k));
    // các hàm thiết lập hoành độ và tung độ của A, B, C xuống k lần để thu nhỏ
}
int main()
{
    TamGiac ABC;
    cin >> ABC; // nhập các giá trị của tam giác ABC
    cout << ABC; // xuất ra giá trị của tam giác ABC
    ABC.tinhTien();
    ABC.quay();
    ABC.phongTo();
    ABC.thuNho();
    cout << ABC;
    return 0;
}