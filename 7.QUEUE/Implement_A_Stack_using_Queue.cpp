//Impelement a stack using 2 queue

/*
Method 1 (By making push operation costly)
This method makes sure that newly entered element is 
always at the front of ‘q1’, so that pop operation 
just dequeues from ‘q1’. ‘q2’ is used to put every 
new element at front of ‘q1’.

push(s, x) operation’s step are described below:
Enqueue x to q2
One by one dequeue everything from q1 and enqueue 
to q2.
Swap the names of q1 and q2
pop(s) operation’s function are described below:
Dequeue an item from q1 and return it.

*/


/* Program to implement a stack using two queue*/
#include<iostream>
#include<queue>
using namespace std;
//Method 1
/***
 * Queue Q1 and Q2
 * push()  -> 0(1)
 * pop()   -> 0(N)
 * Top()   -> 0(1)
 * empty() -> 0(1)

*/
template<typename T>
class Stack{
//Two inbuilt queue
queue<T>q1,q2;
//to maintain current number of elements
int current_Size;
public:
Stack()
{
    current_Size=0;
}
void push(T x)
{
    current_Size++;
    //push x first in empty Q2
    q2.push(x);
    //push all the remaining
    //element in Q1 to Q2
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}
void pop()
{
    //if no elements are there in q1
    if(q1.empty())
    {
        return;
    }
    q1.pop();
    current_Size--;
}
T top()
{
    if(q1.empty())
    {
        return -1;
    }
    return q1.front();
}
T size()
{
    return current_Size;
}
bool empty()
{
    return current_Size==0;
}

};

int main()
{
    Stack<int>S;
for(int i=1;i<=6;i++)
{
    S.push(i);
}
cout<<"Current Size : "<<S.size()<<endl;

while(!S.empty())
{
    cout<<S.top()<<" ";
    S.pop();
}

return 0;
}