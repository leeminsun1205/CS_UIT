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
int tinhChieuCaoCay(Tree root){
    if (root==NULL){
        return 0;
    }
    else{
        if (root->pLeft==NULL && root->pRight==NULL) {
            return 0;
        }
        else {
            return max(tinhChieuCaoCay(root->pLeft), tinhChieuCaoCay(root->pRight))+1;
        }
    }
}
int main(){
    Tree root;
    khoiTao(root);
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        themNodeChoCay(root, x);
    }
    cout << tinhChieuCaoCay(root);
    return 0;
}