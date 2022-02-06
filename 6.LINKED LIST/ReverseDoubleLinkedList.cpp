#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;

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
    head->prev=n1;
    n1->next=head;
    head=n1;
}
void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" --> ";
        head=head->next;
    }
    cout<<"NULL";
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
void Reverse(Node*&head)
{
    Node*ptr1=head;
    Node*ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL)
    {
       ptr2->prev=ptr2->next;
       ptr2->next=ptr1;
       ptr1=ptr2;
       ptr2=ptr2->prev;
    }
    head=ptr1;
}
istream&operator>>(istream&in,Node*&head)
{
    TakeInput(head);
    return in;
}
ostream&operator<<(ostream&os,Node*&head)
{
    Display(head);
    return os;
}
int main(){
Node*head=NULL;
cin>>head;
cout<<head;
Reverse(head);
cout<<head;

return 0;
}