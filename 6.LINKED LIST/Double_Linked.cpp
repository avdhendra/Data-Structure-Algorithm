#include<bits/stdc++.h>
using namespace std;
class Doubley{
    public:
    int data;
    Doubley*next;
    Doubley*prev;
    Doubley(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
int length(Doubley*head)
{
    int len=1;
    while(head->next!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;

}
void InsertAtTail(Doubley*&head,int d)
{
    Doubley*n1=new Doubley(d);
    if(head==NULL)
    {
        head=n1;
        return;

    }
    Doubley *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n1;
    n1->prev=temp;


}
void InsertAtHead(Doubley*&head,int d)
{
    Doubley*n1=new Doubley(d);
    if(head==NULL)
    {
        head=n1;
        return;
    }
    n1->next=head;
    head->prev=n1;
    head=n1;


}
void InsertAtMiddle(Doubley*&head,int position,int d)
{
    Doubley*n1=new Doubley(d);
    if(head==NULL)
    {
        InsertAtHead(head,d);
    }
    if(position>length(head))
    {
        InsertAtTail(head,d);

    }
    int jump=1;
    Doubley*temp=head;
    

    while(jump<position-1)
    {
        temp=temp->next;
        jump++;

    }
   n1->prev=temp;
   n1->next=temp->next;
   temp->next=n1;
   n1->next->prev=n1;





}
void TakeInput(Doubley*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
       
        InsertAtTail(head,d);
       
       
        cin>>d;
    }
}
void Display(Doubley*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<"NULL";
}

void DisplayReverse(Doubley*head)
{
    cout<<"\n";
   
    if(head==NULL)
    {
        return;
    }
    while(head->next!=NULL)
    {
     head=head->next;

    }
    cout<<"Reverse : ";
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->prev;

    }
    cout<<"NULL";
}
ostream &operator<<(ostream&os,Doubley*&head)
{
    Display(head);
    DisplayReverse(head);
    return os;
}
istream &operator>>(istream&is,Doubley*&head)
{
    TakeInput(head);

    return is;
}
int main(){
    Doubley *head=NULL;
    cin>>head;
    cout<<head<<endl;
InsertAtMiddle(head,2,6);
cout<<head;
    


return 0;
}