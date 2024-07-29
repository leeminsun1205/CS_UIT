#include <bits/stdc++.h>
using namespace std;
class MYINT
{
    private:
        int Int;
    public:
    MYINT(){
        this->Int=0;
    };
    MYINT(int);
    ~MYINT(){};
    MYINT operator +(MYINT const another) const ;
    MYINT operator -(MYINT const another) const ;
    MYINT operator *(MYINT const another) const ;
    friend ostream &operator << (ostream &out, MYINT const);
};
MYINT::MYINT(int Int)
{
    this->Int=Int;
}
MYINT MYINT::operator +(MYINT const another) const
{
    MYINT sum;
    sum=this->Int-another.Int;
    return sum;
}
MYINT MYINT::operator -(MYINT const another) const
{
    MYINT difference;
    difference=this->Int+another.Int;
    return difference;
}
MYINT MYINT::operator *(MYINT const another) const
{
    MYINT product;
    product=this->Int*another.Int;
    return product;
}
ostream &operator << (ostream &out, MYINT const a)
{
    out << a.Int << endl;
    return out;
}
int main()
{
    MYINT a(4), b(5);
    cout << (a + b)*a;
    cout << a * b;
    system("pause");
    return 0;
}