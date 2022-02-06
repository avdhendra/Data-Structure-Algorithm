#include<iostream>
#include<vector>
using namespace std;

class Heap{
vector<int>V;
bool minHeap;

bool Compare(int a,int b)
{
    //if min heap is true
    if(minHeap)
    {
        //means we have to swap when parent is greater than children
      return   a<b;
    }

    else{
       return a>b;
    }
}

public:
Heap(bool type=true,int default_Size=10)
{
    V.reserve(default_Size);
    V.push_back(-1); //block the zero index
    minHeap=type;  //if this variable is set to true then it is minHeap
    //but if false then it is max heap
}
//0(NlogN)-
void push(int d)
{
    V.push_back(d);
    int idx=V.size()-1;
    int parent=idx/2;
    //Keep pushing to the top till you reach a root node or stop midway 
    //because current element is already greater than parent
    while(idx>1 && Compare(V[idx],V[parent]))
    {
       swap(V[idx],V[parent]);
       idx=parent;
       parent=parent/2;
    }
}
void Heapfiy(int i )
{
    int left=2*i;
    int right=2*i+1;
    int minIndex=i;
    if(left<V.size() && Compare(V[left],V[minIndex]))
    {
        minIndex=left;
    }
    if(right<V.size() && Compare(V[right],V[minIndex]))
    {
        minIndex=right;
    }
    if(minIndex!=i)
    {
        swap(V[i],V[minIndex]);
        Heapfiy(minIndex);
    }
}
bool isEmpty()
{
    return V.size()==1;
}
int top()
{
    return V[1];
}
void pop()
{
    //Remove the topmost element
    int last=V.size()-1;
    swap(V[1],V[last]);
    V.pop_back();
    Heapfiy(1); //pass index 1
}
};


int main()
{
    Heap h(true); //by default h is true so it print min heap
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);

while(!h.isEmpty())
{
    cout<<h.top()<<" ,";
    h.pop();
}
   
    Heap h2(false);
    h2.push(5);
    h2.push(15);
    h2.push(2);
    h2.push(20);
    h2.push(3);
    cout<<endl;

while(!h2.isEmpty())
{
    cout<<h2.top()<<" ,";
    h2.pop();
}

return 0;

}