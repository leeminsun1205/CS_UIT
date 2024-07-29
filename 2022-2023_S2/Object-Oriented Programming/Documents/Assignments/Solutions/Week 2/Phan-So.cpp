#include <bits/stdc++.h>
using namespace std;
struct Fraction // cấu trúc phân số
{
    int numerator; // tử số
    int pattern; // mẫu số
};
void inputFractional(Fraction &frac); // hàm nhập phân số
int GCD(int numerator, int pattern); // hàm tìm ước chung lớn nhất 
void fractionalShortening(Fraction &frac); // hàm rút gọn phân số
void findFractionalMax(Fraction frac_1, Fraction frac_2); // hàm so sánh 2 phân số
void sumFractions(Fraction frac_1,Fraction frac_2); // hàm tính tổng 2 phân số
void differenceFractions(Fraction frac_1,Fraction frac_2); // hàm tính hiệu 2 phân số
void productFractions(Fraction frac_1,Fraction frac_2); // hàm tính tích 2 phân số
void quotientFractions(Fraction frac_1,Fraction frac_2); // hàm tính hiệu 2 phân số
int main()
{
    Fraction frac_1;
    inputFractional(frac_1);
    cout << "Phan so duoc rut gon la: ";
    fractionalShortening(frac_1);
    Fraction frac_2;
    inputFractional(frac_2);
    findFractionalMax(frac_1,frac_2);
    sumFractions(frac_1, frac_2);
    differenceFractions(frac_1,frac_2);
    productFractions(frac_1,frac_2);
    quotientFractions(frac_1,frac_2);
    return 0;
}
void inputFractional(Fraction &frac)
{
    cout << "Nhap tu so: ";
        cin >>  frac.numerator;
    while(1){
        cout << "Nhap mau so: ";
        cin >> frac.pattern;
        if (frac.pattern != 0) break;
        else cout << "Mau so khong hop le, moi nhap lai!" << endl;
    }
}
int GCD(int x, int y)
{
    x=abs(x); y=abs(y);
    if (x==y) return x;
    if (x>y) return GCD(x-y,y);
    if (x<y) return GCD(x,y-x);
}
void fractionalShortening(Fraction &frac) 
{
    int gcd;
    if (frac.numerator!=0)
        gcd=GCD(frac.numerator, frac.pattern); // gán biến tạm là ước chung lớn nhất của tử và mẫu;
    if (frac.numerator==0) cout << 0;
    else if (frac.numerator%frac.pattern==0) cout << frac.numerator/frac.pattern;
    else 
    {
        if (frac.numerator<0 && frac.pattern<0) 
        {
            frac.numerator=-frac.numerator/gcd;
            frac.pattern=-frac.pattern/gcd;
            cout << frac.numerator << "/" << frac.pattern;
        }
        else if (frac.numerator >0 && frac.pattern<0) 
        {
            frac.numerator=-frac.numerator/gcd;
            frac.pattern=-frac.pattern/gcd;
            cout << frac.numerator << "/" << frac.pattern;
        }
        else {
            frac.numerator=frac.numerator/gcd;
            frac.pattern=frac.pattern/gcd;
            cout << frac.numerator << "/" << frac.pattern;
        }
    } 
    cout << endl;
}
void findFractionalMax(Fraction frac_1, Fraction frac_2)
{
    if(frac_1.numerator*frac_1.pattern>frac_2.numerator*frac_1.pattern) 
    {
        cout << "Phan so lon hon la: ";
        fractionalShortening(frac_1);
    }
    else if (frac_1.numerator*frac_1.pattern<frac_2.numerator*frac_1.pattern)
    {
        cout << "Phan so lon hon la: ";
        fractionalShortening(frac_2);
    }
    else{
        cout << "Hai phan so bang nhau va bang: ";
        fractionalShortening(frac_1);
    }
}
void sumFractions(Fraction frac_1,Fraction frac_2)
{
    cout << "Tong cua 2 phan so tren la: ";
    Fraction frac_Sum;
    frac_Sum.numerator=frac_1.numerator*frac_2.pattern+frac_1.pattern*frac_2.numerator;
    frac_Sum.pattern=frac_1.pattern*frac_2.pattern;
    fractionalShortening(frac_Sum); 
}
void differenceFractions(Fraction frac_1,Fraction frac_2)
{
    cout << "Hieu cua 2 phan so tren la: ";
    Fraction frac_Difference;
    frac_Difference.numerator=frac_1.numerator*frac_2.pattern-frac_1.pattern*frac_2.numerator;
    frac_Difference.pattern=frac_1.pattern*frac_2.pattern;
    fractionalShortening(frac_Difference);
}
void productFractions(Fraction frac_1,Fraction frac_2)
{
    cout << "Tich cua 2 phan so tren la: ";
    Fraction frac_Product;
    frac_Product.numerator=frac_1.numerator*frac_2.numerator;
    frac_Product.pattern=frac_1.pattern*frac_2.pattern;
    fractionalShortening(frac_Product);
}
void quotientFractions(Fraction frac_1,Fraction frac_2)
{
    cout << "Thuong cua 2 phan so tren la: ";
    if (frac_2.numerator==0)
        cout << "error";
    else if (frac_1.numerator==0)
        cout << 0;
    else{
    Fraction frac_Quotient;
    frac_Quotient.numerator=frac_1.numerator*frac_2.pattern;
    frac_Quotient.pattern=frac_1.pattern*frac_2.numerator;
    fractionalShortening(frac_Quotient);
    }
}