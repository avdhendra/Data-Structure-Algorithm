#include<bits/stdc++.h>
using namespace std;
long long int binomialCoeff(int n,int k)
{
    long long int res=1;
    //since C(n,k)=C(n,n-k)
    if(k>n-k)
    {
        k=n-k;
    }
    //calculate value of [n*(n-1)*----*(n-k+1)]
    //[k*(k-1)*---*1]
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
long int catalan(int n)
{
    long long int c=binomialCoeff(2*n,n);
    //return 2nCn/(n+1)
    return c/(n+1);
}
int main(){
for(int i=0;i<10;i++)
{
    cout<<catalan(i)<<" ,";
}
return 0;
}