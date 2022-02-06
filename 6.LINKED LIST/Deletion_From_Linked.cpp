#include<bits/stdc++.h>
using namespace std;
class Node{
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
void InsertAthead(Node*&head,int d)
{
    Node*n1=new Node(d);
    if(head==NULL)
    {
        head=n1;
        return;

    }
    n1->next=head;
    head->prev=n1;
    head=n1;

}
void InsertAtTail(Node*&head,int d)
{
    Node*n1=new Node(d);
    if(head==NULL)
    {
        head=n1;
    }
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    n1->prev=temp;
    temp->next=n1;
}
void Display(Node*head)
{
while(head!=NULL)
{
    cout<<head->data<<" --> ";
    head=head->next;
}
cout<<" NULL ";
}
void DeleteFromTail(Node*&head)
{
    if(head==NULL)
    {
        return;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;


}
int main(){
Node*h1=NULL;
for(int i=1;i<6;i++)
{
InsertAthead(h1,i);
}
Display(h1);
DeleteFromTail(h1);
Display(h1);

return 0;
}