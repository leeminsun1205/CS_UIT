#include <bits/stdc++.h>
using namespace std;
static int dem=0;
class NhomMau{
    protected:
        bool Rh;
        int stt;
    public:
        NhomMau(){}
        ~NhomMau(){}
        void Nhap(){
            char khangNguyenD;
            cout << "Nhap Rhesus (+, -): ";
            cin >> khangNguyenD;
            dem++;
            stt=dem;
            if (khangNguyenD=='+'){
                Rh=true;
            }
            else{
                Rh=false;
            }
        }
        bool GetRh(){ return Rh;}
        virtual bool KTDiTruyen(string, string) =0;
        virtual string GetTen()=0;
        virtual bool TuongThich(string, bool)=0;
        void Xuat1(){
            cout << "Nguoi thu " << stt << ": nhom mau ";
        }
        virtual void Xuat(){
            if (Rh==true){
                cout << "+";
            }
            else cout << "-";
        }
};
class MauO:public NhomMau{
    public:
        MauO(){}
        ~MauO(){}
        bool KTDiTruyen(string me, string cha){
            if (me!="AB" && cha!="AB") {
                return true;
            }
            else return false;
        }
        string GetTen(){
            return "O";
        }
        bool TuongThich(string mauCho, bool RhCho){
            if (Rh==0){
                if (mauCho=="O" && RhCho==0) {
                    return true;
                }
                return false;
            }
            else{
                if (mauCho=="O") {
                    return true;
                }
                return false;
            }
        }
        void Xuat(){
            NhomMau::Xuat1();
            cout << "O";
            NhomMau::Xuat();
        }

};
class MauA:public NhomMau{
    public:
        MauA(){}
        ~MauA(){}
        bool KTDiTruyen(string me, string cha){
            if (me=="A" || me=="AB") {
                return true;
            }
            else {
                if (cha=="A" || cha=="AB") {
                    return true;
                }
                return false;
            }
        }
        string GetTen(){
            return "A";
        }
        bool TuongThich(string mauCho, bool RhCho){
            if (Rh==0){
                if ((mauCho=="A" || mauCho=="O") && RhCho==0) {
                    return true;
                }
                return false;
            }
            else{
                if (mauCho=="A" || mauCho=="O"){
                    return true;
                }
                return false;
            }
        }
        void Xuat(){
            NhomMau::Xuat1();
            cout << "A";
            NhomMau::Xuat();
        }
};
class MauB:public NhomMau{
    public:
        MauB(){}
        ~MauB(){}
        bool KTDiTruyen(string me, string cha){
            if (me=="A" || me=="O"){
                if (cha=="B" || cha=="AB") {
                    return true;
                }
                return false;
            }
            else {
                return true;
            }
        }
        string GetTen(){
            return "B";
        }
        bool TuongThich(string mauCho, bool RhCho){
            if (Rh==0){
                if ((mauCho=="B" || mauCho=="O") && RhCho==0) {
                    return true;
                }
                return false;
            }
            else{
                if (mauCho=="B" || mauCho=="O"){
                    return true;
                }
                return false;
            }
        }
        void Xuat(){
            NhomMau::Xuat1();
            cout << "B";
            NhomMau::Xuat();
        }
};
class MauAB:public NhomMau{
    public:
        MauAB(){}
        ~MauAB(){}
        bool KTDiTruyen(string me, string cha){
            if (me=="A") {
                if(cha=="B" || cha=="AB") {
                    return true;
                }
                return false;
            }
            else if (me=="B"){
                if(cha=="A" || cha=="AB") {
                    return true;
                }
                return false;
            }
            else if (me=="C"){
                if(cha!="O") {
                    return true;
                }
                return false;
            }
            return false;
        }
        string GetTen(){
            return "AB";
        }
        bool TuongThich(string mauCho, bool RhCho){
            if (Rh==0){
                if (RhCho==0) {
                    return true;
                }
                return false;
            }
            return true;
        }
        void Xuat(){
            NhomMau::Xuat1();
            cout << "AB";
            NhomMau::Xuat();
        }
};
class QuanLiMau{
    private:
        int n;
        string luaChon;
        vector<NhomMau*> nhomMau;
        vector <NhomMau*> giaDinh;
    public:
        void NhapThongTin(){
            cout << "Nhap so nguoi can quan ly mau: ";
            cin >> n;
            for (int i=0; i<n; i++){
                system("cls");
                cout << "---------------------QUANLY----------------------\n";
                cout << "Nhap O hoac o cho nguoi co nhom mau O-----------\n";
                cout << "Nhap A hoac a cho nguoi co nhom mau A-----------\n";
                cout << "Nhap B hoac b cho nguoi co nhom mau B-----------\n";
                cout << "Nhap AB hoac ab cho nguoi co nhom mau AB--------\n"; 
                cout << "Nhap nhom mau: ";
                cin >> luaChon;
                if(luaChon=="O" || luaChon=="o"){
                    nhomMau.push_back(new MauO);
                }
                else if(luaChon=="A" || luaChon=="a"){
                    nhomMau.push_back(new MauA);
                }
                else if(luaChon=="B" || luaChon=="b"){
                    nhomMau.push_back(new MauB);
                }
                else if(luaChon=="AB" || luaChon=="ab"){
                    nhomMau.push_back(new MauAB);
                }
                else {
                    cout << "Lua chon khong hop le! Moi nhap lai!\n";
                    system("pause");
                    i--;
                    continue;
                }
                nhomMau[i]->Nhap();
            }
        }
        void KTDiTruyen(){
            
            for (int i=0; i<3; i++){
                system("cls");
                cout << "Nhap thong tin cha, me, con can kiem tra di truyen:\n";
                cout << "---------------------QUANLY----------------------\n";
                cout << "Nhap O hoac o: nhom mau O------------------------\n";
                cout << "Nhap A hoac a: nhom mau A------------------------\n";
                cout << "Nhap B hoac b: nhom mau B------------------------\n";
                cout << "Nhap AB hoac ab: nhom mau AB---------------------\n"; 
                cout << "Nhap theo thu tu cha, me, con--------------------\n";
                cout << "Nhap nhom mau cua ";
                if (i==0) cout << "cha: ";
                else if (i==1) cout << "me: ";
                else cout << "con: ";
                cin >> luaChon;
                if(luaChon=="O" || luaChon=="o"){
                    giaDinh.push_back(new MauO);
                }
                else if(luaChon=="A" || luaChon=="a"){
                    giaDinh.push_back(new MauA);
                }
                else if(luaChon=="B" || luaChon=="b"){
                    giaDinh.push_back(new MauB);
                }
                else if(luaChon=="AB" || luaChon=="ab"){
                    giaDinh.push_back(new MauAB);
                }
                else {
                    cout << "Lua chon khong hop le! Moi nhap lai!\n";
                    system("pause");
                    i--;
                    continue;
                }
                giaDinh[i]->Nhap();
            }
            if (giaDinh[2]->KTDiTruyen(giaDinh[0]->GetTen(), giaDinh[1]->GetTen())){
                    cout << "Phu hop voi quy luat di truyen!\n";
                }
                else {
                    cout << "Khong phu hop voi quy luat di truyen!\n";
                }
        }
        void KTTuongThich(){
            system("cls");
            int X, indexOfX;
            while (1){
                cout << "Nhap X la nguoi chon de kiem tra mau trong danh sach(1<=X<=n): ";
                cin >> X;
                if (X<1 || X>n){
                    cout << "X khong co trong danh sach quan li mau! Moi nhap lai!\n";
                }
                else {
                    break;
                }
            }
            indexOfX=X-1;
            cout << "Nhung nguoi co the cho mau X( ";
            nhomMau[indexOfX]->Xuat();
            cout << "):\n";
            for (int i=0; i<n; i++){
                if (i != indexOfX ){
                    if (nhomMau[indexOfX]->TuongThich(nhomMau[i]->GetTen(),nhomMau[i]->GetRh())) {
                        cout << "-";
                        nhomMau[i]->Xuat();
                        cout << endl;
                    }
                }
            }
            system("pause");
        }
};
int main(){
    QuanLiMau QLM;
    QLM.NhapThongTin();
    QLM.KTTuongThich();
    QLM.KTDiTruyen();
    system("pause");
    return 0;
}