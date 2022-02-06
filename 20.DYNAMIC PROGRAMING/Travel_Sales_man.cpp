/*
Optimise solution 
in 
from (n-1)!===>2^N.N

we perform memoization

*/
#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
int n=4; //number of city
int dp[16][4]; // 16==>2^n, 4==>n

//Adj Matrix which define the graph
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int ALL_visited=(1<<n)-1; // we subtract -1 because we count from zero

int Travel_Sale_man(int mask,int pos)
{
    if(mask==ALL_visited)
    {
        return dist[pos][0];
    }
    //Lookup in dp
  if(dp[mask][pos]!=-1)
  {
      return dp[mask][pos];
  }
  int ans=inf;
  for(int city=0;city<n;city++)
  {
      if((mask&(1<<city))==0)
      {
          int newAns=dist[pos][city]+Travel_Sale_man((mask|(1<<city)),city);
           ans=min(ans,newAns);
      }
  }
  return dp[mask][pos]=ans;


}
int main(){
//initial we set dp value to zero
memset( &dp[0][0], -1, sizeof(dp) );
cout<<Travel_Sale_man(1,0);
return 0;
}