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
        float getHoanhDo(); 
        float getTungDo();
};
istream &operator >> (istream &in, Diem &A)
{
    in >> A._hoanhDo;
    in >> A._tungDo;
    return in;
}
float Diem::getHoanhDo()
{
    return this->_hoanhDo;
}
float Diem::getTungDo()
{
    return this->_tungDo;
}
class DaGiac
{
    private:
        int _soDinh;
        Diem *_dinh;
    public:
        DaGiac(){};
        ~DaGiac(){};
        friend istream &operator >> (istream &in, DaGiac&);
        double dienTich();
        
};
istream &operator >> (istream &in, DaGiac &A)
{
    in >> A._soDinh;
    A._dinh =new Diem [A._soDinh]; 
    for (int i=0; i<A._soDinh; i++) 
        in >> A._dinh[i];
    return in;
}
double DaGiac::dienTich()
{
    double sum=0;
    for (int i=0; i<this->_soDinh-1; i++)
    {
        sum+=_dinh[i].getHoanhDo()*_dinh[i+1].getTungDo()-_dinh[i+1].getHoanhDo()*_dinh[i].getTungDo();
    }
    sum+=_dinh[_soDinh-1].getHoanhDo()*_dinh[0].getTungDo()-_dinh[0].getHoanhDo()*_dinh[_soDinh-1].getTungDo();
    sum=0.5*abs(sum);
    return sum;
}
int main()
{
    DaGiac D;
    cin >> D;
    cout << D.dienTich();
    return 0;
}   
