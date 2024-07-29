#include <bits/stdc++.h>
using namespace std;
class DaThuc
{
    private:
        int bac_n;
        int *he_so;
    public:
        DaThuc(){};
        ~DaThuc(){};
        friend istream &operator >> (istream &in, DaThuc& A);
        friend ostream &operator << (ostream &out, DaThuc A);
        DaThuc operator + (DaThuc another);
        DaThuc operator - (DaThuc another);
        DaThuc operator * (DaThuc another);
};
istream &operator >> (istream &in, DaThuc& A)
{
    in >> A.bac_n;
    A.he_so=new int [A.bac_n+1];
    for (int i=0; i<=A.bac_n; i++)
        in >> A.he_so[i];
    return in;
} 
ostream &operator << (ostream &out, DaThuc A)
{
    out << A.he_so[0] << "x^0";
    for (int i=1; i<=A.bac_n; i++)
    {
        if (A.he_so[i]>0)
            out << "+" << A.he_so[i] << "x^" << i;
        else if (A.he_so[i]<0) out << A.he_so[i] << "x^" << i;
    }
    return out;
}
DaThuc DaThuc::operator + (DaThuc another)
{
    if (this->bac_n>another.bac_n)
        for (int i=another.bac_n+1; i<=this->bac_n; i++)
            another.he_so[i]=0;
    else 
        for (int i=this->bac_n+1; i<=another.bac_n; i++)
            this->he_so[i]=0;
    DaThuc sum;
    sum.bac_n=another.bac_n;
    sum.he_so=new int[sum.bac_n+1];
    for (int i=0; i<=sum.bac_n+1; i++)
        sum.he_so[i]=this->he_so[i]+another.he_so[i];
    return sum;
}  
DaThuc DaThuc::operator - (DaThuc another)
{
    if (this->bac_n>another.bac_n)
        for (int i=another.bac_n+1; i<=this->bac_n; i++)
            another.he_so[i]=0;
    else 
        for (int i=this->bac_n+1; i<=another.bac_n; i++)
            this->he_so[i]=0;
    DaThuc difference;
    difference.bac_n=another.bac_n;
    difference.he_so=new int[difference.bac_n+1];
    for (int i=0; i<=difference.bac_n+1; i++)
        difference.he_so[i]=this->he_so[i]-another.he_so[i];
    return difference;
} 
DaThuc DaThuc::operator * (DaThuc another)
{
    DaThuc product;
    product.bac_n=another.bac_n+this->bac_n;
    product.he_so=new int [product.bac_n+1];
    for (int i=0; i<=product.bac_n+1; i++)
        product.he_so[i]=0;
    for (int i=0; i<=this->bac_n; i++)
        for (int j=0; j<=another.bac_n; j++)
        {
            product.he_so[i+j]+=this->he_so[i]*another.he_so[j];
        }
    return product;
} 
int main()
{
    DaThuc A, B;
    cin >> A >> B;
    char c;
    cin >> c;
    if (c=='+') cout << A+B;
    if (c=='-') cout << A-B;
    if (c=='*') cout << A*B << endl;
    return 0;
}