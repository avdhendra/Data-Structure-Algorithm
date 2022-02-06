/*
here we use temp varible because we pass head by reference so it will change to original one

*/



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
/*
here we dont use head by reference so we dont need to take extra variable
*/
int length(Node*head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
void InsertAtTail(Node*&head,int d)
{Node*n1=new Node(d);
    if(head==NULL)
    {
        head=n1;
        return ;
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
void InsertAtMiddle(Node*&head,int d,int position)
{
    if(position==0||head==NULL)
    {
        InsertAtHead(head,d);
    }
    else if(position>length(head))
    {
        InsertAtTail(head,d);
    }
    else{
        //take p-1 jump
        int jump=1;
     Node*temp=head;   
    while(jump<=(position-1))
    {
        temp=temp->next;
        jump++;
    }

    //create a new node
    Node*m1=new Node(d);
    m1->next=temp->next;
    temp->next=m1;

    }
}
void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
}
int main(){
Node*head=NULL;
InsertAtTail(head,5);
InsertAtTail(head,2);
InsertAtTail(head,1);
InsertAtTail(head,0);
print(head);
InsertAtMiddle(head,4,3);
InsertAtHead(head,7);
cout<<"\n";
print(head);

return 0;
}