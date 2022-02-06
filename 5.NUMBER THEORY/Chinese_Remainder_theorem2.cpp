/*
Chinese Remainder Theorem


x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of 
         pp[i] with respect to num[i]

*/

#include<bits/stdc++.h>
using namespace std;
//Return modulo inverse of a 
/*
with respect to m using 
extended euclid algorithm
*/
class Triplet{
    public:
    int x;
    int y;
    int gcd;
};
Triplet gcdExtendedEuclid(int a,int b)
{
    //Base case
    if(b==0)
    {
        Triplet myans;
        myans.gcd=a;
        myans.x=1;
        myans.y=0;
        return myans;

    }
    Triplet smallAns=gcdExtendedEuclid(b,a%b);
    //Extended Euclid Says
    Triplet myans;
    myans.gcd=smallAns.gcd;
    myans.x=smallAns.y;
    myans.y=(smallAns.x-((a/b)*(smallAns.y)));
    return myans;

}
double inv(int a,int b)
{
    /*
    if a%m=-ve like (17*(-1))%3 =((17%3)*-1%3)%3=-2%3
    a%m when a is -ve we can do (a+m)%m
    */
    Triplet Ans=gcdExtendedEuclid(a,b);
   if(Ans.x<0)
   {
       Ans.x+=b;
   } 
   return Ans.x;
}

int findMinx(int num[],int rem[],int k)
{
    //Compute Product of all number
    int prod=1;
    for(int i=0;i<k;i++)
    {
        prod*=num[i];
    }
    //Initialize result
    int result=0;
    //Apply above formula
    for(int i=0;i<k;i++)
    {
        int pp=prod/num[i];
        result+=rem[i]*inv(pp,num[i])*pp;
    }
    return result%prod;
}
int main(){
int num[]={3,4,5};
int rem[]={2,3,1};
int k=sizeof(num)/sizeof(num[0]);
cout<<"X is : "<<findMinx(num,rem,k);
return 0;
}
