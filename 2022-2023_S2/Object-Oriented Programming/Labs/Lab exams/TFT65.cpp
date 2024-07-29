#include <bits/stdc++.h>
using namespace std;
set <int> tuongCN;
set <int> tuongTC;
set <int> tuongDauSi;
static int tongGT=0;
class Tuong {
    protected:
        int giaTri;
        int attack;
        int defend;
        float tongST;
    public:
        Tuong(){
            tongST=0;
        }
        void Nhap(){
            cin >> attack;
            cin >> defend;
        }
        virtual void Xuat(){
            cout << " - sat thuong gay ra: " << tongST << endl;
        }
        int getST(){
            return attack;
        }
        void tinhTongST(float ST){
            tongST+=ST;
        }
        void tangST(int ST){
            attack+=ST;
        }
        void tangDF(int DF){
            defend+=DF;
        }
        virtual float buff()=0;
        virtual int getLoai()=0;
};
class Jarvan : public Tuong{
    public:
        void Xuat(){
            cout << "Jarvan";
            Tuong::Xuat();
        }
        int getLoai(){
            return 1;
        }
        float buff(){
            return defend*2;
        }
};
class Reisai : public Tuong{
    public:
        void Xuat(){
            cout << "Reksai";
            Tuong::Xuat();
        }
        int getLoai(){
            return 2;
        }
        float buff(){
            return attack*2;
        }
};
class Sivir : public Tuong{
    public:
        void Xuat(){
            cout << "Sivir";
            Tuong::Xuat();
        }
        int getLoai(){
            return 3;
        }
        float buff(){
            return attack*2;
        }
};
class Illaoi : public Tuong{
    public:
        void Xuat(){
            cout << "Illaoi";
            Tuong::Xuat();
        }
        int getLoai(){
            return 4;
        }
        float buff(){
            return (attack+defend)/2.0;
        }
};
class BanCo{
    private:
        int n, m;
        vector <Tuong*> tuong;
    public:
        void Nhap(){
            int loai;
            cin >> n >> m;
            for (int i=0; i<n; i++){
                cin >> loai;
                if (loai==1){
                    tuong.push_back(new Jarvan);
                    tuongCN.insert(loai);
                    tuongDauSi.insert(loai);
                    tongGT++;
                }
                else if (loai==2){
                    tuong.push_back(new Reisai);
                    tuongDauSi.insert(loai);
                    tuongTC.insert(loai);
                    tongGT+=2;
                }
                else if (loai==3){
                    tuong.push_back(new Sivir);
                    tuongCN.insert(loai);
                    tongGT+=4;
                }
                else{
                    tuong.push_back(new Illaoi);
                    tuongDauSi.insert(loai);
                    tuongTC.insert(loai);
                    tongGT++;
                }
                tuong[i]->Nhap();
            }
        }
        void CuongHoa(){
            if (tuongCN.size()==2){
                for (int i=0; i<n; i++)
                    if (tuong[i]->getLoai()==1 || tuong[i]->getLoai()==3){
                        tuong[i]->tangST(15);
                        tuong[i]->tangDF(15);
                    }
            }
            if (tuongDauSi.size()==2){
                for (int i=0; i<n; i++)
                    if (tuong[i]->getLoai()==1 || tuong[i]->getLoai()==2 || tuong[i]->getLoai()==4){
                        tuong[i]->tangDF(15);
                    }
            }
            else if (tuongDauSi.size()==3){
                for (int i=0; i<n; i++)
                    if (tuong[i]->getLoai()==1 || tuong[i]->getLoai()==2 || tuong[i]->getLoai()==4){
                        tuong[i]->tangDF(30);
                    }
            }
            if (tuongTC.size()==2){
                for (int i=0; i<n; i++)
                    if (tuong[i]->getLoai()==2 || tuong[i]->getLoai()==4){
                        tuong[i]->tangST(30);
                    }
            }
        }
        void VanCo(){
            for (int j=1; j<=m; j++){
                for (int i=0; i<n; i++){
                    if (tuong[i]->getLoai()==2){
                        if (j%4==0)
                            tuong[i]->tinhTongST(tuong[i]->buff());
                        else 
                            tuong[i]->tinhTongST(tuong[i]->getST());
                    }
                    else{
                        tuong[i]->tinhTongST(tuong[i]->buff());
                    }
                }
            }
        }
        void Xuat(){
            for (int i=0; i<n; i++){
                tuong[i]->Xuat();
            }
            cout << "Tong gia tri: " << tongGT;
        }
};
int main(){
    BanCo banCo;
    banCo.Nhap();
    banCo.CuongHoa();
    banCo.VanCo();
    banCo.Xuat();
    return 0;
}