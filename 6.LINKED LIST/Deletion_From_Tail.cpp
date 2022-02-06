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
void DeleteAtTail(Node*&head)
{
    if(head==NULL)
    {
        return;

    }
    Node* prev=NULL;
    Node*temp=head;
    
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        
    }
    delete temp;
    prev->next=NULL;
    return;

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
    for(int i=1;i<5;i++)
    {
        insertAtTail(head,i);
    }
    print(head);
    DeleteAtTail(head);
    cout<<"\n";
    print(head);
    

return 0;
}