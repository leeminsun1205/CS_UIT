#include <bits/stdc++.h>
using namespace std;
static int tong_suc_chua=0;
class Phong{
    private:
        string ten;
        int tang;
        int so_phong;
        int suc_chua;
    public:
        Phong(){
            ten="";
            tang=0;
            so_phong=0;
            suc_chua=0;
        }
        ~Phong(){}
        int getSucChua(){
            return this->suc_chua;
        }
        int getTang(){
            return this->tang;
        }
        string getTen(){
            return this->ten;
        }
        virtual void nhap(){
            cin >> ten >> tang >> so_phong >> suc_chua;
            tong_suc_chua+=suc_chua;
        }
};
class PhongLT : public Phong{
    private:
        int may_lanh;
    public:
        PhongLT(){
            may_lanh=0;
        }
        ~PhongLT(){}
        void nhap(){
            Phong::nhap();
            cin >> may_lanh;
        }
};
class PhongTH : public Phong{
    private:
        int sl_mt;
    public:
        PhongTH(){
            sl_mt=0;
        }
        ~PhongTH(){}
        void nhap(){
            Phong::nhap();
            cin >> sl_mt;
        }
};
class GiangDuong : public Phong{
    private:
        int sl_mc;
    public:
        GiangDuong(){
            sl_mc=0;
        }
        ~GiangDuong(){}
        void nhap(){
            Phong::nhap();
            cin >> sl_mc;
        }
};
class QuanLy{
    private:
        int n;
        int k;
        Phong** phong;
    public:
        QuanLy(){}
        ~QuanLy(){}
        void nhap(){
            int loai;
            cin >> n;
            phong= new Phong*[n];
            for (int i=1; i<=n; i++){
                cin >> loai;
                if (loai==1){
                    phong[i]=new PhongLT;
                    phong[i]->nhap();
                }
                else if (loai==2){
                    phong[i]=new PhongTH;
                    phong[i]->nhap();
                }
                else {
                    phong[i]=new GiangDuong;
                    phong[i]->nhap();
                }
            }
            cin >> k;
        }
        int phongMinK(){
            for (int i=1; i<=n; i++){
                if (phong[i]->getSucChua()>=k){
                    return phong[i]->getSucChua();
                }
            }
            return -1;
        }
        string phongKhitNhat(){
            int Min=1;
            for (int i=1; i<=n; i++){
                if (phong[i]->getSucChua()==phongMinK()){
                    Min=min(Min, phong[i]->getTang());
                }
            }
            for (int i=1; i<=n; i++){
                if (phong[i]->getTang()==Min && phong[i]->getSucChua()==phongMinK()){
                    return phong[i]->getTen();
                }
            }
            return "";
        }
        void xuat(){
            cout << tong_suc_chua << endl;
            if (phongMinK()==-1){
                cout << "NULL";
            }
            else{
                cout << phongKhitNhat();
            }
        }
};
int main(){
    QuanLy phongDH;
    phongDH.nhap();
    phongDH.xuat();
    return 0;
}