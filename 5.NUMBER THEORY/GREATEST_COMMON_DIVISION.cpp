/*
GCD -> greatest common Divisor
(a,b)->
8,4 ->4

we always use euclid algorithm to find gcd in efficient way


gcd(a,b)=gcd(b,a%b)
a>b
till a%b=0

gcd(n,0)=n

//property of modulo

R=a%b 
0<=R<=b-1


also

a%b =a-b*[a/b]   //floor value of [a/b]


R<=a-b a%b max value when a/b is min
so
R<b

2r<a
r<a/2
so 
R=a%b
a%b<a/2



a,b
a/2
a/4
.
...
so the complexity
k=log(a)
a= max of(a,b)
*/
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    //special case for a<b
    if(a<b)
    {
        return gcd(b,a);

    }
    //Base case 
    if(b==0)
    {
          return a;
    }
    //Answer step applying Euclid Algorithm
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=gcd(a,b);
    cout<<"GCD is : "<<ans<<endl;
} 