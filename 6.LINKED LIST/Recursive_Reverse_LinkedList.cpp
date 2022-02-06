#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
void InsertAtHead(Node*&head,int d)
{
    Node*n1=new Node(d);
    if(head==NULL)
    {
        head=n1;
        return;
    }
    n1->next=head;
    head=n1;
}

Node*RecursiveReverse(Node*head)
{
    //smallest Linked List

    if(head->next==NULL||head==NULL)
    {
        return head;

    }
    //rec Case
    Node*smallHead=RecursiveReverse(head->next);
    Node*temp=head->next;
    temp->next=head;
    head->next=NULL;
    return smallHead;




}
void TakeInput(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAtHead(head,d);
        cin>>d;

    }
}
void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" --> ";
        head=head->next;

    }
    cout<<"NULL";
}
int main(){
    Node*head=NULL;
    TakeInput(head);
    print(head);
    cout<<"\n";
    head=RecursiveReverse(head);
    print(head);


return 0;
}