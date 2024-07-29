#include <bits/stdc++.h>
using namespace std;
class NhaHang
{
    private:
        string name;
        int danh_gia;
        float khoang_cach;
    public:
    NhaHang(){};
    ~NhaHang(){};
    friend istream &operator >> (istream &in, NhaHang &);
    friend ostream &operator << (ostream &out, NhaHang);
    int getDanhGia();
    float getKhoangCach();
    void swapNH(NhaHang&);
};
istream &operator >> (istream &in, NhaHang &A)
{
    cout << "Moi nhap ten nha hang:\n";
    getline(cin, A.name);
    cout << "Moi nhap ty le danh gia muc do tot:\n";
    cin >> A.danh_gia;
    cout << "Moi nhap khoang cach tu trung tam thanh pho toi nha hang:\n";
    cin >> A.khoang_cach;
    cin.ignore();
    return in;
}
ostream &operator << (ostream &out, NhaHang A)
{
    cout << "Ten nha hang: " << A.name << " | ";
    cout << "Ty le danh gia: " << A.danh_gia << " | ";
    cout << "Khoang cach: " << A.khoang_cach;
    return out;
}
int NhaHang::getDanhGia()
{
    return this->danh_gia;
}
float NhaHang::getKhoangCach()
{
    return this->khoang_cach;
}
void NhaHang::swapNH(NhaHang &NH)
{
    swap(this->name, NH.name);
    swap(this->danh_gia, NH.danh_gia);
    swap(this->khoang_cach, NH.khoang_cach);
}

struct NodeNH{
    NhaHang data;
    NodeNH *next;
};

NodeNH* makeNodeNH(NhaHang NH);
void insertLast(NodeNH* &head, NhaHang NH);
void nhapNH(NodeNH* &head);
void xuatNH90(NodeNH* head);
void sapXepNH(NodeNH* head);

NodeNH* makeNodeNH(NhaHang NH)
{
    NodeNH* tmp=new NodeNH();
    tmp->data=NH;
    tmp->next=NULL;
    return tmp;
}
void insertLast(NodeNH* &head, NhaHang NH)
{
    NodeNH* tmp=makeNodeNH(NH);
    if (head==NULL){
        head=tmp;
    }
    else{
        NodeNH *p=head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        p->next=tmp;
    }
}
void nhapNH(NodeNH* &head)
{
    cout << "Nhap danh sach 10 nha hang:\n";
    for (int i=1; i<=10; i++)
    {
        NhaHang NH;
        cin >> NH;
        insertLast(head, NH);
    }
}
void xuatNH90(NodeNH* head)
{
    cout << "Danh sach nha hang co ty le danh gia muc do tot tren 90 la:\n";
    while (head != NULL)
    {
        if (head->data.getDanhGia()>90)
            cout << head->data << endl;
        head=head->next;
    }
}
void sapXepNH(NodeNH* head)
{
    cout << "Danh sach nha hang da duoc sap xep:\n";
    for(NodeNH* p=head; p->next!= NULL; p=p->next)
    {
        NodeNH *max = p; 
        for (NodeNH *q=p->next; q != NULL; q=q->next){
            if (q->data.getDanhGia()>max->data.getDanhGia()){
                max=q;
            }
            else if (q->data.getDanhGia()==max->data.getDanhGia() && q->data.getKhoangCach() < max->data.getKhoangCach())
            {
                max=q;
            }
        } 
        max->data.swapNH(p->data);
    }
    while(head!=NULL)
    {
        cout << head->data << endl;
        head=head->next;
    }
}
int main()
{
    NodeNH *head=NULL;
    nhapNH(head);
    xuatNH90(head);
    sapXepNH(head);
    return 0;
}