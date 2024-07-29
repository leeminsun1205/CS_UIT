#include <bits/stdc++.h>
using namespace std;
void chiThi(list <double> lst)
{
    double x, y; int n;
    while (1){
        cin >> n;
        list<double>::iterator it = lst.begin();
        if (n==0){
            cin >> x;
            lst.push_back(x);
        }
        else if (n==1) {
            cin >> x;
            while (it != lst.end()) {
                if (*it==x){
                    lst.erase(it);
                    break;
                }
                it++;
            }
        }
        else if (n==2)
        {
            cin >> x;
            while (it != lst.end()){
                if (*it==x)
                {
                    it=lst.erase(it);
                }
                else it++;
            }
        }
        else if (n==3){
            cin >> x >> y;
            int count=0;
            while (it != lst.end()){
                if (0<=x && x<lst.size() && count==x) *it=y;
                it++;   
                count++;
            }
        }
        else if (n==-1){
            int count=0;
            cout << "[";
            while (it != lst.end()){
                cout << *it;
                if (count != lst.size()-1) cout << ",";
                it++;
                count++;
            }
            cout << "]";
            break;
        }
    }
}
int main()
{
    list <double> lst; 
    chiThi(lst);
    return 0;
}
// Giả sử người ta có nhu cầu sử dụng danh sách liên kết đơn để lưu trữ các số nguyên dương. Hãy thực hiện các yêu cầu sau
// a. Định nghĩa cấu trúc dữ liệu để có thể lưu trữ như yêu cầu
// b. Viết hàm nhập vào các số nguyên dương vào danh fdsách, việc nhập kết thúc khi nhập giá trị -1
// c. Viết hàm in ra các số nguyên tố trong danh sách, nếu danh sách là rỗng là in ra là 0
// d. Viết hàm sắp xếp danh sách theo giá trị của phần tử trong danh sách sao cho giảm dần và in ra màn hình
// e. Viết hàm nhập vào 1 số nguyên dương x và thêm x vào trong danh sách ở câu d sao cho danh sách vẫn đảm bảo giảm dần