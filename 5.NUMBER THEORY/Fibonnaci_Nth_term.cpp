/**In this method we directly implement the formula for nth term in the fibonacci series. 
Fn = {[(√5 + 1)/2] ^ n} / √5 
**/
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    double phi=(1+sqrt(5))/2;
    return round((pow(phi,n))/sqrt(5));
}
int main(){
int n;
cin>>n;
cout<<fib(n)<<endl;
return 0;
}