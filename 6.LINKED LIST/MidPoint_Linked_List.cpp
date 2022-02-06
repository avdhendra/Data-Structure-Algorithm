//Runner Technique
//Finding midPoint of LinkedList

#include<bits/stdc++.h>
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
Node*MidPoint(Node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node*Slow=head;
    Node*fast=head->next;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        Slow=Slow->next;
    }
    return Slow;
}
void Print(Node*head)
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
Print(head);
cout<<"\n";
head=MidPoint(head);
cout<<head->data<<" ";

return 0;
}