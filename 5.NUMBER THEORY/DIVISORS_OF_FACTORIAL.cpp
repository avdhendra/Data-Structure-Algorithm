/*
we have to find the number of divisor in N!


like 
10!=1*2*3*4*5*6*7*8*9*10


number which divide 10
1 2 5 10 number of divisor-4


we can express N as prime number form

N -> p1^a x p2^b x p3^c...pn^k

total number of divisor
so number of divisor is 
(a+1)*(b+1)*(c+1)...(k+1)

why we add 1 because we include
1=like 10^0


10= 2^1+5^1

(1+1)*(1+1)=4 so its true 

*/ 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 10000000007
//Fill all prime number for a given n range
vector<int>*seiveErathonthenes(ll n)
{
    //create a boolean array "prime[0....n]" and

/*
initialized all entries it as true .A value 
in prime[i] will finally be false if i is not a prime else true
*/
/*     bool prime[n+1];
memset(prime,true,sizeof(prime));
or we can do
*/
vector<bool> prime(n+1,true);
//primes stores all prime number less than or equal to n as dynamically
vector<int>* primes=new vector<int>();

//loop to update prime[]
    for(ll p =2; p*p<=n;p++)
{
    //if prime is not changes then it 
    //prime
    if(prime[p]==true)
    {//update all multiple of p as false
        for(ll i=p*p;i<=n;i+=p)
        {
            prime[i]=false;

        }
    }

}
//store primes in the vector 
primes->push_back(2);
for(int i=3;i<=n;i+=2)
{
    if(prime[i])
    {
        primes->push_back(i);
    }
}
//return array from function

return primes;
}

ll findDivisor(ll number,vector<int>* &primes)
{
    //initalized result
ll result=1;
//find exponent of all primes which divides n 
// and less than n
for(int i=0;i<primes->size();i++)
{
    //current divisor
    int k=primes->at(i);
    ll count=0;
    //find the highest power(store in exp)
    //of all prime[i] that divides n using 
    //legendre's formula
    while((number/k)!=0)
    {
        count=(count+(number/k))%mod;
        k=k*primes->at(i);
    }
    //multiple exponents of all primes less than n
    result=(result*((count+1)%mod))%mod;

}
//return total divisors
return result;
}
int main()
{ 
     int n;
     cin>>n;
  vector<int>*primes= seiveErathonthenes(n);
  cout<<findDivisor(n,primes)<<endl;


}