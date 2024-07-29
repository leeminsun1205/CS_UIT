#include <bits/stdc++.h>
using namespace std; 
#define MAX 4
class SoPhuc
{
    private:
        int thuc, ao;
    public:
    SoPhuc(){
        this->thuc=0;
        this->ao=0;
    };
    ~SoPhuc(){};
    friend istream &operator >> (istream &in, SoPhuc&);
    friend ostream &operator << (ostream &out, SoPhuc);
    SoPhuc operator + (SoPhuc const another);
    SoPhuc operator * (SoPhuc const another);

};
istream &operator >> (istream &in, SoPhuc&z)
{   
    in >> z.thuc >> z.ao;
    return in;
}
ostream &operator << (ostream &out, SoPhuc z)
{
    cout << z.thuc << " " << z.ao;
    return out;
}
SoPhuc SoPhuc::operator + (SoPhuc const another)
{
    SoPhuc Sum; ;
    Sum.thuc=this->thuc+another.thuc; 
    Sum.ao=this->ao+another.ao;
    return Sum;
}
SoPhuc SoPhuc::operator * (SoPhuc const another) 
{
    SoPhuc Product; 
    Product.thuc=this->thuc*another.thuc-this->ao*another.ao; 
    Product.ao=this->thuc*another.ao+this->ao*another.thuc; 
    return Product; 
}
class Scalar{
    private:
        SoPhuc scl;
    public:
    Scalar(){};
    ~Scalar(){};
};
class Vector{
    private:
        vector <SoPhuc> vtr;
    public:
    Vector(){};
    ~Vector(){};
};
class Matrix{
    private:
        SoPhuc mtr[MAX][MAX];
    public:
    Matrix(){};
    ~Matrix(){};
};
void chiThi(int n)
{
    for (int i=1; i<=n; i++)
    {
        int type; cin >> type;
        if (type==1){
            SoPhuc Scalar;
            cin >> Scalar;
        }
        if (type==2){
            int m; cin >> m;
            vector <SoPhuc> Vector(m);
            for (int i=0; i<n; i++)
                cin>> Vector[i];
        }
        if (type==3){
            int k; cin >> k;
            SoPhuc Matrix[MAX][MAX];
            for (int i=0; i<k; i++)
                for (int j=0; j<k; j++)
                    cin >> Matrix[i][j];
        }
    }
    string bieu_thuc;
    cin >> bieu_thuc;
}
int main()
{
    int n; 
    cin >> n;
    chiThi(n);
    return 0;
}