/***
 In push operation, the new element is always 
 enqueued to q1. In pop() operation, if q2 is
 empty then all the elements except the last,
 are moved to q2. Finally the last element is 
 dequeued from q1 and returned.

push(s, x) operation:
Enqueue x to q1 (assuming size of q1 is unlimited).
pop(s) operation:
One by one dequeue everything except the last element from q1 and enqueue to q2.
Dequeue the last item of q1, the dequeued item is 
result, store it.
Swap the names of q1 and q2
Return the item stored in step 2.

*/
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class Stack{
    public:
    queue<T>q1,q2;
    int current_Size;
    Stack()
    {
        current_Size=0;
    }
    void pop()
    {
        if(q1.empty())
        {
            return;
        }
        //Leave one element in Q1 and 
        //push other in Q2
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        //Pop the only left element
        //from Q1
        q1.pop();
        current_Size--;
        //swap the two queues
        swap(q1,q2);
    }
    void push(T x)
    {
        q1.push(x);
        current_Size++;
    }
    T top()
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        T temp=q1.front();
        q1.pop();
        q2.push(temp);
        swap(q1,q2);
        return temp;
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
    for(int i=1;i<=7;i++)
    {
        S.push(i);
    }
    S.pop();
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
return 0;
}