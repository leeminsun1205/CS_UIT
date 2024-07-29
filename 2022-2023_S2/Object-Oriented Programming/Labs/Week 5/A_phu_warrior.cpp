#include <bits/stdc++.h>
using namespace std;

class VuKhi{
    public:
        int _loaiVuKhi;
        float _satThuong;
        int _nSuDung;
        VuKhi(){
            _loaiVuKhi=0;
            _satThuong=0;
            _nSuDung=0;
        };
        ~VuKhi(){};
        virtual void nhap(){
            cin >> _satThuong;
            cin >> _nSuDung;
        }
        virtual void buffDame(){
            return;
        };
        void buffDame(float _HP){
            _satThuong=0.1*_HP;
        }
};

class Dao :public VuKhi{
    private:
        float chieuDai;
    public:
        Dao(){};
        ~Dao(){}
        void nhap(){
            VuKhi::nhap();
            cin >> chieuDai;
        }
        void buffDame(){
            _satThuong*=chieuDai;
        }
};

class CungTen :public VuKhi{
    private:
        int nMuiTen;
    public:
        CungTen(){};
        ~CungTen(){}
        void nhap(){
            VuKhi::nhap();
            cin >> nMuiTen;
        }
        void buffDame(){
            _satThuong=_satThuong*nMuiTen/2;
        }
};

class TayKhong :public VuKhi{
    public:
        TayKhong(){};
        ~TayKhong(){}
};

class APhu: public VuKhi{
    public:
        float _HP;
        int _nVuKhi;
        vector <VuKhi*> vuKhi;
        APhu(){}
        ~APhu(){}
        void nhap(){
            int loai;
            cin >> _HP;
            cin >> _nVuKhi;
            for (int i=0; i<_nVuKhi+1; i++){
                if (i<_nVuKhi){
                    cin >> loai;
                    if (loai==1){
                        vuKhi.push_back(new Dao);
                        vuKhi[i]->_loaiVuKhi=1;
                    }
                    else if (loai==2){
                        vuKhi.push_back(new CungTen);
                        vuKhi[i]->_loaiVuKhi=2;
                    }
                    vuKhi[i]->nhap();
                    vuKhi[i]->buffDame();
                }
                else {
                    vuKhi.push_back(new TayKhong);
                    vuKhi[i]->buffDame(_HP);
                    vuKhi[i]->_loaiVuKhi=3;
                }
            }
        }
};
class ThuDu{
    public:
        int _loaiThuDu;
        float _HP;
        float _satThuong;
        ThuDu(){};
        ~ThuDu(){};
        virtual void nhap(){
            cin >> _HP;
            cin >> _satThuong;
        }
        virtual void buffDame(){
            _satThuong*=1.0;
        }
        void setLoai(int loai){
            _loaiThuDu=loai;
        }
        virtual void setNChiuDon(){
            return;
        }
        virtual int getNChiuDon(){
            return 1;
        }
};

class BoTot:public ThuDu{
    private:
        int nChiuDanh;
    public:
        BoTot(){};
        ~BoTot(){};
        void nhap(){
            ThuDu::nhap();
            cin >> nChiuDanh;
        }
        void setNChiuDon(){
            nChiuDanh-=1;
        }
        int getNChiuDon(){
            return this->nChiuDanh;
        }
};

class Ho: public ThuDu{
    public:
        Ho(){}
        ~Ho(){}
        void buffDame(){
            _satThuong*=1.5;
        }
};
class TranChien {
    private:
        APhu aPhu;
        int nThuDu;
        vector <ThuDu*> thuDu;
    public:
        TranChien(){};
        ~TranChien(){};
        void thongTinTranChien(){
            int loai;
            aPhu.nhap();
            cin >> nThuDu;
            for (int i=0; i<nThuDu; i++){
                cin >> loai;
                if (loai==1){
                    thuDu.push_back(new BoTot);
                    thuDu[i]->setLoai(1);
                }
                else{
                    thuDu.push_back(new Ho);
                    thuDu[i]->setLoai(2);
                }
                if (thuDu.size()>0){
                    thuDu[i]->nhap();
                    thuDu[i]->buffDame();
                }
            }
        }
        
        void tanCongThuDu(){
            thuDu[0]->_HP-=aPhu.vuKhi[0]->_satThuong;
            if (aPhu.vuKhi[0]->_loaiVuKhi==1){
                aPhu.vuKhi[0]->_nSuDung-=1;
                if (aPhu.vuKhi[0]->_nSuDung==0){
                    aPhu.vuKhi.erase(aPhu.vuKhi.begin());
                }
            }
            else if(aPhu.vuKhi[0]->_loaiVuKhi==2){
                aPhu.vuKhi[0]->_nSuDung-=2;
                if (aPhu.vuKhi[0]->_nSuDung<=0){
                    aPhu.vuKhi.erase(aPhu.vuKhi.begin());
                }
            }
            else{
                aPhu._HP-=aPhu.vuKhi[0]->_satThuong;
            }
            if (thuDu[0]->_loaiThuDu==1){
                thuDu[0]->setNChiuDon();
            }  
            if (!aPhu.vuKhi.empty() && aPhu.vuKhi[0]->_loaiVuKhi == 3 && aPhu._HP <= 0) {
                aPhu.vuKhi.erase(aPhu.vuKhi.begin());
            }
        }
        void thuDuTanCong(){
            aPhu._HP-=thuDu[0]->_satThuong;
        }
        void ChienDau(){
            while (1){
                if (thuDu.empty()) {
                    break;
                }
                unsigned int N=thuDu.size();
                tanCongThuDu(); 
                if (aPhu._HP<=0 || thuDu.empty()){
                    break;
                }
                if (thuDu[0]->_HP<=0 || thuDu[0]->getNChiuDon()==0){
                    thuDu.erase(thuDu.begin());
                }
                if (thuDu.empty()){
                    break;
                }
                if (thuDu.size()==N){
                    thuDuTanCong();
                }
                if (aPhu._HP<=0){
                    break;
                }
            }
        }
        void ketQuaTranChien(){
            if (aPhu._HP>0){
                cout << "A Phu chien thang, hp con lai: " << aPhu._HP;
                cout << ", so vu khi con lai: " << aPhu.vuKhi.size()-1;
            }
            else{
                cout << "A Phu that bai, so thu du con lai: " << thuDu.size();
            }
        }
};
int main(){
    TranChien tranChien;
    tranChien.thongTinTranChien();
    tranChien.ChienDau();
    tranChien.ketQuaTranChien();
    return 0;
}