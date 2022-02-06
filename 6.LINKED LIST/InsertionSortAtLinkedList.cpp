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
/*Function to Insert a new Node in a List.Note that this
function expects a pointer to head as this can modify the
 head of the input linked List*/
 void SortedInsert(Node*&head,Node*newNode)
 {
     Node*current;
     if(head==NULL || head->data>=newNode->data)
     {
         newNode->next=head;
         head=newNode;
     }
     else
     {
         /*Locate The Node before the Point of Insertion*/
         current=head;
         while(current->next!=NULL and current->next->data<newNode->data)
         {
             current=current->next;
         }
         newNode->next=current->next;
         current->next=newNode;

     }
 }
//Function to sort a Singly Linked List Using Insertion Sort
void InsertionSort(Node*&head)
{
    //Intiallize sorted Linked List
    Node*sorted=NULL;
    //Traverse the Given Linked List and insert every
     //Node to stored
     Node*current=head;
     while(current!=NULL)
     {
         //Store Next for Next iteration
         Node*next=current->next;
         //insert current in Sorted Linked List
         SortedInsert(sorted,current);
         //update current
         current=next;
     }
     //update head to point to sorted linked list
     head=sorted;

}
/*Below function are Just Utility to test SortedInsert*/
void Print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ---> ";
        head=head->next;
    }
    cout<<" NULL ";
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
istream&operator>>(istream&is,Node*&head)
{
TakeInput(head);
return is;
}
ostream&operator<<(ostream&os,Node*&head){
    Print(head);
    return os;
}
int main(){
    Node*head=NULL;
cin>>head;
cout<<head<<endl;
InsertionSort(head);
cout<<head<<endl;


return 0;
}