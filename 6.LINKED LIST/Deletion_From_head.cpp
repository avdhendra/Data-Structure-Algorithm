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
void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"--> ";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
Node*head=NULL;
for(int i=1;i<5;i++)
{
    InsertAthead(head,i);
}
print(head);
deleteFromHead(head);
cout<<"\n";
print(head);

return 0;
}