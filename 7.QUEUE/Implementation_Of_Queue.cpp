/*
Circular Queue is a linear data structure in which 
the operations are performed based on FIFO 
(First In First Out) principle and the last 
position is connected back to the first position 
to make a circle. It is also called ‘Ring Buffer’. 
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Queue{
T*arr;
int front;
int rear;
int maxSize;
int currentSize;
public:
   Queue(int defaultSize=4)
   {
       front=0;
       maxSize=defaultSize;
       rear=maxSize-1;
       arr=new T[maxSize];
       currentSize=0;
   }

bool isFull()
{
    return currentSize==maxSize;
}
bool isEmpty()
{
    return currentSize==0;
}

   //push:Enqueue which insert data at rear+1
   void push(T data)
   {
       if(!isFull())
       {
           rear=(rear+1)%maxSize;
           arr[rear]=data;
           currentSize++;
       }
   }
   //pop 
   void pop()
   {
       if(!isEmpty())
       {
           front=(front+1)%maxSize;
           currentSize--;
       }
   }
   T getFront()
   {
       return arr[front];
   }
};
int main(){
    Queue<int>Q(10);
    for(int i=1;i<=6;i++)
    {
        Q.push(i);
    }
   // Q.pop();
   // Q.push(8);
    while(!Q.isEmpty())
    {
        cout<<Q.getFront();
        Q.pop();
    }

return 0;
}