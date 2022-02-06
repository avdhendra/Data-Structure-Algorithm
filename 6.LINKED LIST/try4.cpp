#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
int length(Node*head)
{
    int len=1;
    while(head->next!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
void InsertAtTail(Node*&head,int d)
{
    Node*n1=new Node(d);
    if(head==NULL)
    {
        head=n1;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n1;
}
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
void DeletionHead(Node*&head)
{
    if(head==NULL)
    {
        return;
    }
    Node*temp=head;
    head=temp->next;
    delete temp;

}
void DeletionTail(Node*&head)
{
    if(head==NULL)
    {
        return;
    }
Node*prev=NULL;
Node*temp=head;
int jump=1;
while(temp->next!=NULL)
{
    prev=temp;
    temp=temp->next;

}
prev->next=NULL;
delete temp;


}

void DeletionMiddle(Node*&head,int Position)
{

Node*temp=head;
if( Position==0)
{
    DeletionHead(head);
}
if(Position>length(head))
{
    DeletionTail(head);
}
int jump=1;
Node*nextNode;
while(jump<=Position-1)
{
    temp=temp->next;
jump++;
}
nextNode=temp->next;
temp->next=nextNode->next;
delete nextNode;

}
void Reverse(Node*&head)
{
    Node*nextNode=head;
    Node*temp=head;
    Node*prev=NULL;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        temp->next=prev;
        prev=temp;
        temp=nextNode;
    }
    head=prev;
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
int main()
{
    Node*head=NULL;
    for(int i=1;i<6;i++)
    {
        InsertAtTail(head,i);
    }
    print(head);
    Reverse(head);
  //  DeletionMiddle(head,3);
    print(head);
}