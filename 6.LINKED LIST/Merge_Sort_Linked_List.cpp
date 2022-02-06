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
void TakeInput(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAtTail(head,d);
        cin>>d;

    }
}
void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" --> ";
        head=head->next;
    }
}
istream& operator>>(istream&is,Node*&head)
{
    TakeInput(head);
    return is;
}
ostream&operator<<(ostream&os,Node*&head)
{
    Display(head);
    return os;
}
Node*Merge(Node*&head1,Node*&head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }
    Node*result=NULL;
    if(head1->data<=head2->data)
    {
        result=head1;
result->next=Merge(head1->next,head2);
    }
    else{
        result=head2;
        result->next=Merge(head1,head2->next);

    }
    return result;
}
Node*midPoint(Node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node*fast=head->next;
    Node*slow=head;
    if(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}
Node* MergeSort(Node*head)
{
//base case
if(head==NULL||head->next==NULL)
{
    return head;
}
Node*mid=midPoint(head);
Node*a=head;
Node*b=mid->next;
mid->next=NULL;

//2.Recursive Sort
a=MergeSort(a);
b=MergeSort(b);

Node*c=Merge(a,b);
return c;
}

int main(){
Node*head=NULL;
cin>>head;
MergeSort(head);
cout<<head;

return 0;
}