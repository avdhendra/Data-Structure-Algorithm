/***
 Given  N Ropes of different sizes ,we have join the ropes
 together 



 The cost of joining 2 ropes of different size A and B is (A+B).
 Find the Minimum cost To join all the ropes together.
*/
/*
Pick 2 Smallest Ropes& Join Cost =A+b


Add the new rope in the min heap 

Repeat Until a Single Rope

*/



#include<bits/stdc++.h>
using namespace std;
int Join_Rope(int ropes[],int n)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(ropes[i]);
    }
    int cost=0;
    while(pq.size()>1)
    {
        int A=pq.top();
        pq.pop();
        int B=pq.top();
        pq.pop();
        int rope_length;
        rope_length=A+B;
        cost+=rope_length;
        pq.push(rope_length);
    }
    return cost;

}

int main(){
int ropes[]={4,3,2,6};
int n=4;
cout<<Join_Rope(ropes,n)<<endl;
return 0;
}