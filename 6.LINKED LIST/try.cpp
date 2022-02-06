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
void InsertAthead(Node*&head,int d)
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
        InsertAthead(head,d);
        cin>>d;
    }
}
void Reverse(Node*&head)
{
Node*currentNode=head;
Node*nextNode=head;
Node*prev=NULL;
while(nextNode!=NULL)
{
    nextNode=nextNode->next;
     
     currentNode->next=prev;
     prev=currentNode;
     currentNode=nextNode;

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
int main(){
Node*head=NULL;
TakeInput(head);
print(head);
Reverse(head);
cout<<"\n";
print(head);

return 0;
}