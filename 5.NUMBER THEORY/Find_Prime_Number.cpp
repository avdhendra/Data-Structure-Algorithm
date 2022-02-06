/*
time complexity :-0(n root(N))

*/

#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int i)
{
    int count=0;
    for(int j=1;j*j<=i;j++)
    {
        if(j*j==i)
        {
            count++;
        }
        
        else{
            count+=2;
        }
    }
    if(count==2)
    {
        return true;
    }
    return false;
}
int main()
{
    int count=0;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        if(checkPrime(i)==true)
        {
            count++;
        }
    }
    cout<<count<<endl;
}
/*



*/