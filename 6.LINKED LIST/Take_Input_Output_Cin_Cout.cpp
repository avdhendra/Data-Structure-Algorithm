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
void Take_Input(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAthead(head,d);
        cin>>d;

    }
    return;
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
istream & operator >>(istream &is,Node*&head)
{
    Take_Input(head);
    return is;
}
ostream & operator >>(ostream& os,Node*&head)
{
    print(head);
    return os;
}
int main(){
Node*head=NULL;
cin>>head;
cout<<head;
return 0;
}