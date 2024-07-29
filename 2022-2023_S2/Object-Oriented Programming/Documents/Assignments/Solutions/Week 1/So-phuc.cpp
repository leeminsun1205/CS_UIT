#include <bits/stdc++.h>
using namespace std;
typedef struct ComplexNumber // Cấu trúc số phức có dạng A(a1,a2) với a1 là phần ảo, a2 là phần thực
{
    int real; // Khai báo phần thực
    int imaginary; // Khai báo phần ảo
} ComNum;
istream& operator >> (istream& in, ComNum &z) // nạp chồng toán tử nhập 1 số phức
{
    cout << "Phan thuc: ";
    in >> z.real; // nhập phần thực
    cout << "Phan ao: ";
    in >> z.imaginary; // nhập phần ảo
    return in; // trả về kết quả nhập
}
ostream& operator << (ostream& out, ComNum z) // nạp chồng toán tử xuất 1 số phức
{
    cout << "(" << z.real << "," << z.imaginary << ")"; // xuất ra định dạng của số phức đã nhập 
    return out; // trả về kết quả xuất
}
ComNum operator + (ComNum A, ComNum B) // nạp chồng toán tử cộng 2 số phức
{
    ComNum Sum; // khai báo số phức tổng
    Sum.real=A.real+B.real; // tính phần thực của số phức tổng
    Sum.imaginary=A.imaginary+B.imaginary; // tính phần ảo của số phức tổng
    return Sum; // trả về số phức tổng
}
ComNum operator - (ComNum A, ComNum B) // nạp chồng toán tử trừ 2 số phức
{
    ComNum Difference; // khai báo số phức hiệu
    Difference.real=A.real-B.real; // tính phần thực của số phức hiệu
    Difference.imaginary=A.imaginary-B.imaginary; // tính phần ảo của số phức hiệu
    return Difference; // trả về số phức hiệu
}
ComNum operator * (ComNum A, ComNum B) // nạp chồng toán tử nhân 2 số phức
{
    ComNum Product; // khai báo số phức tích
    Product.real=A.real*B.real-A.imaginary*B.imaginary; // tính phần thực của số phức tích
    Product.imaginary=A.real*B.imaginary+A.imaginary*B.real; // tính phần ảo của số phức tích
    return Product; // trả về số phức tích
}
ComNum operator / (ComNum A, ComNum B) // nạp chồng toán tử chia 2 số phức
{
    ComNum Quotient; // khai báo số phức thương
    Quotient.real=(A.real*B.real+A.imaginary*B.imaginary)/(B.real*B.real+B.imaginary*B.imaginary); // tính phần thực của số phức thương
    Quotient.imaginary=(B.real*A.imaginary-B.imaginary*A.real)/(B.real*B.real+B.imaginary*B.imaginary); // tính phần ảo của số phức thương
    return Quotient; // trả về số phức thương
}
int main()
{
    ComNum A,B; // khai báo 2 số phức A và B
    cout << "Nhap so phuc A." << endl;
    cin >> A; // nhập số phức A
    cout << "Nhap so phuc B." << endl;
    cin >> B; // nhập số phức B
    cout << "Tong 2 so phuc la: " << A+B << endl;
    cout << "Hieu 2 so phuc la: " << A-B << endl;
    cout << "Tich 2 so phuc la: " << A*B << endl;
    cout << "Thuong 2 so phuc la: " << A/B << endl;
    return 0;
}