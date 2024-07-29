#include <bits/stdc++.h>
using namespace std;
class CPU {
    private:
        int loai_CPU;
        string ma_CPU;
        string hang_CPU;
        int so_core;
        float xung_nhip;
        float gia_CPU;
    public:
        CPU(){
            hang_CPU="Black";
            so_core=4;
            xung_nhip=1.8;
            gia_CPU=200;
        }
        virtual void nhap(){
            cin >> loai_CPU;
            if (loai_CPU==1){
                so_core=2;
            }
            else if (loai_CPU==2){
                xung_nhip=2.46;
                gia_CPU=400;
            }
            else {
                xung_nhip=2.6;
                hang_CPU="White";
                gia_CPU=600;
            }
            cin >> ma_CPU;
        }
        virtual void xuat(){
            cout << "CPU: " << ma_CPU;
            if (loai_CPU==1){
                cout << " Alpha ";
            }
            else if (loai_CPU==2){
                cout << " Beta ";
            }
            else {
                cout << "Gamma";
            }
            cout << hang_CPU << " ";
            cout << so_core << " " << xung_nhip << " " << gia_CPU << endl;
        }
        float getGiaCPU(){
            return this->gia_CPU;
        }
};
class ManHinh {
    private:
        string ma_MH;
        string hang_SX;
        int do_phan_giai;
        float gia_MH;
        int chong_loa;
    public:
        ManHinh(){
            gia_MH=200;
        }
        virtual void nhap(){
            cin >> ma_MH;
            cin >> hang_SX;
            cin >> do_phan_giai;
            if (do_phan_giai==2){
                cin >> chong_loa;
                if (chong_loa==0){
                    gia_MH=300;
                }
                else {
                    gia_MH=500;
                }
            }
        }
        virtual void xuat(){
            cout << "Man hinh: " << ma_MH << " " << hang_SX;
            if (do_phan_giai==1){
                cout << " HD ";
            }
            else {
                cout << " FullHD ";
            }
            cout << gia_MH;
            if (do_phan_giai==2 && chong_loa==1){
                cout << " " << chong_loa;
            }
            cout << endl;
        } 
        float getGiaMH(){
            return this->gia_MH;
        } 
};
class Vo {
    private:
        string ma_vo;
        int loai_vo;
        string hang_vo;
        int mau_vo;
        float gia_vo;
    public:
        Vo(){
            hang_vo="Black";
            gia_vo=400;
        }
        virtual void nhap(){
            cin >> loai_vo;
            cin >> ma_vo;
            if (loai_vo==2){
                hang_vo="White";
                gia_vo=200;
            }
            cin >> mau_vo;
        }
        virtual void xuat(){
            cout << "Vo smartphone: " << ma_vo;
            if (loai_vo==1){
                cout << " Nhom ";
            }
            else {
                cout << " Nhua ";
            }
            cout << hang_vo;
            if (mau_vo==1){
                cout << " Do ";
            }
            else if (mau_vo==2){
                cout << " Den ";
            }
            else {
                cout << " Xanh ";
            }
            cout << gia_vo << endl;
        }
        float getGiaVo(){
            return this->gia_vo;
        }
};
class Smartphone : public CPU, public ManHinh, public Vo{
    private:
        int dong_SP;
        string ma_SP;
        float gia;
    public:
        void tongGiaLK(){
            this->gia=getGiaCPU()+getGiaMH()+getGiaVo();
        }
        void nhap(){
            cin >> dong_SP;
            tongGiaLK();
            if (dong_SP==1){
                gia*=1.3;
            }
            else if (dong_SP==2){
                gia*=1.5;
            }
            else {
                gia*=1.8;
            }
            cin >> ma_SP;
            CPU::nhap();
            ManHinh::nhap();
            Vo::nhap();
        }
        void xuat(){
            cout << "Smartphone: " << ma_SP;
            if (dong_SP==1){
                cout << " Venus ";
            }
            else if (dong_SP==2){
                cout << " Mars ";
            }
            else {
                cout << " Jupiter ";
            }
            cout << gia << endl;
            CPU::xuat();
            ManHinh::xuat();
            Vo::xuat();
        }
};
int main()
{
    int so_luong;
    cin >> so_luong;
    Smartphone* smartphone=new Smartphone[so_luong];
    for (int i=0; i<so_luong; i++){
        smartphone[i].nhap();
    }
    for (int i=0; i<so_luong; i++){
        smartphone[i].xuat();
    }
}