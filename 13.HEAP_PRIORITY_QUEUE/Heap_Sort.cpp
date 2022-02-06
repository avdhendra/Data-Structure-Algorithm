#include<bits/stdc++.h>
using namespace std;
bool Compare(int a,int b)
{
    return a>b;

}

//Heapify Function
void Heapify(vector<int>&v,int size,int i)
{
int left=2*i;
int right=2*i+1;
int minIndex=i;
if(left<=size-1 && Compare(v[left],v[minIndex]) )
{
minIndex=left;
}
if(right<=size-1&& Compare(v[right],v[minIndex]))
{
    minIndex=right;
}
if(minIndex!=i)
{
    swap(v[i],v[minIndex]);
    Heapify(v,size,minIndex);
}
}

// Build 0(n)
void BuildOptimized(vector<int>&v)
{
    for(int i=(v.size()-1)/2;i>=0;i--)
    {
        Heapify(v,v.size(),i);
    }

}
void Heap_Sort(vector<int>&v)
{
    BuildOptimized(v);
    int n=v.size();
    while(n>0)
    {
        swap(v[0],v[n-1]); 
        //we shrink the arr and pass the size according to heapify the heap
        n--;
        Heapify(v,n,0); //we shrink the arr because we want to 
    }
}
void Print(vector<int>v)
{
    for(int i:v)
    {
        cout<<i<<" ,";
    }
    cout<<endl;
}
int main(){
vector<int>v{10,9,16,15,1,3,4};
Heap_Sort(v);
Print(v);
return 0;
}