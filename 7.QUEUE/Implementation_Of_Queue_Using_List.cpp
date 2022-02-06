#include<iostream>
#include<list> //for doubly linked List
#include<forward_list> //for single linked List
using namespace std;
class Queue{
    public:
    int currentSize;
    list<int>Lists;
    Queue()
    {
        currentSize=0;
    }
  bool isEmpty()
  {
      return currentSize==0;
  }
  void push(int data)
  {
      Lists.push_back(data);
      currentSize=currentSize+1;

  }
  void pop()
  {
      if(!isEmpty())
      {
          currentSize--;
          Lists.pop_front();
      }
  }
  int front()
  {
      return Lists.front();
  }
};
int main()
{
Queue Q;
for(int i=1;i<=6;i++)
{
    Q.push(i);
}
while(!Q.isEmpty())
{
    cout<<Q.front()<<" ";
    Q.pop();
}
return 0;
}