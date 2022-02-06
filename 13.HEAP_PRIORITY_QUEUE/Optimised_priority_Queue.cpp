#include<bits/stdc++.h>
using namespace std;

void Print(vector<int>v)
{
    for(int i:v)
    {
        cout<<i<<" ,";
    }
}
bool compare(int a,int b)
{
   return a>b;// if min heap;
}
void Heapfiy(vector<int>&v,int i)
{
    int left=2*i;
    int right=2*i+1;
    int minindex=i;
    if(left<=v.size()-1 && compare(v[left],v[minindex]))
    {
        minindex=left;
    }
    if(right<=v.size()-1 && compare(v[right],v[minindex]))
    {
        minindex=right;
    }
    if(minindex!=i)
    {
        swap(v[i],v[minindex]);
        Heapfiy(v,minindex);
    }

}
void BuildOptimisation(vector<int>&v)
{
    for(int i=(v.size()-1)/2;i>=1;i--)
    {
        Heapfiy(v,i);
    }
}
int main(){
vector<int>v{-1,10,20,5,6,1,8,9,4};
Print(v);
cout<<endl;
BuildOptimisation(v);
Print(v);
return 0;
}