/*
Travelling sales man

*/
#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
int n=4; //number of city
//Adj Matrix which define the graph
int dist[10][10]={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
//if all city have been visited

int VISITED_ALL=(1<<n)-1;  //2^n-1  = 1111
int Travel_Sale_problem(int mask,int pos)   //mask of cities==>0 1 1 0 1 all zero bit are not visited cities
                                              //pos              3 2 1 0  
{
//base case
if(mask==VISITED_ALL)
{               //from current city to the first node
     return dist[pos][0];  //if we visited all node from that city 
}
int ans=inf;
//Try to Goto an Unvisited City
for(int city=0;city<n;city++)
{
    if((mask&(1<<city))==0) //that give  city

/*
i check if current city is visited or not
 mask=0|0|10
    & 0|1|00  1<<2 city
      -----
      0 |0| 0 0      
         |
         V
         not visited


*/

    {                  //from current city to the new city we go
        int newAns=dist[pos][city]+Travel_Sale_problem(mask|(1<<city),city);
          ans=min(ans,newAns);
    }
    
}
return ans;
}
int main(){
cout<<Travel_Sale_problem(1,0)<<endl;
return 0;
}