#include <bits/stdc++.h>
using namespace std;
class CongTyDaCap{
    protected:
        int ID;
        string ten;
        int coin;
        int soDu;
        int coinNhan;
    public:
        virtual void Nhap(){
            cin >> ten;
        }
        int getID(){
            return ID;
        }
        int getCoin(){
            return coin;
        }
        void setCoin(int coin){
            this->coin=coin;
        }
        void setID(int ID){
            this->ID=ID;
        }
        void setSoDu(int soDu){
            this->soDu=soDu;
        }
        virtual int getLoai()=0;
        virtual int hoaHong(){
            return 0;
        }
        void Xuat(){
            cout << ID << " " << soDu << endl;
        }
};
class GiamDoc : public CongTyDaCap{
    public:
        int getLoai(){
            return 1;
        }
};
class DaiLy : public CongTyDaCap{
    private: 
        int cap;
    public:
        void Nhap(){
            CongTyDaCap::Nhap();
            cin >> cap;
        }
        int getLoai(){
            return 2;
        }
        int hoaHong(){
            return 5+cap*3;
        }
};
class NhaDauTu : public CongTyDaCap{
    private:
        int IDDL;
    public:
        void Nhap(){
            CongTyDaCap::Nhap();
            cin >> IDDL;
        }
        int getLoai(){
            return 3;
        }
};
class QuanLi{
    private:
        int n, m;
        vector <CongTyDaCap*> ctyDaCap;
        vector<vector<pair<int, int>>> lichSuMuaCoin;
    public:
        void Nhap(){
            cin >> n >> m;
            int loai, ID;
            for (int i=0; i<n; i++){
                cin >> ID >> loai;
                if (loai==1){
                    ctyDaCap.push_back(new GiamDoc);
                }
                else if (loai==2){
                    ctyDaCap.push_back(new DaiLy);
                }
                else{
                    ctyDaCap.push_back(new NhaDauTu);
                }
                ctyDaCap[i]->Nhap();
                ctyDaCap[i]->setID(ID);
                for (int i = 0; i < m; i++) {
                    for (int j=0; j<n; j++){
                        if (ctyDaCap[j]->getLoai()!=0){
                            int ID, soCoin;
                            cin >> ID >> soCoin;
                            lichSuMuaCoin[i].push_back(make_pair(ID, soCoin));
                        }
                    }
                }
            }
        }
        int GoiDauTu(double coin)
        {
            if (coin>201) return 3;
            else if(coin>101)return 2;
            else if(coin>0)return 1;
        }
        void TinhToan(){
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (ctyDaCap[j]->getLoai()==2){
                        int ID = lichSuMuaCoin[i][j].first;
                        int soCoin = lichSuMuaCoin[i][j].second;
                        for (int k = 0; k < n; k++) {
                            if (ctyDaCap[k]->getLoai() == ID) {
                                if (ctyDaCap[k]->getLoai()==2){
                                    ctyDaCap[k]->setSoDu(soCoin-ctyDaCap[k]->hoaHong());
                                }
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < ctyDaCap.size(); i++) {
                delete ctyDaCap[i];
            }
        }
        void Xuat(){
            for (int i=0; i<n; i++){
                ctyDaCap[i]->Xuat();
            }
        }
};
int main(){
    QuanLi quanLi;
    quanLi.Nhap();
    quanLi.TinhToan();
    quanLi.Xuat();
    return 0;
}