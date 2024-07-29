#pragma once
#include <iostream>
using namespace std;
class Elipse
{
    private:
        double truc_dai;
        double truc_ngan;
    public:
        Elipse();
        ~Elipse();
        virtual void nhap();
        virtual void xuat();
};

class HinhTron : public Elipse
{
    private:
        double ban_kinh;
    public:
        HinhTron();
        ~HinhTron();
        void nhap();
        void xuat();
};

class DanhSach
{
    private:
        int so_luong;
        Elipse **hinh;
    public:
        DanhSach();
        ~DanhSach();
        void nhap();
        void xuat();
};