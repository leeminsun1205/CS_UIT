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
void insertTrue(Node* &head,int x)
{
    Node *p=head, *q=head;
    Node* tmp=makeNode(x);
    while (q->next!=NULL)
    {
        q=q->next;
    }
    if (x<=head->data)
    {
        insertFirst(head,x);
    }
    else if (x>=q->data)
    {
        insertLast(head,x);
    }
    else{
        while (p->next->data<=x)
        {
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;
    }
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
    int x; cin >> x;
    insertTrue(head, x);
    xuatNode(head);
    return 0;
}