#include <iostream>
#include <vector>
#include <algorithm>
static double TongTS=0;
static int TongSoNam=0;
using namespace std;
class DoiTuong{
    public:
        string ten, sdt, cachthuc;
        int tuoi;
        int ID;
        DoiTuong(){}
        virtual void Nhap(){
            cin>>ten>>tuoi>>sdt;
        }
        virtual double getTaisan(){
            return 0;
        };
        virtual int getNam(){
            return 0;
        };
        virtual string getChucvu(){
            return "";
        }
        ~DoiTuong(){}
};
class ChinhTriGia: public DoiTuong{
    public:
        string chucvu;
        ChinhTriGia(){
            cachthuc="dau tim";
            ID=1;
        }
        void Nhap(){
            DoiTuong::Nhap();
            cin>>chucvu;
        }
        double getTaisan(){
            return 0;
        };
        int getNam(){
            return 0;
        };
        string getChucvu(){
            return chucvu;
        }
        ~ChinhTriGia(){}
};
class DoanhNhan: public DoiTuong{
    public:
        double taisan;
        DoanhNhan(){
            ID=2;
        }
        void Nhap(){
            DoiTuong::Nhap();
            cin>>taisan;
            if(taisan>5) cachthuc="nang";
            else if(taisan>3) cachthuc="binh thuong";
            else cachthuc="nhe";
        }
        double getTaisan(){
            return taisan;
        };
        int getNam(){
            return 0;
        };
        string getChucvu(){
            return "";
        }
        ~DoanhNhan(){}  
};
class TuNhan: public DoiTuong{
    public:
        string toitrang;
        int nam;
        TuNhan(){
            ID=3;
        }
        void Nhap(){
            DoiTuong::Nhap();
            cin>>toitrang>>nam;
            if(nam>20) cachthuc="nang";
            else if(nam>10) cachthuc="binh thuong";
            else cachthuc="nhe";
        }
        double getTaisan(){
            return 0;
        };
        int getNam(){
            return nam;
        };
        string getChucvu(){
            return "";
        }
        ~TuNhan(){}  
};
bool check(vector <DoiTuong*> v, string t)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]->ten==t) return true;
    }
    return false;
}
bool cmp(DoiTuong* d1, DoiTuong* d2)
{
    return d1->ID<d2->ID;
}
int main()
{
    int n, m;
    cin>>n>>m;
    DoiTuong **dt=new DoiTuong*[n];
    vector<DoiTuong*> v;
    for(int i=0; i<n; i++)
    {
        
        int lc; cin>>lc;
        if(lc==1) dt[i]=new ChinhTriGia();
        if(lc==2) dt[i]=new DoanhNhan();
        if(lc==3) dt[i]=new TuNhan();
        dt[i]->Nhap();
        if(check(v,dt[i]->ten)==0)
        {
            DoiTuong *d=new DoiTuong();
            if(lc==1) d=new ChinhTriGia();
            if(lc==2) d=new DoanhNhan();
            if(lc==3) d=new TuNhan();
            d=dt[i];
            v.push_back(d);
        }
    }
    while(v.size()>m)
    {
        v.erase(v.begin());
    }
    if(v.size()==0)
    {
        cout<<"Deathnote trong"<<endl;
        return 0;
    }
    bool has1=false, has2= false, has3=false;
    int cnt1=0, cnt2=0, cnt3=0;
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]->ID==1){
            has1=true;
            cnt1++;
        }
        if(v[i]->ID==2){
            has2=true;
            cnt2++;
        }
        if(v[i]->ID==3){
            has3=true;
            cnt3++;
        }
        TongTS+=v[i]->getTaisan();
        TongSoNam+=v[i]->getNam();
    }
    int j=-1;
    if(has1){
        int max=0;
        for(int i=0; i<cnt1; i++){
            if(v[i]->getChucvu().length()>max) {
                max=v[i]->getChucvu().length();
                j=i;
            }
        }
        cout<<v[j]->ten<<", Chuc vu: "<<v[j]->getChucvu()<<endl;
    }
    if(has2){
        int max=0;
        for(int i=cnt1; i<cnt1+cnt2; i++){
            if(v[i]->getTaisan()>max){
                max=v[i]->getTaisan();
                j=i;
            }
        }
        cout<<"Doanh nhan: "<<TongTS<<" ty dong, Cach thuc chet: "<<v[j]->cachthuc<<endl;
    }
    if(has3){
        int max=0;
        for(int i=cnt1+cnt2; i<cnt1+cnt2+cnt3; i++){
            if(v[i]->getNam()>max){
                max=v[i]->getNam();
                j=i;
            }
        }
        cout<<"Tu nhan: "<<TongSoNam<<", Cach thuc chet: "<<v[j]->cachthuc<<endl;
    }
    return 0;
}