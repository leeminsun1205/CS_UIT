#include <bits/stdc++.h>
using namespace std;
static int nNhanLoai=0;
static int nDevil=0;
class NhanVat{
    public:
        string ten;
        float HP;
        float ATK;
        float DEF;
        virtual void nhap(){
            cin >> ten;
            cin >> HP;
            cin >> ATK;
            cin >> DEF;
        }
        virtual void setHP(int n){
            return;
        };
        virtual void setATK(int n){
            return;
        };
        virtual void setDEF(int n){
            return;
        };
        void xuat(){
            cout << ten << " " << HP << endl;
        }
};

class Guild : public NhanVat{
    protected:
        int loai;
    public:
        void setLoai(int loai){
            this->loai=loai;
        }
        int getLoai(){
            return this->loai;
        }
};

class NhanLoai : public Guild{
    protected:
        string job_class;
    public:
        void nhap(){
            Guild::nhap();
            cin >> job_class;
        }
};
class Human : public NhanLoai{
    public:
};
class Elf : public NhanLoai{
    public:
        void setDEF(int n){
            DEF+=n*0.5*DEF;
        }
};

class BanNhan : public Guild{
    protected:
        string racial_class;
    public:
        void nhap(){
            Guild::nhap();
            cin >> racial_class;
        }
};
class Orc : public BanNhan{
    public:
        void setHP(int n){
            HP=n*1.5*HP;
        }
};
class Golbin : public BanNhan{
    public:
        void setATK(int n){
            ATK+=n*0.1*ATK;
        }
};

class DiHinh : public Guild{
    public:
};
class Vampire : public DiHinh{
    public:
        void setHP(int nNhanLoai){
            HP+=0.1*nNhanLoai*HP;
        }
};
class Devil : public DiHinh{
    public:
        void setATK(int nDevil){
            ATK+=0.1*nDevil*ATK;
        }
        void setDEF(int nDevil){
            DEF+=0.1*nDevil*DEF;
        }
};

class Boss : public NhanVat{
    public:
};
bool cmp(Guild* A, Guild* B){
    return (A->HP < B->HP);
}
class Overload{
    int n;
    Guild** guild;
    Boss boss;
    public:
        void nhap(){
            int loai;
            cin >> n;
            guild=new Guild*[n];
            for (int i=0; i<n; i++){
                cin >> loai;
                if (loai==1){
                    guild[i]=new Human;
                    nNhanLoai++;
                }
                else if (loai==2){
                    guild[i]=new Elf;
                    nNhanLoai++;
                }
                else if (loai==3){
                    guild[i]=new Orc;
                }
                else if (loai==4){
                    guild[i]=new Golbin;
                }
                else if (loai==5){
                    guild[i]=new Vampire;
                }
                else{
                    guild[i]=new Devil;
                    nDevil++;
                }
                guild[i]->nhap();
                guild[i]->setLoai(loai);
            }
            boss.nhap();
        }
        void setChiSo(){
            for (int i=0; i<n; i++){
                if (guild[i]->getLoai()==2){
                    guild[i]->setDEF(1);
                }
                else if (guild[i]->getLoai()==3){
                    guild[i]->setHP(1);
                }
                else if (guild[i]->getLoai()==4){
                    guild[i]->setATK(1);
                }
                else if (guild[i]->getLoai()==5){
                    guild[i]->setHP(nNhanLoai);
                }
                else if (guild[i]->getLoai()==6){
                    guild[i]->setATK(nDevil);
                    guild[i]->setDEF(nDevil);
                }
            }
        }
        float STGayRa(float ATK, float DEF){
            if (ATK>DEF){
                return ATK-DEF;
            }
            return 0;
        }
        void tanCong(float ATK, float DEF, float &HP){

            HP=HP-(STGayRa(ATK,DEF));
        }
        int mauMin(){
            int Min=0;
            for (int i=1; i<n; i++){
                if (guild[i]->HP<guild[Min]->HP)
                    Min=i;
            }
            return Min;
        }
        float tongHP(){
            float tongHP=0;
            for (int i=0; i<n; i++){
                if (guild[i]>0)
                    tongHP+=guild[i]->HP;
            }
            return tongHP;
        }
        void deleteGuild(Guild** &guild, int &n, int m){
            for (int i=m; i<n; i++){
                guild[i]=guild[i+1];
            }
            n--;
        }
        void tranChien(){
            while (1){
                for (int i=0; i<n; i++)
                    if (STGayRa(guild[i]->ATK, boss.DEF)>0){
                        tanCong(guild[i]->ATK, boss.DEF, boss.HP);
                    }
                if (boss.HP<=0) break;
                int m=mauMin();
                tanCong(boss.ATK, guild[m]->DEF, guild[m]->HP);
                if (guild[m]->HP<=0) 
                    deleteGuild(guild, n, m);
                if (n==0) break;
            }
        }
        void xuat(){
            if (boss.HP>0){
                boss.xuat();
            }
            else{
                sort(guild,guild+n,cmp);
                for (int i=0; i<n; i++)
                    guild[i]->xuat();
            }
        }
};
int main(){
    Overload overload;
    overload.nhap();
    overload.setChiSo();
    overload.tranChien();
    overload.xuat();
    return 0;
}