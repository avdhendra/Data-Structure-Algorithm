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
/*Reverse The Linked List in Groups
of size k and returns the pointer
to the new head node

*/

Node*ReverseK(Node*&head,int k)
{
    if(!head)
    return NULL;
    
    Node*current=head;
    Node*prev=NULL;
    Node*nextNode=NULL;
    int count=0;

    while(current!=NULL && count<k)
    {
nextNode=current->next;
current->next=prev;
prev=current;
current=nextNode;
count++;

    }
    if(nextNode!=NULL)
    {
  head->next=  ReverseK(nextNode,k);
    }
    return prev;
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
void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<" NULL ";
}
int main(){
Node*head=NULL;
for(int i=1;i<=6;i++)
{
    InsertAtTail(head,i);
}
Display(head);
cout<<"\n";
Node*rev=ReverseK(head,3);
Display(rev);
return 0;
}