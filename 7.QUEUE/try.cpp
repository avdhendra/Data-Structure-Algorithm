#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{
    public:
    int front;
    int rear;
    T*arr;
    int maxSize;
    int currentSize;
 
  Queue(int Size)
  {
      front=0;
      maxSize=Size;
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
  //member function declaration
void push(T data)
{
    if(!isFull())
    {
        rear=(rear+1)%maxSize;
        arr[rear]=data;
        currentSize++;
    }
}
void pop()
{
    if(!isEmpty())
    {
        front=(front+1)%maxSize;
        currentSize--;
    }
}
T getfront()
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
Q.pop();

Q.push(5);
while(!Q.isEmpty())
{

    cout<<Q.getfront();
    Q.pop();

}
return 0;
}