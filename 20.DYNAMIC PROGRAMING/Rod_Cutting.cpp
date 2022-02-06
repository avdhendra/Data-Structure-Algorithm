#include<bits/stdc++.h> 
using namespace std;
//Basic Recursion
int Rod_profit(int *Price,int len)
{
    if(len==0)
    {
        return 0;

    }
    int ans=INT_MIN;
    for(int i=1;i<=len;i++)
    {
        ans=max(ans,Price[i]+Rod_profit(Price,len-i));
    }
    return ans;   

}
//Memoization

int Rod_Profit1(int *Price,int len,int *memo)
{
    if(len==0)
    {
        return 0;
    }
    if(memo[len]!=-1)
    {
        return memo[len];
    }
    int ans=INT_MIN;
    for(int i=1;i<=len;i++)
    {
        ans=max(ans,Price[i]+Rod_Profit1(Price,len-i,memo));
        
    }
    memo[len]=ans;
return ans;
    
}
//Dp way
int Rod_Profit2(int *Price,int totallen)
{
    int dp[100]={};
    if(totallen==0)
    {
        return 0;
    }
      int ans=INT_MIN;
    for(int len=1;len<=totallen;len++)
    {
      
        for(int cut=1;cut<=len;cut++)
       {
            ans=max(ans,Price[cut]+dp[len-cut]);
       }
       dp[len]=ans;
    }
    return dp[totallen];
}
int main(){
int Price[100];
int totalLen;
cin>>totalLen;
for(int EachPiece=1;EachPiece<=totalLen;++EachPiece)
{
    cin>>Price[EachPiece]; //we enter price of Each length
}
int ans=Rod_profit(Price,totalLen);
cout<<"Max Profit : "<<ans<<endl;
//Memoization
int memo[100];
fill(memo,memo+totalLen+1,-1);
int ans1=Rod_Profit1(Price,totalLen,memo);
cout<<"Max Profit 1 : "<<ans1<<endl;
int ans2=Rod_Profit2(Price,totalLen);
cout<<"Max Profit 2: "<<ans2<<endl;
return 0;
}