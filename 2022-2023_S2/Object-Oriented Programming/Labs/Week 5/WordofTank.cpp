#include <bits/stdc++.h>
using namespace std;
class ThapPhao{
    private:
        int loai_TP;
        float size;
        float st;
        int num_ammos;
    public:
        void setLoaiTP(int loai_TP){
            this->loai_TP=loai_TP;
        }
        int getNumAmmos(){
            return num_ammos;
        }
        void setSize(float size){
            this->size=size;
        }
        float getSize(){
            return size;
        }
        void setST(float st){
            this->st=st;
        }
        float getST(){
            return st;
        }
        virtual void nhap(){
            cin >> num_ammos;
        }
        virtual void xuat()=0;
};
class DongCo{
    private:
        int loai_DC;
        int hp;
        float lit;
        float tieu_thu;
    public:
        void setLoaiDC(int loai_DC){
            this->loai_DC=loai_DC;
        }
        void setHP(int hp){
            this->hp=hp;
        }
        void setTieuThu(float tieu_thu){
            this->tieu_thu=tieu_thu;
        }
        virtual void nhap(){
            cin >> lit;
        }
        float getTieuThu(){
            return this->tieu_thu;
        }
        float getLit()
        {
            return lit;
        }
        virtual void xuat()=0;
};
class XeTang : public ThapPhao, public DongCo{
    private:
        int loai_XT;
        float weight;
        int num_crews;
        float dame;
        float hieu_suat;
    public:
        int getNumCrews(){
            return num_crews;
        }
        void setHieuSuat(float hieu_suat){
            this->hieu_suat=hieu_suat;
        }
        void setDame(float dame){
            this->dame=dame;
        }
        float getDame(){
            return dame;
        }
        void nhap(){
            cin >> loai_XT;
            cin >> weight;
            cin >> num_crews;
            ThapPhao::nhap();
            DongCo::nhap();
            if (loai_XT==1){
                setLoaiTP(1);
                setSize(152);
                setST(num_crews/4.0*getSize()*getNumAmmos());
                setLoaiDC(2);
                setHP(600);
                setTieuThu(450/weight);
            }
            else if (loai_XT==2){
                setLoaiTP(2);
                setSize(76.2);
                setST(3*getSize()*getNumAmmos());
                setLoaiDC(1);
                setHP(500);
                setTieuThu(450/weight);
            }
            else if (loai_XT==3){
                setLoaiTP(3);
                setSize(122);
                setST(3*getSize()*getNumAmmos());
                setLoaiDC(2);
                setHP(600);
                setTieuThu(450/weight);
            }
            else {
                setLoaiTP(4);
                setSize(130);
                setST(num_crews/4.0*getSize()*getNumAmmos());
                setLoaiDC(3);
                setHP(1000);
                setTieuThu(400/weight);
            }
        }
        int getLoaiXT(){
            return loai_XT;
        }
        void xuat(){
            if (loai_XT==1){
                cout << "SU152, ";
            }
            else if (loai_XT==2){
                cout << "KV2, ";
            }
            else if (loai_XT==3){
                cout << "IS, ";
            }
            else {
                cout << "Object279, ";
            }
            cout << "weight: " << weight << ", ";
            cout << "number of crews: " << num_crews << ", ";
            cout << "damage: " << dame << ", ";
            cout << "performance: " << hieu_suat << "%";
            cout << endl;
        }
};
class QuanLy{
    public:
        int n;
        XeTang* xe_tang;
        float km;
        int dan_ban;
        void nhap(){
            cin >> n;
            xe_tang=new XeTang[n];
            for (int i=0; i<n; i++)
                xe_tang[i].nhap();
            cin >> km >> dan_ban;
        }
        void xuat(){
            for (int i=0; i<n; i++){
                if (xe_tang[i].getLoaiXT()==1){
                    xe_tang[i].setDame(xe_tang[i].getST()-xe_tang[i].getNumCrews()/4.0*xe_tang[i].getSize()*dan_ban);
                    xe_tang[i].setHieuSuat((xe_tang[i].getNumAmmos()-dan_ban)*1.0/xe_tang[i].getNumAmmos()*100);
                }
                else if (xe_tang[i].getLoaiXT()==2){
                    xe_tang[i].setDame(xe_tang[i].getST()-3*xe_tang[i].getSize()*dan_ban);
                    xe_tang[i].setHieuSuat((xe_tang[i].getNumAmmos()-dan_ban)*1.0/xe_tang[i].getNumAmmos()*100);
                }
                else if (xe_tang[i].getLoaiXT()==3){
                    xe_tang[i].setDame(xe_tang[i].getST()-3*xe_tang[i].getSize()*dan_ban);
                    xe_tang[i].setHieuSuat((xe_tang[i].getLit()-xe_tang[i].getTieuThu()*km/100)*1.0/xe_tang[i].getLit()*100);
                }
                else {
                    xe_tang[i].setDame(xe_tang[i].getST()-xe_tang[i].getNumCrews()/4.0*xe_tang[i].getSize()*dan_ban);
                    xe_tang[i].setHieuSuat(xe_tang[i].getNumCrews()/4.0*100);
                }
                xe_tang[i].xuat();
            }
        }
};
int main(){
    QuanLy xt;
    xt.nhap();
    xt.xuat();
    return 0;
}