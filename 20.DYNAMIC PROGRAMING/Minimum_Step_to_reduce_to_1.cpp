#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
//Basic Recursion we Can Calculate it but
//this A slow Process whose complexity is 0(3^n)
int Reduce(int n)
{
    if(n==1)
    {
        return 0;
    }
    int q1=inf,q2=inf,q3=inf;
    if(n%3==0)
    q1=1+Reduce(n/3);
    if(n%2==0)
    q2=1+Reduce(n/2);
    q3=1+Reduce(n-1);
    
    int output= min(q1,min(q2,q3));
return output;
}
//Memoization
int Reduce1(int n,int*memo)
{
    if(n==1)
    {
        return 0;
    }
    if(memo[n]!=-1)
    {
        return memo[n];
    }
    int q1,q2,q3;
    q1=q2=q3=inf;
    if(n%2==0)
    {
        q1=1+Reduce1(n/2,memo);
    }
    if(n%3==0)
    {
        q2=1+Reduce1(n/3,memo);
    }
    q3=1+Reduce1(n-1,memo);

    memo[n]=min(q1,min(q2,q3));
    return memo[n];
}
int Reduce2(int n,int*Dp)
{

    Dp[0]=0,Dp[1]=0;
    Dp[2]=1,Dp[3]=1;
    for(int i=4;i<=n;i++)
    {
        int q1=inf;
        int q2=inf;
        int q3=inf;
        if(i%3==0)
        q1=1+Dp[i/3];
        if(i%2==0)
        q2=1+Dp[i/2];

        q3=1+Dp[i-1];
        Dp[i]=min(q1,min(q1,q2));
    }
    return Dp[n];

}

int main(){
int n;
cin>>n;
int memo[n+1];
fill(memo,memo+n+1,-1);
cout<<"Number of Step To Convert "<<n<<" To 1 is "<<Reduce1(n,memo)<<endl;
return 0;
}