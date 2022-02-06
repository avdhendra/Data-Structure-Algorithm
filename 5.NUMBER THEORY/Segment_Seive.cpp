/*
Algorithm
Begin
   Create function to find all primes smaller than limit
   using simple sieve of eratosthenes.
   Finds all prime numbers in given range using
   segmented sieve
   A) Compute all primes smaller or equal to square root of high using simple sieve
   B) Count of elements in given range
   C) Declaring boolean only for [low, high]
   D) Find the minimum number in [low ... high] that is a multiple of prime[i] (divisible by prime[i])
   E) Mark multiples of prime[i] in [low … high]
   F) Numbers which are not marked in range, are prime
End





*/
#include<bits/stdc++.h>
using namespace std;
void simpleSieve(int lmt,vector<int>&prime)
{
    bool mark[lmt+1];
    memset(mark,true,sizeof(mark));
    for(int i=2;i*i<=lmt;i++)
    {
        if(mark[i])
        {
            for(int j=i*i;j<lmt;j+=i)
            {
                mark[j]=false;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<lmt;i+=2)
    {
        if(mark[i])
        {
            prime.push_back(i);
        }
    }
}
void PrimeInRange(int low ,int high)
{
    int lmt=floor(sqrt(high))+1;
    vector<int>prime;
    simpleSieve(lmt,prime);
    int n=high-low+1;
    bool mark[n+1];
    memset (mark,true,sizeof(mark));
    for(int i=0;prime[i]*prime[i]<=high;i++)
    {
        int lowLim=(low/prime[i])*prime[i];
        if(lowLim<low)
        {
            lowLim+=prime[i];
        }
        for(int j=lowLim;j<=high;j+=prime[i])
        {
            mark[j-low]=false;
        }
        if(lowLim==prime[i])
{
    mark[lowLim-low]=true;
}
        
    }

    for(int i=0;i<=high-low;i++)
    {
        if(mark[i])
        {
            cout<<i+low<<" ";
        }
    }
}
int main(){
int low,high;
cin>>low>>high;
PrimeInRange(low,high);
return 0;
}