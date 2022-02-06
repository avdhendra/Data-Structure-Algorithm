#include<bits/stdc++.h>
using namespace std;
void stockspan(int price[],int n,int span[])
{
    stack<int>s; //for indices of the days
    s.push(0);
    
    span[0]=1;
for(int i=1;i<=n-1;i++)
{
    int currentPrice=price[i];
    while(!s.empty() and price[s.top()]<=currentPrice)
    {
        s.pop();
    }
    if(!s.empty())
    {
        int prev_highest=s.top();
        span[i]=i-prev_highest;
    }
    else{
        span[i]=i+1;
    }
    s.push(i);
}

}
int main(){
int Prices[]={100,80,60,70,60,75,85};
 int n=sizeof(Prices)/sizeof(int);
 int span[100000]={0};
 stockspan(Prices,n,span);
 for(int i=0;i<n;i++)
 {
     cout<<span[i]<<" ";
 }
return 0;
}