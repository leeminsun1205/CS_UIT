#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Gun {
    public:
        string _name;
        int _ammo;
        int _magazine;
        float _originDamage;
        float _shootSpeed;
        float _decay;
        string _type;
        const int reloadTime = 2;  
    
        virtual void Input() {
            cin >> _magazine >> _decay;
        }
        
        virtual float getDamage(float time) {
            int currentMagazine = _magazine;
            float damagePerBullet = _originDamage * _decay;
            float currentAmmo = _ammo;
            float bulletFire = 0;
            float totalDamage = 0;
            float timeShoot = 1.0 / getShootingSpeed();
            while(time > 0) {
                if(currentMagazine == 0) break;
                if(currentAmmo == 0) {
                    currentMagazine--;
                    currentAmmo = _ammo;
                    time -= reloadTime;
                }
                else {
                    currentAmmo--;
                    bulletFire++;
                    time -= timeShoot;
                }
            }
            return damagePerBullet * bulletFire;
        }
        float getShootingSpeed() {
            if(_decay == 1) return _shootSpeed;
            return _shootSpeed / 2;
        }
};

class Pistol : public Gun {
    public:
        Pistol() {
            _type = "pistol";
        }
};

class G18 final : public Pistol {
    public:
        G18() {
            _name = "G18";
            _ammo = 12;
            _originDamage = 2;
            _shootSpeed = 1;
        }
};

class M500 final : public Pistol {
    public:
        M500() {
            _name = "M500";
            _ammo = 5;
            _originDamage = 4;
            _shootSpeed = 0.5;
        }
};

class Rifle : public Gun {
    public:
        float _buffDamage;
        Rifle() {
            _type = "Rifle";
        }

        void Input() {
            Gun::Input();
            cin >> _buffDamage;
        }
        float getDamage(float time) {
            int currentMagazine = _magazine;
            float damagePerBullet = _originDamage * _decay + _buffDamage;
            float currentAmmo = _ammo;
            float bulletFire = 0;
            float timeShoot = 1.0 / getShootingSpeed();
            while(time > 0) {
                if(currentMagazine == 0) break;
                if(currentAmmo == 0) {
                    currentMagazine--;
                    currentAmmo = _ammo;
                    time -= reloadTime;
                }
                else {
                    currentAmmo--;
                    bulletFire++;
                    time -= timeShoot;
                }
            }
            return damagePerBullet * bulletFire;
        }
};

class MP40 final : public Rifle {
    public:
        MP40() {
            _name = "MP40";
            _ammo = 20;
            _originDamage = 3;
            _shootSpeed = 5;
        }
};

class AK final : public Rifle {
    public:
        AK() {
            _name = "AK";
            _ammo = 30;
            _originDamage = 5;
            _shootSpeed = 1;
        }
};

class Sniper : public Gun { 
    public:
        Sniper() {
            _type = "Sniper";
        }
        float getDamage(float time) {
            int currentMagazine = _magazine;
            float damagePerBullet = _originDamage * _decay;
            float currentAmmo = _ammo;
            float bulletFire = 0;
            float timeShoot = 1.0 / getShootingSpeed();
            while(time > 0) {
                if(currentMagazine == 0) break;
                if(currentAmmo == 0) {
                    currentMagazine--;
                    currentAmmo = _ammo;
                    time -= reloadTime;
                }
                else {
                    currentAmmo--;
                    bulletFire++;
                    time -= timeShoot;
                    time--;
                }
            }
            return damagePerBullet * bulletFire;
        }
};

class SVD final : public Sniper {
    public:
        SVD() {
            _name = "SVD";
            _ammo = 10;
            _originDamage = 5;
            _shootSpeed = 0.5;
        }
};

class AWM final : public Sniper {
    public:
        AWM() {
            _name = "AWM";
            _ammo = 5;
            _originDamage = 10;
            _shootSpeed = 0.5;
        }
};

int main() {
    int n; cin >> n;
    Gun** guns = new Gun*[n];
    for(int i = 0; i < n; i++) {
        int choice; cin >> choice;
        if(choice == 1) {
            guns[i] = new G18;
        }
        else if(choice == 2) {
            guns[i] = new M500;
        }
        else if(choice == 3) {
            guns[i] = new MP40;
        }
        else if(choice == 4) {
            guns[i] = new AK;
        }
        else if(choice == 5) {
            guns[i] = new SVD;
        }
        else if(choice == 6) {
            guns[i] = new AWM;
        }
        guns[i]->Input();
    }
    float time;
    cin >> time;
    for(int i = 0; i < n; i++) {
        cout << guns[i]->_name << ": " << guns[i]->getDamage(time) << endl;
    }
    return 0;
}