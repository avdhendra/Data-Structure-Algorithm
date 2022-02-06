/*

We have given two number a,b where 

one number is greater than the limit of integer to store
but other can be store in long long

so how we can store it we can store it in integer


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//function to find gcd of two integer number
ll gcd(ll a,ll b)
{
   if(a>b)
   {
       return gcd(b,a);
   }
   if(a==0)
   {
       return b;
   }
   return gcd(b%a,a);

}

/*
here a is integer and b is string
the idea is to make the second number (represented as b) less than
and equal to first number by
calculating its mod with first intger number
using basic mathematics

*/
ll reduceB(ll a,char B[])
{
//intiallize result
ll mod=0;
//calculating mod of b with a to make
// b like 0<=b<a
for(int i=0;i<strlen(B);i++)
{
    mod=(mod*10+B[i]-'0')%a;
     
}
return mod; //return modulo
}

ll gcdLarge(ll a,char B[])
{
    //reduce b second number after modulo with a 
    ll num=reduceB(a,B);
    //gcd of two number
    return gcd(a,num);

}
int main()
{
    //First number which is integer
    ll num1=2;
    //second number is represented as string because
    //it can not be handled by integer data type

    char num2[]="10";
    if(num1==0)
    {
        cout<<num2<<endl;
    }
    else
    {
        cout<<gcdLarge(num1,num2);
    }

}