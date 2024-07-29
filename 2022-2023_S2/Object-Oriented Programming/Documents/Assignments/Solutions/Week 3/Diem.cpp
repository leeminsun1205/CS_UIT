#include <bits/stdc++.h>
using namespace std;
class Diem
{
    private:
        float _hoanhDo,_tungDo;
    public:
        Diem(){};
        ~Diem(){};
        friend istream &operator >> (istream &in, Diem &A);
        friend ostream &operator << (ostream &out, Diem A);
        void setHoanhTung(float,float);
        int getHoanhDo();
        int getTungDo();
        void tinhTien();
};
istream &operator >> (istream &in, Diem &A)
{
    cout << "Nhap hoanh do: ";
    in >> A._hoanhDo;
    cout << "Nhap tung do: ";
    in >> A._tungDo;
    return in;
}
ostream &operator << (ostream &out, Diem A)
{
    cout << "Diem A co toa do la: ";
    cout << "A(" << A._hoanhDo << "," << A._tungDo << ")" << endl;
    return out;
}
void Diem::setHoanhTung(float _hoanhDo, float _tungDo)
{
    this->_hoanhDo=_hoanhDo;
    this->_tungDo=_tungDo;
}
int Diem::getHoanhDo()
{
    cout << "Hoanh do cua P la: ";
    return this->_hoanhDo;
}
int Diem::getTungDo()
{
    cout << "Tung do cua P la: ";
    return this->_tungDo;
}
void Diem::tinhTien()
{
    float xV, yV;
    cout << "Nhap vector tinh tien v(xV,yV): " << endl;
    cin >> xV >> yV;
    this->_hoanhDo+=xV;
    this->_tungDo+=yV;
}
int main()
{
    Diem A;
    A.setHoanhTung(0,0);
    cin >> A;
    cout << A.getHoanhDo() << endl;
    cout << A.getTungDo()<< endl;
    cout << A;
    A.tinhTien();
    cout << A;
    return 0;
}