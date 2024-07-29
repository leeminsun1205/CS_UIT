#include <iostream>
using namespace std;
class IntArr {
private:
    int count; // tổng số lượng phần tử có trong values
    int* values; // mảng các số nguyên đang có trong đối tượng hiện tại
public: /* Sinh viên bổ sung đầy đủ các thành phần cần thiết để hàm main hoạt động như mong đợi */
    IntArr(){
        count=0;
        values=NULL;
    }
    IntArr(int count, int ivalues){
        this->count=count;
        for (int i=0; i<this->count; i++)
            values[i]=ivalues;
    }
    IntArr(int count){
        this->count=count;
        for (int i=0; i<this->count; i++)
            values[i]=0;
    }
    IntArr concat(const IntArr &l3){
        IntArr temp(this->count+l3.count);
        for (int i=0; i<this->count; i++){
            temp.values[i]=this->values[i];
        }
        for (int i=0; i<l3.count; i++){
            temp.values[i+this->count]=l3.values[i];
        }
        return temp;
    }
    void push(int ivalues){
        IntArr temp(1, ivalues);
        *this=this->concat(temp);
    }
    friend istream& operator >> (istream &in, IntArr &another){
        delete []another.values;
        in >> another.count;
        another.values=new int[another.count];
        for (int i=0; i<another.count; i++){
            in >> another.values[i];
        }
        return in;
    }
    friend ostream& operator << (ostream &out, const IntArr& another){
        for (int i=0; i<another.count; i++){
            out << another.values[i] << " ";
        }
        return out;
    }
};
int main(){
    IntArr l1; // tạo mảng không chứa bất kì phần tử nào
    IntArr l2(3, 2); /* tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị
    là 2 */
    IntArr l3(2);//tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
    IntArr l4 = l2.concat(l3); /* tạo ra một IntArr mới có nội dung là kết quả
    của việc nối các phần tử l3 vào cuối các phần tử của l2 theo thứ tự */
    l2.push(3); // thêm số 3 vào cuối danh sách trong đối tượng l2
    cin >> l2; /* Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập
    số lượng phần tử mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ
    không sử dụng nếu có) */
    cout << l2; // in ra các số nguyên có trong danh sách
    /* Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho
    các values của IntArr */
return 0;
}