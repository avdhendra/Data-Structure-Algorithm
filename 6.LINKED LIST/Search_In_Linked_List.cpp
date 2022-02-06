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

void insertAtHead(Node*&head,int d)
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
void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" --> ";
        head=head->next;
    }
    cout<<"\n";
}
int main(){
Node*head=NULL;
for(int i=1;i<6;i++)
{
    insertAtHead(head,i);
}
print(head);
bool a=searchElement(head,4);
if(a)
{
    cout<<"element is found";
}
else{
    cout<<"element not present in linked List";
}
return 0;
}