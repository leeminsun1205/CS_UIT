#include <bits/stdc++.h>
using namespace std;
class Tuong{
    private:
        int loai;
        int cs_tan_cong;
        int cap;
    public:
        void setCap(int Cap){
            this->cap=Cap;
        }
        int getCap(){
            return this->cap;
        }
        void nhap(){
            cin >> this->cs_tan_cong;
        }
        int getCSTC(){
            return this->cs_tan_cong;
        }
        void setCSTC(int ST){
            this->cs_tan_cong=ST;
        }
        void cuongHoaST(){
            this->cs_tan_cong+=10;
        }
        void setLoai(int Loai){
            this->loai=Loai;
        }
        int getLoai(){
            return this->loai;
        }
        virtual void xuat(){
            cout << " - " << cs_tan_cong << endl;
        }
};
class Shaco : public Tuong{
    public:
        void xuat(){
            cout << "Shaco";
            Tuong::xuat();
        }
};
class Zed : public Tuong{
    public:
        void xuat(){
            cout << "Zed";
            Tuong::xuat();
        }
};
int khacLoai(Tuong** tuong, int n)
{
    if (n==1) return 0;
    else if (n>=2){
        for (int i=1; i<n; i++){
            if (tuong[i]->getLoai()!=tuong[0]->getLoai()) {
                return 1;
            }
        }
        return 0;
    }
    else return 0;
}
int demShaco(Tuong** tuong, int n, int cap)
{
    int dem=0;
    for (int i=0; i<n; i++)
    {
        if (tuong[i]->getCap()==cap && tuong[i]->getLoai()==1) 
            dem++;
    }
    return dem;
}
int demZed(Tuong** tuong, int n, int cap)
{
    int dem=0;
    for (int i=0; i<n; i++)
    {
        if (tuong[i]->getCap()==cap && tuong[i]->getLoai()==2) 
            dem++;
    }
    return dem;
}
void deletePos(Tuong** tuong, int &n, int pos){
    for(int i=pos; i<n-1; i++){
        tuong[i]=tuong[i+1];
    }
    n--;
}
void gopTuong(Tuong** tuong, int &n, int demS, int demZ, int cap)
{
    int gopS2=demS-demS%3;
    int gopZ2=demZ-demZ%3;
    int tong1, tong2;
    int j=0, k=0, l=0;
    int tong_st[100];
    for (int i=0; i<n; i++){
        if (tuong[i]->getLoai()==1 && j<gopS2){
            j++;
            if (j%3==1){
                tuong[i]->setCap(cap);
                tong1=0;
            }
            tong1+=tuong[i]->getCSTC();
            if (j%3==0){
                tong_st[l]=tong1;
                l++;
            }
            if (j%3==0 || j%3==2){
                deletePos(tuong,n,i);
                i--;
            }
        }
        else if (tuong[i]->getLoai()==2 && k<gopZ2){
            k++;
            if (k%3==1){
                tuong[i]->setCap(cap);
                tong2=0;
            }
            tong2+=tuong[i]->getCSTC();
            if (k%3==0){
                tong_st[l]=tong2;
                l++;
            }
            if (k%3==0 || k%3==2){
                deletePos(tuong,n,i);
                i--;
            }
        }
    }
    for (int i=0; i<n; i++){
        int j=0;
        if (tuong[i]->getCap()==cap){
            tuong[i]->setCSTC(tong_st[j]);
            j++;
        }
    }
}
void satThuongGayRa(Tuong** tuong, int n, int m)
{
    int demS=demShaco(tuong, n, 1);
    int demZ=n-demS;
    if (demS>=3 || demZ>=3){
        gopTuong(tuong, n, demS, demZ, 2);
    }
    demS=demShaco(tuong, n, 2);
    demZ=demZed(tuong, n, 2);
    if (demS>=3 || demZ>=3){
        gopTuong(tuong, n, demS, demZ, 3);
    }
    if (khacLoai(tuong,n)){
        for (int i=0; i<n; i++)
            tuong[i]->cuongHoaST();
    }
    for (int i=0; i<n; i++){
        if (tuong[i]->getLoai()==1){
            tuong[i]->setCSTC(tuong[i]->getCSTC()*tuong[i]->getCap()*2*m);
        }
        else if (tuong[i]->getLoai()==2){
            int cstc=0;
            for (int j=1; j<=m; j++)
                if (j%3==0){
                    cstc+=tuong[i]->getCSTC()*tuong[i]->getCap()*3;
                }
                else{
                    cstc+=tuong[i]->getCSTC()*tuong[i]->getCap();
                }
            tuong[i]->setCSTC(cstc);
        }
    }
    for (int i=0; i<n; i++)
        tuong[i]->xuat();
}
int main()
{
    int n, m, loai;
    cin >> n >> m;
    Tuong** tuong= new Tuong*[n];
    for (int i=0; i<n; i++)
    {
        cin >> loai;
        if (loai==1)
        {
            tuong[i]=new Shaco;
            tuong[i]->nhap();
            tuong[i]->setLoai(loai);
            tuong[i]->setCap(1);
        }
        else if (loai==2)
        {
            tuong[i]=new Zed;
            tuong[i]->nhap();
            tuong[i]->setLoai(loai);
            tuong[i]->setCap(1);
        }
    }
    satThuongGayRa(tuong,n,m);
    return 0;
}