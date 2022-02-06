#include<bits/stdc++.h>
using namespace std;
int RecLCS(char*x,char*y,int lenX,int lenY)
{
    if(lenX==0||lenY==0)
    {
        return 0;
    }
    if(x[lenX-1]==y[lenY-1])
    {
        return 1+RecLCS(x,y,lenX-1,lenY-1);

    }
    else{
    return max(RecLCS(x,y,lenX-1,lenY),RecLCS(x,y,lenX,lenY-1));
    }
}
int LCS(char*x,char*y)
{
    int m=strlen(x);
    int n=strlen(y);
    int dp[100][100];

    //Base Case
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=n;++j)
    {
        dp[0][j]=0;
    }
     /* Following steps build L[m+1][n+1] in
    bottom up fashion. Note that L[i][j]
    contains length of LCS of X[0..i-1]
    and Y[0..j-1] */
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;j++)
        {
            int q=0;
            if(x[i-1]==y[j-1]) //if Character match then we add it 
            {
                q=1+dp[i-1][j-1];
            }
            else{
                q=max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=q;
        }
    }
    return dp[m][n];
}
int main(){
char str1[100],str2[100];
cin>>str1>>str2;
int ans=LCS(str1,str2);
cout<<"Max Length of Common Subsequeunce "<<ans<<endl;
int x=strlen(str1);
int y=strlen(str2);
int ans1=RecLCS(str1,str2,x,y);
cout<<"MAx length of Common Subsequence Recursion : "<<ans1<<endl;
return 0;
}