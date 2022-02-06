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
int length(Node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
bool searchElement(Node*head,int d)
{
    if(head==NULL)
    {
        return false;
    }
int jump=1;
while(jump<=length(head))
{
    if(head->data==d)
    {
        return true;
    }

    head=head->next;
    jump++;
    

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
cout<<"\n";
cout<<length(head);
bool a=searchElement(head,4);
cout<<"\n";
if(a)
{
    cout<<"element is found";
}
else{
    cout<<"element not present in linked List";
}
return 0;
}