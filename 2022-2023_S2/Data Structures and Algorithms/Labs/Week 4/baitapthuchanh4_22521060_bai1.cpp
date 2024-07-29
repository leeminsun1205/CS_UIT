#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
void khoiTao(Tree &root){
    root=NULL;
}
Tree taoNode(int data){
    Tree temp=new Node;
    temp->data=data;
    temp->pLeft=NULL;
    temp->pRight=NULL;
    return temp;
}
void themNodeChoCay(Tree &root, int data){
    if (root==NULL){
        root=taoNode(data);
    }
    else{
        if (data<root->data){
            themNodeChoCay(root->pLeft, data);
        }
        else{
            themNodeChoCay(root->pRight, data);
        }
    }
}
void timPhanTuTheCho(Tree &NodeXoa, Tree &NodeThe){
    if (NodeThe->pLeft!=NULL){
        timPhanTuTheCho(NodeXoa, NodeThe->pLeft);
    }
    else{
        NodeXoa->data=NodeThe->data;
        NodeXoa=NodeThe;
        NodeThe=NodeThe->pRight;
    }
}
void xoaNode(Tree &root, int data){
    if (root==NULL){
        return;
    }
    else{
        if(data<root->data){
            xoaNode(root->pLeft, data);
        }
        else if(data>root->data){
            xoaNode(root->pRight, data);
        }
        else{ 
            Tree NodeXoa=root;
            if (root->pLeft==NULL){
                root=root->pRight;
            }
            else if (root->pRight==NULL){
                root=root->pLeft;
            }
            else{
                timPhanTuTheCho(NodeXoa, root->pRight);
            } 
            delete NodeXoa;
        }
    }
}
void timKiem(Tree root, int data){
    if (root==NULL){
        cout << "Khong tim thay nut " << data << " trong cay\n";
    }
    else{
        if (data<root->data){
            timKiem(root->pLeft, data);
        }
        else if (data>root->data){
            timKiem(root->pRight, data);
        }
        else{
            cout << "Tim thay nut " << data << " trong cay\n";
        }
    }
}
void duyet_NLR(Tree root){
    if (root != NULL){
        cout << root->data << " ";
        duyet_NLR(root->pLeft);
        duyet_NLR(root->pRight);
    }
}
void duyet_LRN(Tree root){
    if (root != NULL){
        duyet_LRN(root->pLeft);
        duyet_LRN(root->pRight);
        cout << root->data << " ";
    }
}
void duyet_LNR(Tree root){
    if (root != NULL){
        duyet_LNR(root->pLeft);
        cout << root->data << " ";
        duyet_LNR(root->pRight);
    }
}
void Menu(Tree &root){
    while(1)
    {
        system("cls");
        cout << "==============MENU=============\n";
        cout << "1. Them node vao cay \n";
        cout << "2. Xoa node trong cay\n";
        cout << "3. Tim kiem phan tu trong cay\n";
        cout << "4. Xuat du lieu theo NLR\n"; 
        cout << "5. Xuat du lieu theo LRN\n";
        cout << "6. Xuat du lieu theo LNR\n";
        cout << "0. Ket thuc\n";
        cout << "===============================\n";
        int lua_chon;
        cout << "Nhap lua chon: ";
        cin >> lua_chon;
        if (lua_chon<0 || lua_chon>6)
        {
            cout << "Lua chon khong hop le!\n";
            system("pause");
        }
        else if (lua_chon==1)
        {
            int x;
            cout << "Nhap so nguyen x can them: ";
            cin >> x;
            themNodeChoCay(root,x);
        }
        else if (lua_chon==2){
            int data;
            cout << "Nhap data nut can xoa: ";
            cin >> data;
            xoaNode(root, data);
        }
        else if (lua_chon==3){
            int data; 
            cout << "Nhap data nut can tim kiem: ";
            cin >> data;
            timKiem(root, data);
            system("pause");
        }
        else if (lua_chon==4){
            cout << "Cay duoc duyet theo thu tu NLR:\n";
            duyet_NLR(root);
            cout << endl;
            system("pause");
        }
        else if (lua_chon==5){
            cout << "Cay duoc duyet theo thu tu LRN:\n";
            duyet_LRN(root);
            cout << endl;
            system("pause");
        }
        else if (lua_chon==6){
            cout << "Cay duoc duyet theo thu tu LNR:\n";
            duyet_LNR(root);
            cout << endl;
            system("pause");
        }
        else {
            cout << "Chuong trinh ket thuc!\n";
            break;
        }
    }
}
int main()
{
    Tree root;
    khoiTao(root);
    Menu(root);
    system("pause");
    return 0;
}
