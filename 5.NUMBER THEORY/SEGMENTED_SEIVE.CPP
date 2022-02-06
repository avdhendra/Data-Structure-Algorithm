/*
THE TASK IS TO PRINT PRIME NUMBER
FROM A GIVEN RANGE OF NUMBER
BUT THE RANGE IS FROM 

2<=L<U<=2147483647

U-L<=1000000

OUPTUT
FOR EACH TEST CASE OUPUT MUST CONTAIN ALL PRIMES FROM INTERVAL [L,U] IS INCREASING ORDER

SEIVE SIZE IS OF 10^6

*/
#include<bits/stdc++.h>
using namespace std;
//precompute all the seive in a given range
#define MAX 100001
vector<int>*seive()
{
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++)
    {
        isPrime[i]=true; 
    }
    for(int i=2;i*i<MAX;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    vector<int>*PRIME=new vector<int>();
    PRIME->push_back(2);
    for(int i=3;i<MAX;i+=2)
    {
        if(isPrime[i])
        {
            PRIME->push_back(i);
        }
    }
    return PRIME;
}
void printPrimes(long long int l,long long int r,vector<int>*&primes)
{bool isPrime[r-l+1];
    for(int i =0;i<=r-l;i++)
    { 
        isPrime[i]=true;
    }
    //because r is long long int so comparsion need to be same 
    for(int i=0;primes->at(i)*(long long int )primes->at(i)<=r;i++)
    {
int currprime=primes->at(i);
//just smaller or equal value to l
long long int base=(l/(currprime))*(currprime);
if(base<l)
{
    base=base+currprime;
}
//mark all multiple within L to R as false
for(long long int j=base;j<=r;j+=currprime)
{
    isPrime[j-l]=false;
}
//There may be a case where base is itself a prime number
if(base==currprime)
{
    isPrime[base-l]=true;
}
    }
    for(int i=0;i<=r-l;i++)
    {
        if(isPrime[i])
        {
            cout<<i+l<<endl;
        }
    }
}
int main(){
vector<int>*Prime=seive();
long long int l,r;
cin>>l>>r;
printPrimes(l,r,Prime);
return 0;
}