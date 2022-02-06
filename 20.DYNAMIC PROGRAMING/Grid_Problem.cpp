
//Time complexity m*n=n^2
#include<bits/stdc++.h>
using namespace std;
int Grid_Problem(int Grid[][100],int m,int n)
{
   int dp[100][100]={};
    //base case
    dp[0][0]=Grid[0][0];
    //fill the first row
    for(int r=1;r<n;r++)
    {
        dp[0][r]=dp[0][r-1]+Grid[0][r];
    }
    //fill first col
    for(int c=1;c<m;c++ )
    {
        dp[c][0]=dp[c-1][0]+Grid[c][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i-1][j]+Grid[i][j],dp[i][j-1]+Grid[i][j]);
        }
    }
    int output=dp[m-1][n-1];
return output;
}


int main(){
int Grid[100][100]={
    {1,2,3},
    {4,8,2},
    {1,5,3}
};
cout<<Grid_Problem(Grid,3,3);
return 0;
}