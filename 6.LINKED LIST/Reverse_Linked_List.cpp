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
void reverseList(Node*&head)
{
    Node*currentNode=head;
    Node*prev=NULL;
    Node*nextNode=head;
    while(nextNode!=NULL)
    {
        //save the next Node
        nextNode=nextNode->next;
        //make the current node point to prev
        currentNode->next=prev;
        //just update prev and current
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
    Node *head=NULL;
    for(int i=1;i<6;i++)
    {
        InsertAtHead(head,i);
    }
    print(head);
    cout<<"\n";
    reverseList(head);
    print(head);

return 0;
}