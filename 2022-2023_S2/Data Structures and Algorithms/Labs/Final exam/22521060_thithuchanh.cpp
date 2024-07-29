#include <bits/stdc++.h>
using namespace std;
struct NhanVien{
    int maNV;
    string hoTen;
    int namSinh;
    long long luong;
};
istream &operator >> (istream &in, NhanVien &NV){
    cout << "Nhap ma nhan vien: ";
    in >> NV.maNV;
    cin.ignore();
    cout << "Nhap ho ten nhan vien: ";
    getline(in, NV.hoTen);
    cout << "Nhap nam sinh nhan vien: ";
    in >> NV.namSinh;
    cout << "Nhap muc luong nhan vien: ";
    in >> NV.luong;
    return in;
}
ostream &operator << (ostream &out, NhanVien NV){
    cout << "Ma nhan vien: ";
    out << NV.maNV;
    cout << " | Ho va ten: ";
    out << NV.hoTen;
    cout << " | Nam sinh: ";
    out << NV.namSinh;
    cout << " | Luong: ";
    out << NV.luong;
    return out;
}
struct Node{
    NhanVien data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
void khoiTao(Tree &root){
    root=NULL;
}
Tree taoNode(NhanVien data){
    Tree temp=new Node;
    temp->data=data;
    temp->pLeft=NULL;
    temp->pRight=NULL;
    return temp;
}
void themNV(Tree &root, NhanVien data){
    if (root==NULL){
        root=taoNode(data);
    }
    else{
        if (data.maNV < root->data.maNV){
            themNV(root->pLeft,data);
        }
        else if (data.maNV > root->data.maNV){
            themNV(root->pRight,data);
        }
    }
}
void timNV(Tree root, string hoTen) {
    timNV(root->pLeft, hoTen);
    if(root->data.hoTen == hoTen) {
        cout << "Tim thay nhan vien co ten: " << hoTen << endl;
        cout << root->data;
    }
    timNV(root->pRight, hoTen);
}

void timNodeTheMang(Tree &NodeXoa, Tree &NodeThe) {
    if (NodeThe->pLeft != NULL) {
        timNodeTheMang(NodeXoa, NodeThe->pLeft);
    }
    else {
        NodeXoa->data.maNV = NodeThe->data.maNV;
        NodeXoa->data.namSinh = NodeThe->data.namSinh;
        NodeXoa->data.hoTen = NodeThe->data.hoTen;
        NodeXoa->data.luong = NodeThe->data.luong;
        NodeXoa = NodeThe;
        NodeThe = NodeThe->pRight;
    }
}

void xoaNV(Tree &root, int maNV) {
    if(root != NULL) {
        if(root->data.maNV < maNV) xoaNV(root->pRight, maNV);
        else {
            if(root->data.maNV > maNV) xoaNV(root->pLeft, maNV);
            else {
                Tree NodeXoa = root;
                if(root->pLeft == NULL) root = root->pRight;
                else {
                    if(root->pRight == NULL) root = root->pLeft;
                    else timNodeTheMang(NodeXoa, root->pRight);
                }
                delete NodeXoa;
            }
        }
    }
}
void xuatNV10(Tree root){
    if (root != NULL){
        xuatNV10(root->pRight);
        if (root->data.luong==(long long)10000000){
            cout << root->data << endl;
        }
        xuatNV10(root->pLeft);
    }
}
void quanLy(Tree &root){
    int luaChon;
    while(1){
        system("cls");
        cout << "--------------QuanLy--------------\n";
        cout << "1. Them thong tin nhan vien-------\n";
        cout << "2. Tim kiem nhan vien theo ten----\n";
        cout << "3. Xoa nhan vien theo ma nhan vien\n";
        cout << "4. In ra nhan vien luong 10 trieu-\n";
        cout << "0. Ket thuc chuong trinh!---------\n";
        cout << "Moi nhap lua chon: ";
        cin >> luaChon;
        if (luaChon<0 || luaChon>4){
            cout << "Lua chon khong hop le!\n";
            system("pause");
        }
        else if (luaChon==1){
            NhanVien NV;
            cin >> NV;
            themNV(root, NV);
        }
        else if (luaChon==2){
            string hoTen;
            cout << "Nhap ten nhan vien can tim kiem: ";
            getline(cin, hoTen);
            timNV(root, hoTen);
            system("pause");
        }
        else if (luaChon==3){
            int maNV;
            cout << "Nhap ma so nhan vien can xoa: ";
            cin >> maNV;
            xoaNV(root, maNV);
        }
        else if (luaChon==4){
            xuatNV10(root);
            system("pause");
        }
        else {
            cout << "Ket thuc chuong trinh!";
            break;
        }
    }
}
int main(){
    Tree root;
    khoiTao(root);
    quanLy(root);
    system("pause");
    return 0;
}