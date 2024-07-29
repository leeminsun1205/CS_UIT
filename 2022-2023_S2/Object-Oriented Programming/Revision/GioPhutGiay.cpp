#include <iostream>
using namespace std;
class ThoiGian{
private:
    int hours, minutes, seconds;
public:
    ThoiGian(){
        hours=0, minutes=0, seconds=0;
    }
    friend istream &operator >> (istream &in, ThoiGian &another){
        cout << "Nhap gio: ";
        in >> another.hours;
        cout << "Nhap phut: ";
        in >> another.minutes;
        cout << "Nhap giay: ";
        in >> another.seconds;
        return in;
    }
    friend ostream &operator << (ostream &out, const ThoiGian &another){
        cout << "Gio: " << another.hours;
        cout << "Phut: " << another.minutes;
        cout << "Giay: " << another.seconds;
        return out;
    }
    ThoiGian &operator ++(){
        if (seconds<59){
            seconds++;
        }
        else{
            seconds=0;
            if (minutes<59){
                minutes++;
            }
            else{
                minutes=0;
                if (hours<23){
                    hours++;
                }
                else {
                    hours=0;
                }
            }
        }
    }
    ThoiGian operator +(const ThoiGian &another){
        if 
    }
};
int main(){

}