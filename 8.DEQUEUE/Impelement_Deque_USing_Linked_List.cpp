#include<iostream>
#include<list>
using namespace std;
class Deque{
  public:
    list<int>l1;
    int currentSize;
    Deque()
    {
        currentSize=0;
    }
void InsertFront(int x)
{
    l1.push_front(x); 
    currentSize++; 

}
void InsertRear(int x)
{
    l1.push_back(x);
    currentSize++;
}
void DeleteFromFront()
{
    l1.pop_front();
    currentSize--;
}
void DeleteFromRear()
{
    l1.pop_back();
    currentSize--;
}
bool isEmpty()
{
    return currentSize==0;
}
int getFront()
{
    return l1.front();
}
int getRear()
{
    l1.back();
}

};
int main()
{
Deque D1;
D1.InsertRear(1);
D1.InsertRear(2);
D1.DeleteFromFront();
D1.InsertFront(4);
while(!D1.isEmpty())
{
    cout<<D1.getFront()<<" ";
    D1.DeleteFromFront();
}
}