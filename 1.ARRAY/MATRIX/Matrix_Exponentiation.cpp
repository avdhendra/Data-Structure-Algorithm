#include<bits/stdc++.h>
using namespace std;

//Function to compute F raise to power n-2
int power(int F[3][3],int n)
{
    int M[3][3]{{1,1,1},{1,0,0},{0,1,0}};
    //Multiple it with intial value i.e with 
    //F(0)=0, F(1)=1, F(2)=1
    if(n==1)
    return F[0][0]+F[0][1];
    
    power(F,n/2);
    multiple(F,F);
    if(n%2!=0)
    multiple(F,M);

}
/*
return nth term of a series defined using below
//recurrence relation
// F(n) is defined as
f(n)=f(n-1)+f(n-2)+f(n-3), n>=3

//Base case  :
f(0)=0, F(1)=1, f(2)=1
*/
int findnthTerm(int n)
{
    int F[3][3]={{1,1,1},{1,0,0},{0,1,0}};
    //Base case
    if(n==0)
    return 0;
    if(n==1 || n==2)
    {
        return 1;
    }
    return power(F,n-2);
}
int main(){
int num;
cout<<"enter nth fib number : ";
cin>>num;
cout<<"F("<<num<<")"<<findnthTerm(num)<<endl;
return 0;
}