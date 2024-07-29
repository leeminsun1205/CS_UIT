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
        int giaTriDaThuc(int x);
        DaThuc operator + (DaThuc another);
        DaThuc operator - (DaThuc another);
        DaThuc operator * (DaThuc another);
};
istream &operator >> (istream &in, DaThuc& A)
{
    cout << "Nhap bac thu n: ";
    in >> A.bac_n;
    A.he_so=new int [A.bac_n+1];
    cout << "Nhap cac he so tu bac 0 toi bac " << A.bac_n << ":\n";
    for (int i=0; i<=A.bac_n; i++)
        in >> A.he_so[i];
    return in;
} 
ostream &operator << (ostream &out, DaThuc A)
{
    if (A.he_so[0]!=0)
        out << A.he_so[0];
    for (int i=1; i<=A.bac_n; i++)
    {
        if (A.he_so[i]>0)
            if (A.he_so[i]!=1){
                if (i!=1)
                    out << "+" << A.he_so[i] << "x^" << i;
                else 
                    out << "+" << A.he_so[i] << "x";
            }
            else{ 
                if (i!=1)
                    out << "+x^" << i;
                else 
                    out << "+x";
            }
        else if (A.he_so[i]<0)
            if (A.he_so[i]!=-1){
                if (i!=1)
                    out << A.he_so[i] << "x^" << i;
                else 
                    out << A.he_so[i] << "x";
            }
            else 
                if (i!=1)
                    out << "-x^" << i;
                else 
                    out << "-x";
    }
    cout << endl;
    return out;
}
int DaThuc::giaTriDaThuc(int x)
{
    int gia_tri=0;
    for (int i=0; i<=this->bac_n; i++)
    {
        gia_tri+=this->he_so[i]*pow(x,i);
    }
    return gia_tri;
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
    cout << "Moi nhap da thuc A.\n";
    cin >> A;
    cout << "Da thuc A vua nhap la:\n" << "A="<< A;
    cout << "Moi nhap da thuc B.\n";
    cin >> B;
    cout << "Da thuc B vua nhap la:\n" << "B="<< B;
    cout << "Gia tri cua da thuc A tai x=2 la: ";
    cout << A.giaTriDaThuc(2) << endl;
    cout << "Gia tri cua da thuc B tai x=3 la: ";
    cout << B.giaTriDaThuc(3) << endl;
    cout << "-Nhap '+' de tinh tong 2 da thuc.\n";
    cout << "-Nhap '-' de tinh hieu 2 da thuc.\n";
    cout << "-Nhap '*' de tinh tich 2 da thuc.\n";
    cout << "Nhap ki hieu: ";
    char c;
    cin >> c;
    if (c=='+') {
        cout << "Tong 2 da thuc A va B la:\n"<< "A+B=" <<A+B;
    }
    if (c=='-') {
        cout << "Hieu 2 da thuc A va B la:\n"<< "A-B=" << A-B;
    }
    if (c=='*') {
        cout << "Tich 2 da thuc A va B la:\n" << "A*B=" << A*B;
    }
    return 0;
}