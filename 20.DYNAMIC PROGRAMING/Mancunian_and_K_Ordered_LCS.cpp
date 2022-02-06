 /*
Any programmer worth his salt would be familiar with
the famous Longest Common Subsequence problem. 
Mancunian was asked to solve the same by an incompetent
programmer. As expected, he solved it in a flash. 
To complicate matters, a twist was introduced 
in the problem.

In addition to the two sequences, an additional 
parameter k was introduced. A k-ordered LCS is defined 
to be the LCS of two sequences if you are allowed to 
change at most k elements in the first sequence to any 
value you wish to. Can you help Mancunian solve this 
version of the classical problem?
 
 
 */
/*
Dp way
12345
53241
k=1

*/
#include<bits/stdc++.h>
using namespace std;
int LCS(char*S1,char*S2,int x,int y,int k)
{
    int dp[x+1][y+1];
    if(x==0 || y==0)
    {
        return 0;
    }
    for(int i=0;i<=x;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++)
    {
        dp[0][j]=0;
    }
    
    for(int i=1;i<=x;i++)
    {
        int q1=0,q2=0,q3=0;
        for(int j=1;j<=y;j++)
        {
            if(S1[i-1]==S2[j-1])
            {
                q1=1+dp[i-1][j-1];
            }
            if(k>0)
            {
               q2= 1+dp[i-1][j-1];
                k--;
            }
            else{
                q3=max(dp[i-1][j],dp[i][j-1]);

            }
            
            dp[i][j]=max(q1,max(q2,q3));
        }
    }
    return dp[x][y];

}
int main(){
char s1[100];
char s2[100];
cin>>s1>>s2;
int x=strlen(s1);
int y=strlen(s2);
int k;
cin>>k;
int ans=LCS(s1,s2,x,y,k);
cout<<ans<<endl;


return 0;
}