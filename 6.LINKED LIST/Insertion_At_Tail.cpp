#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

void InsertAtTail(Node*&head,int d)
{
    if(head==NULL)
    {
        head=new Node(d);
    }
    Node*n1=new Node(d);
    head->next=n1;
    

}
void Print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"--> ";
        head=head->next;
    }
    cout<<"NULL";
}
int main(){
    Node*head=NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    Print(head);

return 0;
}