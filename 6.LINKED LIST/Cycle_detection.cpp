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
bool Detection(Node*&head)
{
    Node*fast=head->next;
    Node*slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            return true;
        }

    }
    return false;
}
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
void MakeCycle(Node*&head,int pos)
{
    Node*temp=head;
    Node*StartNode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            //start node signify where the cycle start
            StartNode=temp;

        }
        //temp goes till end of linked List
        temp=temp->next;
        count++;
    }
    temp->next=StartNode;
}
void takeInput(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAthead(head,d);
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
    cout<<" NULL ";
}
istream& operator>>(istream&is,Node*&head)
{
    cout<<"Enter the Linked List : ";
    takeInput(head);
    return is;
}
ostream&operator<<(ostream &os ,Node*&head)
{
    cout<<"Linked List : ";
    Display(head);
    return os;
}
int main(){
Node*h1=NULL;
cin>>h1;
cout<<h1<<endl;
MakeCycle(h1,3);
if(Detection(h1))
{
    cout<<"Linked List have Cycle in it : ";

}
else
{
    cout<<"Linked List is not having cycle : ";
}
return 0;
}