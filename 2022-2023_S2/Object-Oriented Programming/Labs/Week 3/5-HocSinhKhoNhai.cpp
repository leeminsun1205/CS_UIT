#include <bits/stdc++.h>
using namespace std;
struct DiemSo
{
    float giua_ki;
    float cuoi_ki;
};
struct Date
{
    int ngay, thang, nam;
};
int leapYear(int year)
{
    if (((year%100!=0) && (year%4==0)) || (year%400==0)) return 1;
    return 0;
}
class HocSinh
{
    private:
        string ho_ten;
        Date ngay_sinh;
        DiemSo monVan, monToan, monTA;
        static int dem;
        int stt;
    public:
        HocSinh();
        ~HocSinh(){};
        void nhapThongTin();
        float getDiemVan();
        float getDiemToan();
        float getDiemTA();
        float getDiemTB();
        void xuatThongTin();
        bool kiemTraHsGioi();
};
HocSinh::HocSinh()
{
    this->ho_ten="";
    this->ngay_sinh.ngay=0;
    this->ngay_sinh.thang=0;
    this->ngay_sinh.nam=0;
    this->monVan.giua_ki=0;
    this->monToan.cuoi_ki=0;
    this->monToan.giua_ki=0;
    this->monToan.cuoi_ki=0;
    this->monTA.giua_ki=0;
    this->monTA.cuoi_ki=0;
};
void HocSinh::nhapThongTin()
{
    cin.ignore();
    getline(cin,this->ho_ten);
    char c; 
        cin >> this->ngay_sinh.ngay >> c >> this->ngay_sinh.thang >> c >> this->ngay_sinh.nam;
        while(1){
            if (!leapYear(ngay_sinh.nam) && ngay_sinh.thang==2 && ngay_sinh.ngay==29)
            {
                cin >> this->ngay_sinh.ngay >> c >> this->ngay_sinh.thang >> c >> this->ngay_sinh.nam;
            }
            else break;
        }

    while (1){
        cin >> this->monVan.giua_ki >> this->monVan.cuoi_ki;
        cin >> this->monToan.giua_ki >> this->monToan.cuoi_ki;
        cin >> this->monTA.giua_ki >> this->monTA.cuoi_ki;
        if ((0<=this->monVan.giua_ki && this->monVan.giua_ki <=10)
            && (0<=this->monVan.cuoi_ki && this->monVan.cuoi_ki <=10)
            && (0<=this->monToan.giua_ki && this->monToan.giua_ki <=10)
            && (0<=this->monToan.cuoi_ki && this->monToan.cuoi_ki <=10)
            && (0<=this->monTA.giua_ki && this->monTA.giua_ki <=10)
            && (0<=this->monTA.cuoi_ki && this->monTA.cuoi_ki <=10)) break;
    }
}
float HocSinh::getDiemVan()
{
    return this->monVan.giua_ki*0.3+this->monVan.cuoi_ki*0.7;
}
float HocSinh::getDiemToan()
{
    return this->monToan.giua_ki*0.3+this->monToan.cuoi_ki*0.7;
}
float HocSinh::getDiemTA()
{
    return this->monTA.giua_ki*0.3+this->monTA.cuoi_ki*0.7;
}
float HocSinh::getDiemTB()
{
    return (getDiemVan()+getDiemToan()+getDiemTA())/3;
}
void HocSinh::xuatThongTin()
{
    cout << "Ho ten: " << this->ho_ten << " - Diem trung binh: " << round(getDiemTB()*100)/100 << endl;
}
bool HocSinh::kiemTraHsGioi()
{
    if ((this->ngay_sinh.nam<=2005 
        || (this->ngay_sinh.nam==2006 && this->ngay_sinh.thang==1 && this->ngay_sinh.nam==1))
        && getDiemTB()>8 
        && getDiemVan() >=7 && getDiemToan() >=7 && getDiemTA()>=7
        && this->monVan.giua_ki>=5 && this->monVan.cuoi_ki>=5
        && this->monToan.giua_ki>=5 && this->monToan.cuoi_ki>=5
        && this->monTA.giua_ki>=5 && this->monTA.cuoi_ki>=5) return 1;
    else return 0;
}
bool cmp (HocSinh A, HocSinh B)
{
    return A.getDiemTB()>B.getDiemTB();
}
int main()
{
    int n, k, count=0;
    cin >> n >> k;
    vector <HocSinh> hoc_sinh(n);
    for (int i=0; i<n; i++)
        hoc_sinh[i].nhapThongTin();
    if (k!=0){
    stable_sort(hoc_sinh.begin(), hoc_sinh.end(), cmp);
    for (int i=0; i<n; i++)
        if (hoc_sinh[i].kiemTraHsGioi()) 
        {
            hoc_sinh[i].xuatThongTin();
            count ++;
            if (count==k) break;
        }
    }
    return 0;
}