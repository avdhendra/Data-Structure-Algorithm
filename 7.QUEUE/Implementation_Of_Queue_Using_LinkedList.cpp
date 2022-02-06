#include<bits/stdc++.h>
using namespace std;
//class for linked List
class LinkedQueue{
    public:
   int data;
   LinkedQueue*next;
   LinkedQueue(int d)
   {
       data=d;
       next=NULL;
   }
};
//class for Queue
class Queue{
    public:
    LinkedQueue*front,*rear;
    Queue()
    {
        front=rear=NULL;
    }
    void push(int x)
    {
        //create new Linked List
        LinkedQueue*n1=new LinkedQueue(x);
        //If Queue is empty ,then
        //new Node is front and rear both
        if(rear==NULL)
        {
            front =rear=n1;
            return;
        }
        //add the new Node at the end of Queue and change rear;
        
        
        while(rear->next!=NULL)
        {
            rear=rear->next;
        }
        rear->next=n1;
        rear=n1;

    }
    //Function to remove 
    //a key from given queue Q
    void pop()
    {
        //If Queue is empty return NULL
        if(front==NULL)
        {
            return;
        }
        //Store previous front and Move front one Node ahead
        LinkedQueue*temp=front;
        front=front->next;
        //If front become NULL,then
        //change rear also as NULL
        if(front==NULL)
        {
            rear=NULL;
        }
        delete(temp);
    }
    
};
int main(){
Queue Q;
for(int i=1;i<=6;i++)
{
    Q.push(i);
}
Q.pop();
Q.push(8);
Q.pop();
while((Q.front)!=NULL)
{
    cout<<(Q.front)->data<<" --> ";
    Q.front=(Q.front)->next;
}
cout<<" NULL ";


return 0;
}