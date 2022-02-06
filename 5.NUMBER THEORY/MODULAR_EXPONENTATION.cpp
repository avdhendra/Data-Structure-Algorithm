 //Recursive apporach
//complexity is order of 0(log(b))
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int modRecursive(int a,int b,int c)
{
    if(a==0)
    {
        return 0;
    }
    if(b==0)
    {
        return 1;
    }
//if B is even

    if(b%2==0)
    {
        return modRecursive((a*a)%c,b/2,c)%c;
    }
    else
    {
        // B is odd
        return ((a%c)* (modRecursive((a*a)%c,b/2,c)))%c;
    }
}
int main(){
cout<<modRecursive(2,6,5);
return 0;
}