#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* makeNode(int data)
{
    Node* tmp=new Node();
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}
void insertFirst(Node* &head, int data)
{
    Node* tmp=makeNode(data);
    if (head==NULL)
        head=tmp;
    else{
        tmp->next=head;
        head=tmp;
    }
}
void insertLast(Node* &head, int data)
{
    Node* tmp=makeNode(data);
    if (head==NULL){
        head=tmp;
    }
    else{
        Node *p=head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        p->next=tmp;
    }
}
void nhapNode(Node* &head, int n)
{
    for (int i=1; i<=n; i++)
    {
        int data;
        cin >> data;
        insertLast(head,data);
    }
}
void daoNguoc(Node *&head)
{
    Node* p=head;
    Node* head2=NULL;
    while (p!=NULL)
    {
        insertFirst(head2,p->data);
        p=p->next;
    }
    head=head2;
}
void xuatNode(Node *head)
{
    while (head!=NULL)
    {
        cout << head->data << " ";
        head=head->next;
    }
}
int main()
{
    Node* head=NULL;
    int n; cin >> n;
    nhapNode(head,n);
    daoNguoc(head);
    xuatNode(head);
    return 0;
}