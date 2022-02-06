#include<bits/stdc++.h>
using namespace std;
long long int balancedBinary(int h)
{
    int mod=pow(10,9)+7;
    long long int balanceBt[h+1];
    balanceBt[0]=balanceBt[1]=1;
    for(int i=2;i<=h;i++)
    {
        balanceBt[i] = (balanceBt[i - 1] * ((2 * balanceBt [i - 2])%mod + balanceBt[i - 1])%mod) % mod;
    }
    return balanceBt[h];
}
int main()
{
    int height;
    cin>>height;
    cout<<"No. of balanced binary trees of height h is : "<<balancedBinary(height)<<endl;

}