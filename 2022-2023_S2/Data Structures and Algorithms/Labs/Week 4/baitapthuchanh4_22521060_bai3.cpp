#include <bits/stdc++.h>
using namespace std;
const int MAX = 31;
int n, a[MAX], con[MAX], C[MAX][MAX];
struct Node{
    int data;
    int chiSo;
    Node *pLeft;
    Node *pRight;
};
typedef Node* TREE;
void themNodeVaoCay(TREE &t, int data)
{
    if (t == NULL){
        Node *p = new Node;
        p->data = a[data];
        p->chiSo = data;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else{
        if (t->data > a[data])
            themNodeVaoCay(t->pLeft, data);
        else
            themNodeVaoCay(t->pRight, data);
    }
}

int tinhSoCon(TREE root) {
    return (root ? con[root->chiSo] : 0);
}

int soHoanVi(TREE root) {
    if (root == NULL) 
        return 1;
    con[root->chiSo] = 1;
    if (root->pLeft==NULL && root->pRight==NULL) {
        return 1;
    }
    int hoanViTrai = soHoanVi(root->pLeft);
    int hoanViPhai = soHoanVi(root->pRight);
    int conTrai = tinhSoCon(root->pLeft);
    int conPhai = tinhSoCon(root->pRight);
    con[root->chiSo] += conTrai + conPhai;
    return hoanViTrai*hoanViPhai*C[conTrai + conPhai][conTrai];
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    TREE root = NULL;
    for (int i=1; i<=n; i++) {
        themNodeVaoCay(root, i);
    }
    for (int i=0; i<=30; i++){
        C[i][0]=1;
    }
    for (int i=1; i<=30; i++)
        for (int j=1; j<=i; j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    cout << soHoanVi(root);
    return 0;
}