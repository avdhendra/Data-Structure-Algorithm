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
void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<" NULL ";
}
Node*appendk(Node*head,int k)
{
    Node*temp=head;
    Node*fast=head;
    Node*slow=head;
    for(int i=0;i<k &&fast->next!=NULL;i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node*newHead=slow->next;
    slow->next=NULL;
    fast->next=temp;
    return newHead;
}
int main(){
    Node*head=NULL;

    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        InsertAtTail(head,i);
    }
    int k;
    cin>>k;
    k=k%n;
    if(k==0)
    {
        Display(head);
    }
    else{
        head=appendk(head,k);
        cout<<"\n";
        Display(head);
    }


return 0;
}