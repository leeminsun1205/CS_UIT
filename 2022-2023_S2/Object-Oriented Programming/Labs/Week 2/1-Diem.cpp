#include <bits/stdc++.h>
using namespace std;
class Diem
{
    private:
        float _hoanhDo, _tungDo;
    public:
        Diem(){};
        ~Diem(){};
        friend istream &operator >> (istream &in, Diem &A);
        friend ostream &operator << (ostream &out, Diem A);
        void nhanDoi();
        void ganDiemO();
        void tinhTien();
};
istream &operator >> (istream &in, Diem &A)
{
    in >> A._hoanhDo >> A._tungDo;
    return in;
}
ostream &operator << (ostream &out, Diem A)
{
    cout << "(" << A._hoanhDo << "," << A._tungDo << ")";
    return out;
}
void Diem::nhanDoi()
{
    this->_hoanhDo*=2;
    this->_tungDo*=2;
}
void Diem::ganDiemO()
{   
    this->_hoanhDo=0;
    this->_tungDo=0;
}
void Diem::tinhTien()
{
    int o; float d;
    cin >> o >> d;
    if (o==0) this->_hoanhDo+=d;
    else this->_tungDo+=d;
}
int main()
{
    Diem A;
    cin >> A;
    int n,x; cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x;
        if (x==1) A.nhanDoi();
        else if (x==2) A.ganDiemO();
        else if (x==3) A.tinhTien();
    }
    cout << A;
    return 0;
}