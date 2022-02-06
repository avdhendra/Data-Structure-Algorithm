#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    //Priority by default max heap
    priority_queue<int>pq;
    int A[]={5,6,17,18,9,11};

    //Insert these in Q

    for(int i=0;i<6;i++)
    {
        pq.push(A[i]);
    }

    //Heap -Max or Min ?
    while(!pq.empty())
    {
        cout<<pq.top()<<" ,";
        pq.pop();
    }

cout<<endl;

//Greater is comparator and make priority min heap which is max heap by default

priority_queue<int,vector<int>,greater<int>>PQ1;

int A1[]={5,6,17,18,9,11};

//Insert these in Q
for(int i=0;i<6;i++)
{
    PQ1.push(A[i]);
}
while(!PQ1.empty())
{
    cout<<PQ1.top()<<" ,";
    PQ1.pop();
}



    return 0;

}