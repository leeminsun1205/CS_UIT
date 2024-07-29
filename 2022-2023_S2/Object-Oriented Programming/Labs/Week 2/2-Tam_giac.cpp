#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
class Diem
{
    private:
        float _hoanhDo, _tungDo; 
    public:
        Diem(){};
        ~Diem(){}; 
        friend istream &operator >> (istream &in, Diem &A); 
        friend ostream &operator << (ostream &out, Diem A); 
        void tinhTien(float, float); 
};
istream &operator >> (istream &in, Diem &A)
{
    in >> A._hoanhDo;
    in >> A._tungDo;
    return in;
}
ostream &operator << (ostream &out, Diem A)
{
    cout << "(" << A._hoanhDo << "," << A._tungDo << ")";
    return out;
}
void Diem::tinhTien(float rad, float d)
{
    float xV=cos(rad)*d;
    float yV=sin(rad)*d;
    this->_hoanhDo+=xV;
    this->_tungDo+=yV;
}
class TamGiac
{
    private:
        Diem A,B,C;
    public:
        TamGiac(){};
        ~TamGiac(){};
        friend istream &operator >> (istream &in, TamGiac &TG); 
        friend ostream &operator << (ostream &out, TamGiac TG); 
        void tinhTien();
};
istream &operator >> (istream &in, TamGiac &TG)
{
    in >> TG.A;
    in >> TG.B;
    in >> TG.C;
    return in;
}
ostream &operator << (ostream &out, TamGiac TG)
{
    out << TG.A << endl;
    out << TG.B << endl;
    out << TG.C;
    return out;
}
void TamGiac::tinhTien()
{
    float degree; float d;
    cin >> degree >> d;
    float rad=degree/180*PI;
    A.tinhTien(rad,d); 
    B.tinhTien(rad,d);
    C.tinhTien(rad,d);
}
int main()
{
    TamGiac TG;
    cin >> TG;
    TG.tinhTien();
    cout << TG;
}