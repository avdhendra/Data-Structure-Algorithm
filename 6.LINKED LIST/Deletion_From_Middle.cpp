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
int length(Node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
void insertAtTail(Node*&head,int d)
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
void deleteFromHead(Node*&head)
{
if(head==NULL)
{
    return;
}
Node*temp=head;
head=head->next;
delete temp;

}
void deleteFromtail(Node*&head)
{
    if(head==NULL)
    {
        return ;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp->next!=NULL)
    {
      prev=temp;
      temp=temp->next;
    }
    delete temp;
    prev->next=NULL;

}
void deleteFromMiddle(Node*&head,int Position)
{
    Node*temp=head;
    if(head==NULL||Position==0)
    {
        return;
    }
    if(Position==1)
    {
        deleteFromHead(head);
        

    }
     if(Position>length(head))
    {
        deleteFromtail(head);
    }

    {
        int jump=1;
        Node*nextNode;

while(jump<=Position-1)
{
    temp=temp->next;
    jump++;
}
nextNode=temp->next;
temp->next=nextNode->next;;
delete nextNode;
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
for(int i=1;i<6;i++)
{
    insertAtTail(head,i);
}
print(head);
cout<<"\n";
deleteFromMiddle(head,4);
cout<<"\n";
print(head);
return 0;
}