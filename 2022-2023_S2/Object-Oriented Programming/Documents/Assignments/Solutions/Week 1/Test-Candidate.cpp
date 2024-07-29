#include <bits/stdc++.h>
using namespace std;
struct TestCandidate // cấu trúc TestCandidate
{
    string id, name, birthday; // khai báo mã số, tên, ngày sinh
    double math_P, literature_P, english_P; // khai báo điểm toán, văn, anh
};
istream& operator >> (istream& in, TestCandidate &Cdd) // hàm nạp chồng toán tử nhập 
{
    cin.ignore(); // xóa dấu enter để ngăn trôi lệnh
    cout << "Moi nhap ma so sinh vien: ";
    getline(in, Cdd.id); // nhập id
    cout << "Moi nhap ten: ";
    getline(in, Cdd.name); // nhập tên
    cout << "Moi nhap ngay sinh: ";
    getline(in, Cdd.birthday); // nhập ngày sinh
    cout << "Moi nhap diem toan: ";
    in >> Cdd.math_P; // nhập điểm toán
    cout << "Moi nhap diem van: ";
    in >> Cdd.literature_P; // nhập điểm văn
    cout << "Moi nhap diem tieng Anh: ";
    in >> Cdd.english_P; // nhập điểm tiếng anh
    return in; // trả về kết quả nhập
}
ostream& operator << (ostream& out, TestCandidate Cdd) // hàm nạp chồng toán tử xuất
{
    out << "ID:" << Cdd.id << "|";
    out << "Ho va ten: " << Cdd.name << "|";
    out  << "Ngay sinh: " << Cdd.birthday << "|";
    out << "Diem toan: " << Cdd.math_P << "|";
    out << "Diem van: " << Cdd.literature_P << "|";
    out << "Diem tieng Anh: " << Cdd.english_P << endl;
    return out;
}
bool check(TestCandidate Cdd) // hàm kiểm tra những thí sinh có tổng điểm lớn hơn 15
{
    double sum_P=Cdd.math_P+Cdd.literature_P+Cdd.english_P; // khai báo biến tính tổng điểm
    if (sum_P>15) return 1; // nếu tổng điểm >15 thì trả về 1
    return 0; // ngược lại trả về 0
}
int main()
{
    cout << "Moi nhap so luong thi sinh: ";
    int n; cin >> n; // nhập số lượng thí sinh
    vector <TestCandidate> Cdd(n);
    for (int i=0; i<n; i++)
    {
        cout << "Thong tin cua sinh vien thu " << i+1 << " la: " << endl;
        cin >> Cdd[i]; // lần lượt nhập thông tin từng sinh viên
    }
    for (int i=0; i<n; i++)
        if (check(Cdd[i])) cout << Cdd[i]; // kiểm tra và xuất ra thông tin của những sinh viên có tổng điểm lớn hơn 15
    return 0;
}