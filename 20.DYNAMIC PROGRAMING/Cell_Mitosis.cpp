/*
Bottom Up DP

F(i)---->F(i/2)
|  \
|   \ F(i+1)  this value is not There in DP array
V
F(i-1)

if i is Odd
if i is Even

dp[i]=dp[i/2]+x(cost of Double)
dp[i]=dp[i-1]+y (cost of Increase)
dp[i]=dp[i+1]+z(cost of decrease) but this value is not present in DP array




*/
#include<bits/stdc++.h>
using namespace std;
int Cell_Mitosis(int Number,int x,int y,int z)
{
    int dp[1000]={};
  dp[0]=0;
  dp[1]=0;
  for(int i=2;i<=Number;i++)
  {
      if(i%2==0)
      {
          dp[i]=min(dp[i/2]+x,dp[i-1]+y);
      }
      else
      {
          dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
      }
  }
  return dp[Number];
}
int main(){
int Number_cell;
cin>>Number_cell;
int double_value,increment_value,Decrement_value;
cin>>double_value>>increment_value>>Decrement_value;
int ans=Cell_Mitosis(Number_cell,double_value,increment_value,Decrement_value);
cout<<ans<<endl;
return 0;
}