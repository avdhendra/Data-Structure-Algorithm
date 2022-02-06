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
void InsertHeadAt(Node*&head,int d)
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
void TakeInput(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertHeadAt(head,d);
        cin>>d;

    }
}
void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<"NULL";
}
Node*merge(Node*head1,Node*head2)
{
if(head1==NULL)
{
    return head2;
}
else if(head2==NULL)
{
    return head1;

}
//New head to start
Node*Result=NULL;
//compare two a and b for smaller element
if(head1->data<=head2->data)
{
    Result=head1;
    Result->next=merge(head1->next,head2);

}
else
{
    Result=head2;
    Result->next=merge(head1,head2->next);
}
return Result;
}
ostream &operator<<(ostream&os,Node*&head)
{
    Display(head);
    return os;
}
istream &operator>>(istream &is,Node*&head)
{
    TakeInput(head);
    return is;
}
int main(){
Node*h1=NULL;
Node*h2=NULL;
cin>>h1>>h2;
Node*h3=merge(h1,h2);
cout<<h3;
return 0;
}