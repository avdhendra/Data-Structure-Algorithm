// Dequeu or Double ended queue
/***
 * It allow insert and delete ay both ends 
 * InsertFront(): adds an item at the front of Queue
 * InsertRear(): adds an item at the rear of Deque.
 * DeleteFront(): Delete an item from front of Deque
 * DeleteRear(): Delete an item from rear of Deque
 * getFront(): gets the front item from queue
 * getRear(): gets the last item from queue
 * isEmpty(): checks wether Deque is empty or Not
 * isFull()
 * 
*/


#include<bits/stdc++.h>
using namespace std;
class Deque{
    public:
    int front;
    int rear;
    int *Arr;
    int currentSize;
    int maxSize;
    Deque(int d)
    {
maxSize=d;
front=0;
rear=maxSize-1;
Arr=new int[maxSize];
currentSize=0;
    }
    //when the array is full
    bool isFull()
    {
        return currentSize==maxSize;
    }
    //when the array is empty
    bool isEmpty()
    {
        return currentSize==0;
    }
    //we have insert from rear side of array
    //so we increment rear
    void InsertAtRear(int x)
    {
        if(!isFull())
        rear=(rear+1)%maxSize;  //rear say in array limit
        Arr[rear]=x;
        currentSize++;
    }
    void InsertAtFront(int x)
    {
        if(!isFull())
        {
        if(front==0)    // if front is at zero index we cant add another element so we have to 
                         //insert it place of last index because it is and circular array
        {
            front=maxSize-1;
            Arr[front]=x;
            

        }

     else{
        
        front=(front-1)%maxSize;     //else if front is at index 1 then we take it to the index of 0
        Arr[front]=x;
        
        }
    currentSize++;  // we increment the size
    }
    }
    void DeleteFront()
    {
        if(!isEmpty())
        {
           if(front==maxSize-1)     //if we want to delete the element from the front and front point to end then we 
                                     //make the front on 0 indx and delete the size
           {
               front=0;

           }
           else{
front=(front+1)%maxSize;     // else if the front is in the 0 idx then we increment the front and then delete the size
           }
            
            currentSize--;
        }
    }
    void DeleteRear()
    {
        if(!isEmpty())
        {
            if(rear==0)                //if rear is at the front we take the rear to the last index
            {
                rear=maxSize-1;

            }
            else{
                rear=(rear-1)%maxSize;            //we subtract the rear then decrement the size
            }
            
            currentSize--;
        }
    }
    int  getFront()
    {
        return Arr[front];

    }
    int getrear()
    {
        return Arr[rear];
}

};
int main(){
Deque d(100);
cout<<"Insert element at rear end : ";
d.InsertAtRear(5);
d.InsertAtRear(4);
d.InsertAtFront(1);
while(!d.isEmpty())
{
    cout<<d.getFront()<<" ";
    d.DeleteFront();
}



return 0;
}