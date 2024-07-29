#include <bits/stdc++.h>
using namespace std;
class HoangTu{
    private:
        int tien;
        int tri_tue;
        int suc_manh;
    public:
        void setTien(int tien){
            this->tien=tien;
        }
        void setTriTue(int tri_tue){
            this->tri_tue=tri_tue;
        }
        void setSucManh(int suc_manh){
            this->suc_manh=suc_manh;
        }
        int getTien(){
            return this->tien;
        }
        int getTriTue(){
            return this->tri_tue;
        }
        int getSucManh(){
            return this->suc_manh;
        }
        void nhap(){
            cin >> tien >> tri_tue >> suc_manh;
        }
        void xuat(){
            cout << tien << " " << tri_tue << " " << suc_manh;
        }
};
class Cong{
    private:
        int loai;
    public:
        void setLoai(int loai)
        {
            this->loai=loai;
        }
        int getLoai()
        {
            return loai;
        }
        virtual void nhap()=0;
        virtual int DK_qua_cong()=0;
};
class CongGiaoThuong: public Cong{
    private:
        int don_gia;
        int so_hang;
    public:
        void nhap(){
            cin >> don_gia >> so_hang;
        }
        int DK_qua_cong(){
            return don_gia*so_hang;
        }
};
class CongHocThuat: public Cong
{
    private:
        int cs_tri_tue;
    public:
        void nhap(){
            cin >> cs_tri_tue;
        }
        int DK_qua_cong(){
            return cs_tri_tue;
        }
};
class CongSucManh: public Cong
{
    private:
        int cs_suc_manh;
    public:
        void nhap(){
            cin >> cs_suc_manh;
        }
        int DK_qua_cong(){
            return cs_suc_manh;
        }
};
int main()
{
    int n; cin >> n;
    vector <Cong*> cong(n);
    int loai;
    for (int i=0; i<n; i++)
    {
        cin >> loai;
        if (loai ==1)
        {
            cong[i]=new CongGiaoThuong;
            cong[i]->nhap();
            cong[i]->setLoai(loai);
        }
        else if (loai ==2)
        {
            cong[i]=new CongHocThuat;
            cong[i]->nhap();
            cong[i]->setLoai(loai);
        }
        else if (loai ==3)
        {
            cong[i]=new CongSucManh;
            cong[i]->nhap();
            cong[i]->setLoai(loai);
        }
    }
    HoangTu hoang_tu;
    hoang_tu.nhap();
    for (int i=0; i<n; i++)
    {
        if (cong[i]->getLoai()==1)
        {
            int tien=hoang_tu.getTien();
            int DK=cong[i]->DK_qua_cong();
            if (tien>=DK){
                hoang_tu.setTien(tien-DK);
            }
            else{
                hoang_tu.setTien(tien-DK);
                break;
            }
        }
        else if (cong[i]->getLoai()==2)
        {
            int tri_tue=hoang_tu.getTriTue();
            int DK=cong[i]->DK_qua_cong();
            if (tri_tue<DK){
                hoang_tu.setTriTue(-1);
                break;
            }
        }
        else if (cong[i]->getLoai()==3)
        {
            int suc_manh=hoang_tu.getSucManh();
            int DK=cong[i]->DK_qua_cong();
            if (suc_manh>=DK){
                hoang_tu.setSucManh(suc_manh-DK);
            }
            else{
                hoang_tu.setSucManh(suc_manh-DK);
                break;
            }
        }
    }
    if (hoang_tu.getTien()>=0 && hoang_tu.getTriTue()>=0 && hoang_tu.getSucManh()>=0)
        hoang_tu.xuat();
    else 
        cout << -1;
}