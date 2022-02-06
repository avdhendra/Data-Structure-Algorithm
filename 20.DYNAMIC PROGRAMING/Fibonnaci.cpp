#include<bits/stdc++.h>
using namespace std;
//Basic Fib Function
int fib1(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib1(n-1)+fib1(n-2);
}
//Memoization using recursion
//This is Top Down Aprroach
int fib2(int n,int*Memo)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    if(Memo[n]>0)
    {
        return Memo[n]; //Means we already calculate that value befor
    //So we Just return that value
    }
    int output=fib2(n-1,Memo)+fib2(n-2,Memo);
    Memo[n]=output;
    return output;

}
//This is Pure DP
//This is Bottom Up Approach
int fib3(int n)
{
    int *Dp=new int[n+1];
    Dp[0]=0;
    Dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        Dp[i]=Dp[i-1]+Dp[i-2];
    }
    int Output=Dp[n];
    delete[] Dp;
    return Output;

}
int main(){
int n1,n2,n3;
cin>>n1>>n2>>n3;
int Arr[n2+1];
fill(Arr,Arr+n2+1,-1);
cout<<n1<<" th FiboNacci "<<fib1(n1)<<endl;
cout<<n2<<" th FiboNacci "<<fib2(n2,Arr)<<endl;
cout<<n3<<" th FiboNacci "<<fib3(n3)<<endl;


return 0;
}