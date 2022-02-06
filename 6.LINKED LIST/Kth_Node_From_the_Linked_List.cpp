#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
void InsertAtHead(Node*&head,int d)
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
void takeInput(Node*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAtHead(head,d);
        cin>>d;

    }
}
void Print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" --> ";

        head=head->next;
    }
    cout<<"NULL ";
}
/*
//Kth Node from the last of Linked List
Node*Find(Node*head,int k)
{
    int n=0;
    Node*curr=head;
    //Count the Total Number Node
    while(curr)
    {
        curr=curr->next;
        n++;
    }
    //if the total Number of Node
    if(n>=k)
    {
        //return (n-k+1)th Node from the Begining
        curr=head;
        for(int i=0;i<n-k;i++)
        {
            curr=curr->next;
        }
        return curr;
    }


}
*/
Node*findKthNode(Node*head,int k)
{
    Node*curr=head;
    //Move K Node ahead in the Linked List
    for(int i=0; curr && i<k;i++)
    {
        curr=curr->next;
    }
    //return K is More Than the Total Number of Node in the 
    //Node in the List
    if(curr==NULL)
    {
        return NULL;
    }
    //Move The Head and Curr Parrallel till curr
    //reach the end of the list
    while(curr)
    {
        head=head->next;
        curr=curr->next;

    }
    //Head will Now Contain Kth Node From the End
    return head;

}
int main(){
    Node*head=NULL;
    takeInput(head);
    Print(head);
    cout<<"\n";
    Node*fin=findKthNode(head,3);
    if(fin)
    {
        cout<<" Kth Node "<<fin->data;
    }
    return 0;
    

}