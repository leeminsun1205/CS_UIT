#include <bits/stdc++.h>
using namespace std;
class SinhVien
{
    private:
        string MSSV, tenSV;
        float diemTB;
    public:
    SinhVien();
    ~SinhVien(){};
    string getTenSV();
    string getMSSV();
    float getDTB();
    void nhapTenSV();
    void nhapMSSV();
    void nhapDTB();
    void swapSV(SinhVien&);
    friend ostream &operator << (ostream &out, SinhVien);
};
SinhVien::SinhVien(){
    this->MSSV="";
    this->tenSV="";
    this->diemTB=0;
}
string SinhVien::getTenSV()
{
    return this->tenSV;
}
string SinhVien::getMSSV()
{
    return this->MSSV;
}
float SinhVien::getDTB()
{
    return this->diemTB;
}
void SinhVien::nhapTenSV()
{
    cout << "Moi nhap ho va ten:\n";
    getline(cin,this->tenSV);
}
void SinhVien::nhapMSSV()
{
    cout << "Moi nhap MSSV:\n";
    cin >> this->MSSV;
}
void SinhVien::nhapDTB()
{
    cout << "Moi nhap diem trung binh:\n";
    cin >> this->diemTB;
    cin.ignore();
}
void SinhVien::swapSV(SinhVien &another)
{
    swap(this->tenSV,another.tenSV);
    swap(this->MSSV, another.MSSV);
    swap(this->diemTB,another.diemTB);
}
ostream &operator << (ostream &out, SinhVien sv)
{
    cout << "MSSV: " << sv.MSSV << " | ";
    cout << "Ho va ten: " << sv.tenSV << " | ";
    cout << "DTB: " << sv.diemTB;
}

struct NodeSV
{
    SinhVien data;
    NodeSV *next;
};

NodeSV *makeNodeSV(SinhVien sv);
void insertFirst(NodeSV* &head, SinhVien sv);
void deletePos(NodeSV* &head, int pos);
void nhapSV(NodeSV* &head);
void xuatSV(NodeSV* head);
void timSV(NodeSV* head);
void xoaSV(NodeSV* &head);
void lietKeSV(NodeSV *head);
void xepLoaiSV(NodeSV *head);
void sapXepDTB(NodeSV* &head);

NodeSV *makeNodeSV(SinhVien sv)
{
    NodeSV *tmp=new NodeSV();
    tmp->data=sv;
    tmp->next=NULL;
    return  tmp;
}
void insertFirst(NodeSV* &head, SinhVien sv)
{
    NodeSV* tmp=makeNodeSV(sv);
    if (head==NULL)
        head=tmp;
    else{
        tmp->next=head;
        head=tmp;
    }
}
void deletePos(NodeSV* &head, int pos)
{
    if (pos<=0 || pos >pos+1) return;
    NodeSV *truoc=NULL, *sau=head;
    for (int i=1; i<=pos-1; i++) 
    {   truoc=sau;   
        sau=sau->next;
    }
    if (truoc==NULL){
        head=head->next;
    }
    else 
    {
        truoc->next=sau->next;
    } 
}
void nhapSV(NodeSV* &head)
{
    while (1)
    {
        SinhVien sv;
        sv.nhapTenSV();
        if (sv.getTenSV()==" ") break;
        sv.nhapMSSV();
        sv.nhapDTB();
        insertFirst(head, sv);
    }
}
void xuatSV(NodeSV* head)
{
    while (head!=NULL)
    {
        cout << head->data << endl;
        head=head->next;
    }
}
void timSV(NodeSV* head)
{
    string MSSV;
    cout << "Moi nhap MSSV can tim:\n";
    cin >> MSSV;
    while (head!=NULL)
    {
        if (MSSV==head->data.getMSSV())
        {
            cout << head->data;
            cout << endl;
            break;
        }
        head=head->next;
    }
    if (head==NULL) cout << "Sinh vien co MSSV " << MSSV << " khong co trong lop hoc\n";
}
void xoaSV(NodeSV* &head)
{
    string x; 
    cout << "Nhap MSSV cua sinh vien can xoa khoi danh sach:\n";
    cin >> x;
    int pos=1;
    NodeSV* p=head;
    while(x!=p->data.getMSSV())
    {
        pos++;
        p=p->next;
    }
    if (p==NULL) return;
    else
        deletePos(head, pos);
}
void lietKeSV(NodeSV *head)
{
    cout << "Danh sach nhung sinh vien co diem trung binh lon hon 5:\n";
    while (head != NULL)
    {
        if(head->data.getDTB()>=5) 
        {
            cout << head->data << endl;
        }
        head=head->next;
    }
}
void xepLoaiSV(NodeSV *head)
{
    cout << "Danh sach xep loai sinh vien:\n";
    while (head != NULL)
    {
        if(head->data.getDTB()<=3.6){
            cout << head->data << " | Loai: Yeu" << endl;
        }
        else if (head->data.getDTB()<6.5){
            cout << head->data << " | Loai: Trung binh" << endl;
        }
        else if (head->data.getDTB()<7){
            cout << head->data << " | Loai: Trung binh kha" << endl;
        }
        else if (head->data.getDTB()<8){
            cout << head->data << " | Loai: Kha" << endl;
        }
        else if (head->data.getDTB()<9){
            cout << head->data << " | Loai: Gioi" << endl;
        }
        else {
            cout << head->data << " | Loai: Xuat sac" << endl;
        }
        head=head->next;
    }
}
void sapXepDTB(NodeSV* &head)
{
    cout << "Danh sach sinh vien co diem trung binh tang dan:\n";
    for(NodeSV* p=head; p->next!= NULL; p=p->next)
    {
        NodeSV *min = p; 
        for (NodeSV *q=p->next; q != NULL; q=q->next){
            if (q->data.getDTB()<min->data.getDTB()){
                min=q;
            }
        } 
        min->data.swapSV(p->data);
    }
}
int main()
{
    NodeSV *head=NULL;
    nhapSV(head);
    xuatSV(head);
    timSV(head);
    xoaSV(head);
    lietKeSV(head);
    xepLoaiSV(head);
    sapXepDTB(head);
    xuatSV(head);
    return 0;
}