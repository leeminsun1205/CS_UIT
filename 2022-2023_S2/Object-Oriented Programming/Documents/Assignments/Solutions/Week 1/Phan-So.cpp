#include <bits/stdc++.h>
using namespace std;
struct Fraction // cấu trúc phân số có dạng tử/mẫu;
{
    int numerator, pattern; // khai báo lần lượt tử số và mẫu số 
}; 
int GCD(int x, int y) // hàm tìm ước chung lớn nhất của tử và mẫu
{
    x=abs(x); y=abs(y);
    if (x==0) return 1;
    if (x==y) return x;
    if (x>y) return GCD(x-y,y);
    if (x<y) return GCD(x,y-x);
}
Fraction Shortening(Fraction &F) // hàm rút gọn phân số
{
    Fraction F1; // khai báo phân số rút gọn F1
    int gcd=GCD(F.numerator, F.pattern); // khởi tạo biến gcd là ước chung lớn nhất của tử số và mẫu số của phân số cần rút gọn
    F1.numerator=F.numerator/gcd; // rút gọn tử số
    F1.pattern=F.pattern/gcd; // rút gọn mẫu số
    if (F1.pattern<0)  // nếu mẫu số bé hơn 0 thì chuẩn hóa lại phân số 
    {
        F1.numerator=-F1.numerator; 
        F1.pattern=-F1.pattern;
    }
    return F1; // trả về phân số đã rút gọn
}
istream& operator >> (istream& in, Fraction &F) // hàm nạp chồng toán tử nhập 2 phân số 
{
    cout << "Tu so: "; 
    in >> F.numerator; // nhập tử số
    while (1)
    {
        cout << "Mau so:";
        in >> F.pattern; // nhập mẫu số
        if (F.pattern != 0) break; // nếu mẫu số khác 0 thì dừng việc nhập
        cout << "Mau so khong duoc phep bang 0! Moi nhap lai." << endl; // nếu mẫu số bằng 0 thì tiếp tục việc nhập
    }
    return in; // trả về giá trị nhập
}
ostream& operator << (ostream& out, Fraction F) // hàm nạp chồng toán tử xuất 2 phân số
{
    cout << F.numerator << "/" << F.pattern; // xuất tử và mẫu của phân số có dạng tử/mẫu
    return out; // trả về kết quả xuất
}
Fraction operator + (Fraction F1, Fraction F2) // hàm nạp chồng toán tử cộng 2 phân số
{
    Fraction Sum;
    Sum.numerator=F1.numerator*F2.pattern+F2.numerator*F1.pattern;
    Sum.pattern=F1.pattern*F2.pattern;
    return Shortening(Sum); // trả về phân số tổng ở dạng rút gọn
}
Fraction operator - (Fraction F1, Fraction F2) // hàm nạp chồng toán tử trừ 2 phân số
{
    Fraction Difference;
    Difference.numerator=F1.numerator*F2.pattern-F2.numerator*F1.pattern;
    Difference.pattern=F1.pattern*F2.pattern;
    return Shortening(Difference); // trả về phân số hiệu ở dạng rút gọn
}
Fraction operator * (Fraction F1, Fraction F2) // hàm nạp chồng toán tử nhân 2 phân số
{
    Fraction Product;
    Product.numerator=F1.numerator*F2.numerator;
    Product.pattern=F1.pattern*F2.pattern;
    return Shortening(Product); // trả về phân số tích ở dạng rút gọn
}
Fraction operator / (Fraction F1, Fraction F2) // hàm nạp chồng toán tử chia 2 phân số
{
    Fraction Quotient;
    Quotient.numerator=F1.numerator*F2.pattern;
    Quotient.pattern=F1.pattern*F2.numerator;
    return Shortening(Quotient); // trả về phân số thương ở dạng rút gọn
}
int main()
{
    Fraction F1,F2;
    cout << "Moi nhap phan so thu nhat." << endl;
    cin >> F1; // nhập phân số F1
    cout << "Moi nhap phan so thu hai." << endl;
    cin >> F2; // nhập phân số F2
    cout << "Phan so thu nhat la: " << Shortening(F1) << endl;
    cout << "Phan so thu hai la: " << Shortening(F2) << endl;
    cout << "Tong 2 phan so la: " << F1+F2 << endl;
    cout << "Hieu 2 phan so la: " << F1-F2 << endl;
    cout << "Tich 2 phan so la: " << F1*F2 << endl;
    Fraction F3=F1/F2; // phân số F3 là thương của F1 và F2
    if (F3.pattern==0) // nếu mẫu số của phân số thương là 0 thì xuấtt ra không thể chia 2 phân số
        cout << "Khong the chia 2 phan so!";
    else 
        cout << "Thuong 2 phan so la: " << F3;
    return 0;
}