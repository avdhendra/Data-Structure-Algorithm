//iterative method 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll modexponentiation(int a,int b,int c)
{

ll count=1;
// if a is not in range of integer

a=a%c; 

if(b==0)
return 1;

if (a==0)
return 0;



while(b>0)
{
    //if b is odd multiply a with result 
   if(b&1) //odd
   {
       count=(count*a)%c;
   }
   a=(a*a)%c;
   b=b/2;

}
return count;

}
int main(){
    int a;
    int b;
    int mod;
    
    cout<<"Enter base : ";
    cin>>a;
    
    cout<<"Enter power : ";
    cin>>b;
    
    cout<<"Enter modulo : ";
    cin>>mod;
cout<<"Power is : "<<modexponentiation(a,b,mod);
return 0;
}