#include <bits/stdc++.h>
using namespace std;
class SoPhuc
{
    private:
        float _thuc, _ao;
        float p, theta;
    public:
        SoPhuc(){};
        ~SoPhuc(){};
        friend istream &operator >> (istream &in, SoPhuc&);
        friend ostream &operator << (ostream &out, SoPhuc);
        void canBacN(unsigned int);
};
istream &operator >> (istream &in, SoPhuc &Z)
{
    in >> Z._thuc >> Z._ao;
    return in;
}
ostream &operator << (ostream &out, SoPhuc Z)
{
    out<< round(Z._thuc*100)/100 << " " << round(Z._ao*100)/100;
    return out;
}
void SoPhuc::canBacN(unsigned int n)
{
    this->p=sqrt(pow(this->_thuc,2)+pow(this->_ao,2));
    if (this->_thuc==0) this-> theta=atan2(this->_ao,0.00001);
    else
        this-> theta=atan2(this->_ao,this->_thuc);
    vector <SoPhuc> zCanN(n);
    for (int i=0; i<n; i++)
    {
        zCanN[i].p=pow(p,1.0/n);
        zCanN[i].theta=1.0/n*(this->theta+(i)*2.0*3.1415);
        zCanN[i]._thuc=zCanN[i].p*cos(zCanN[i].theta);
        zCanN[i]._ao=zCanN[i].p*sin(zCanN[i].theta);
        if (zCanN[i]._thuc==-0 || 0<zCanN[i]._thuc &&zCanN[i]._thuc<0.004 ||-0.004<zCanN[i]._thuc &&zCanN[i]._thuc<0)
            zCanN[i]._thuc=0;
        if (zCanN[i]._ao==-0 || 0<zCanN[i]._ao &&zCanN[i]._ao<0.004 ||-0.004<zCanN[i]._ao &&zCanN[i]._ao<0)
            zCanN[i]._ao=0;
    }
    for (int i=0; i<n; i++)
        cout << zCanN[i] << endl;
}
int main()
{
    SoPhuc Z; unsigned int n;
    cin >> Z;
    cin >> n;
    Z.canBacN(n);
    return 0;
}