#include <bits/stdc++.h>
using namespace std;
class Tuong{
    private:
        int loai;
        int cs_tan_cong;
        int cap;
    public:
        Tuong(){
            loai=0;
            cs_tan_cong=0;
            cap=1;
        }
        ~Tuong(){}
        void nhap(){
            cin >> this->cs_tan_cong;
        }
        void setCap(int Cap){
            this->cap=Cap;
        }
        int getCap(){
            return this->cap;
        }
        int getCSTC(){
            return this->cs_tan_cong;
        }
        void setCSTC(int ST){
            this->cs_tan_cong=ST;
        }
        void setLoai(int Loai){
            this->loai=Loai;
        }
        int getLoai(){
            return this->loai;
        }
        virtual void xuat(){
            cout << " - " << this->cs_tan_cong << endl;
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
bool khacLoai(Tuong** tuong, int n)
{
    if (n<=1) return 0;
    else {
        for (int i=1; i<n; i++){
            if (tuong[i]->getLoai()!=tuong[0]->getLoai()) {
                return 1;
            }
        }
        return 0;
    }
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
void deletePos(Tuong** tuong, int &n, int &pos){
    for(int i=pos; i<n-1; i++){
        tuong[i]=tuong[i+1];
    }
    pos--;
    n--;
}
void nangCap(Tuong** tuong, int &n, int demS, int demZ, int cap)
{
    int gopS2=demS-demS%3;
    int gopZ2=demZ-demZ%3;
    int j=0, k=0, l=0;
    int tong_st[100];
    for (int i=0; i<n; i++){
        if (tuong[i]->getLoai()==1 && j<gopS2){
            j++;
            if (j%3==1){
                tuong[i]->setCap(cap);
                tong_st[l]=tuong[i]->getCSTC();
            }
            else if (j%3==2){
                tong_st[l]+=tuong[i]->getCSTC();
                deletePos(tuong,n,i);
            }
            else {
                tong_st[l]+=tuong[i]->getCSTC();
                l++;
                deletePos(tuong,n,i);
            }
        }
        else if (tuong[i]->getLoai()==2 && k<gopZ2){
            k++;
            if (k%3==1){
                tuong[i]->setCap(cap);
                tong_st[l]=tuong[i]->getCSTC();
            }
            else if (k%3==2){
                tong_st[l]+=tuong[i]->getCSTC();
                deletePos(tuong,n,i);
            }
            else {
                tong_st[l]+=tuong[i]->getCSTC();
                l++;
                deletePos(tuong,n,i);
            }
        }
    }
    for (int i=0; i<n; i++){
        int j=0;
        if (tuong[i]->getCap()==cap){
            tuong[i]->setCSTC(tong_st[j]*cap);
            j++;
        }
    }
}
void satThuongGayRa(Tuong** tuong, int n, int m)
{
    int demS=demShaco(tuong, n, 1);
    int demZ=n-demS;
    if (demS>=3 || demZ>=3){
        nangCap(tuong, n, demS, demZ, 2);
        demS=demShaco(tuong, n, 2);
        demZ=demZed(tuong, n, 2);
    }
    if (demS>=3 || demZ>=3){
        nangCap(tuong, n, demS, demZ, 3);
    }
    if (khacLoai(tuong,n)){
        for (int i=0; i<n; i++)
            tuong[i]->setCSTC(tuong[i]->getCSTC()+10);
    }
    for (int i=0; i<n; i++){
        if (tuong[i]->getLoai()==1){
            tuong[i]->setCSTC(tuong[i]->getCSTC()*2*m);
        }
        else{
            int cstc=0;
            for (int j=1; j<=m; j++)
                if (j%3==0){
                    cstc+=tuong[i]->getCSTC()*3;
                }
                else{
                    cstc+=tuong[i]->getCSTC();
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
        }
        else
        {
            tuong[i]=new Zed;
            tuong[i]->nhap();
            tuong[i]->setLoai(loai);
        }
    }
    satThuongGayRa(tuong,n,m);
    return 0;
}