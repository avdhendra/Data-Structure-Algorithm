#include<bits/stdc++.h>
using namespace std;
class Node1{
    public:
    int data;
    Node1*next;
    Node1*prev;
    Node1(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
class Node2{
    public:
    int data;
    Node2*next;
    Node2(int d)
    {
        data=d;
        next=NULL;
    }
};
int length(Node1*head)
{
    int len=1;
    while(head->next!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;

}                                    
Node2*Merge(Node2*&a,Node2*&b)
{
    if(a==NULL)
    {
        return b;
    }

   else if (b==NULL)
    {
        return a;
    }
    Node2*res=NULL;
    if(a->data<=b->data)
    {
        res=a;
        res->next=Merge(a->next,b);
    }

    else
    {
        res=b;
        res->next=Merge(a,b->next);

    }
    return res;
}
Node2*midPoint(Node2*h2)
{
    Node2 *fast=h2->next;
    Node2* slow =h2;
    while(fast!=NULL && fast->next!=NULL)
    {
slow=slow->next;
fast=fast->next->next;
    }
    return slow;
}
Node2*MergeSort(Node2*h2)
{
    if(h2==NULL || h2->next==NULL)
    {
        return h2;
    }
    Node2* mid=midPoint(h2);
    Node2*start=h2;
    Node2* end=mid->next;
    mid->next=NULL;
    start=MergeSort(start);
    end=MergeSort(end);
    Node2*merg=Merge(start,end);
    return merg;
}
void InsertAthead2(Node2*&head1,int d)
{
    Node2*n1=new Node2(d);
    if(head1==NULL)
    {
        head1=n1;
        return;
    }
    n1->next=head1;
    head1=n1;


}
void InsertAthead1(Node1*&head,int d)
{
Node1*n1=new Node1(d);
if(head==NULL)
{
head=n1;
return;
}


n1->next=head;
head->prev=n1;
head=n1;

}
void TakeInput(Node1*&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAthead1(head,d);
        cin>>d;
    }
}
void TakeInput1(Node2*&head1)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        InsertAthead2(head1,d);
        cin>>d;
    }

}
void Display(Node1*head1)
{
    while(head1!=NULL)
    {
cout<<head1->data<<" --> ";
head1=head1->next;
    }
    cout<<"NULL";
}
void Display1(Node2*head2)
{
    while(head2!=NULL)
    {
        cout<<head2->data<<" --> ";
        head2=head2->next;
    }
    cout<<" NULL ";
}
void Reverse(Node2*&head2)
{
    Node2* currentNode=head2;
    Node2* nextNode=head2;
    Node2*prev=NULL;
    if(head2==NULL || head2->next==NULL)
    {
        return ;

    }
    while(nextNode->next!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prev;
        prev=currentNode;
        currentNode=nextNode;


    }
    head2=prev;
}
Node2*RecursiveReverse1(Node2*&head2)
{
    if(head2==NULL ||  head2->next==NULL)
    {
        return head2;
    }
    Node2*smallhead=RecursiveReverse1(head2->next);
    Node2*temp=head2->next;
    temp->next=head2;
    head2->next=NULL;
    return smallhead;


}
void InsertAtTail(Node1*&head,int d)
{
    Node1*n1=new Node1(d);
    if(head==NULL)
    {
        head=n1;
        return;
    }
    Node1*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    n1->prev=temp;
    temp->next=n1;

}
void InsertAtMiddle(Node1*&head,int position,int d)
{
    Node1*n1=new Node1(d);
    if(head!=NULL||position==0)
    {
        InsertAthead1(head,d);

    }
    if(position>length(head))
    {
InsertAtTail(head,d);
    }
    int jump=1;
    Node1*temp=head;
    while(jump<=position-1)
    {
         temp=temp->next;
         jump++;
    }
    n1->prev=temp;
    n1->next=temp->next;
    temp->next=n1;
    n1->next->prev=n1;
    
}
void Rev(Node1*&head)
{
    Node1*ptr1=head;
    Node1*ptr2=ptr1->next;
ptr1->next=NULL;
ptr1->prev=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    } 
    head=ptr1;
}


int main(){
    Node2*h2=NULL;
    Node1*head=NULL;
    cout<<"Enter element in single Linked List : ";
    TakeInput1(h2);
    cout<<"\n";
    cout<<"Linked List : ";
    Display1(h2);
    cout<<"\n";
   Node2*m= MergeSort(h2);
   cout<<"Sorted Linked List : ";
   Display1(m);
   cout<<"\n";
   Node2*c=RecursiveReverse1(m);
   cout<<"Reverse Linked List : ";
   Display1(c);
   cout<<"\n";
   for(int i=1;i<=5;i++)
   {
       InsertAthead1(head,i);
   }
   cout<<"Double Linked List : ";
   Display(head);
   
   cout<<"Reverse Linked List : ";
   Rev(head);
   Display(head);
   cout<<"\n";
   Node1*head2=NULL;
   for(int i=1;i<6;i++)
   {
       InsertAtTail(head2,i);
   }
   cout<<"Insert At Tail : ";
Display(head2);
cout<<"\n";
cout<<"Insert At Middle : ";
InsertAtMiddle(head2,3,8);
Display(head2);
return 0;
}