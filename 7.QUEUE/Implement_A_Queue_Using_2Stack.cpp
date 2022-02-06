//Impelement a Queue using 2 Stack
#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> S1,S2;
    int currentSize;
    Queue()
    {
        currentSize=0;
    }
    void push(int d)
    {
        //Move all element from S1 to S2
        while(!S1.empty())
        {
         S2.push(S1.top());
         S1.pop();
        }
        //push item into S1
        S1.push(d);
        //push everything back to S1
        while(!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
        currentSize++;
    }
    //Pop an item from the Queue
    int front()
   {
            int x=S1.top();
       
       return x;
       
   }
   void Pop()
   {
       if(!S1.empty())
       {
           S1.pop();;
       }
       else{
           return;
       }
   }
   bool empty()
   {
       return currentSize==0;
   }
};
int main()
{
    Queue Q;
    
    for(int i=1;i<=7;i++)
    {
        Q.push(i);
        
    }
    while(!Q.empty())
    {
        cout<<Q.front()<<endl;
        Q.Pop();
      
    }


}