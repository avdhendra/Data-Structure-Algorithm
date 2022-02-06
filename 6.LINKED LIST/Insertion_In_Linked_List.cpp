/*
Insertion have different ways;
head
middle
tail

*/
/*
Insertion at Head*/


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
void build()
{

}
/*
if u pass head by value and if function change value of head it will not reflect out of function
so we pass it by reference
*/
void insertAtHead(Node*&head,int d)  //passing the pointer by reference
{

/*if(head==NULL)
{
    head=new Node(d);
    return ;
}*/
Node*n1=new Node(d);
n1->next=head;
head=n1;
}
void print(Node*head)
{
    while(head!=NULL)
    {cout<<head->data<<"--> ";
head=head->next;
    }
}

int main(){
Node*head;
for(int i=1;i<5;i++)
{
    insertAtHead(head,i);
}
print(head);
return 0;
}