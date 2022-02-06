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
Node* Reversek(Node*&head,int k)
{
    if(head==NULL|| k==1)
    return head;
Node*temp=new Node(0);
temp->next=head;
Node*current=temp;
Node*nextNode=temp;
Node*prev=temp;
int count =0;
while(current->next!=NULL)
{
    current=current->next;
    count++;
}

while(count>=k)
{
    current=prev->next;
    nextNode=current->next;
    for(int i=1;i<k;i++)
    {
        current->next=nextNode->next;
        nextNode->next=prev->next;
        prev->next=nextNode;
        nextNode=current->next;
    }
    
    prev=current;
    
count-=k;
}
return temp->next;

}

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

void Display(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<" NULL ";
}
int main(){
Node*h1=NULL;
for(int i=1;i<=6;i++)
{
    InsertAtTail(h1,i);
}

Display(h1);
cout<<"\n";
Node*rev=Reversek(h1,3);
Display(rev);
return 0;
}