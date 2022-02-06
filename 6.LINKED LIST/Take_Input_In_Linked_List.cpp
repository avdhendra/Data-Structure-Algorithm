#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int d)
    {
        data=d;
        next=NULL;
    }

};
void Push(Node*&head,int d)
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
Push(head,d);
    cin>>d;
}
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
return 0;
}