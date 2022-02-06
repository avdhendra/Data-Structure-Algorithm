#include<bits/stdc++.h>
using namespace std;
void eulerPhi(int m)
{
    int phi[m+1];
    for(int i=1;i<=m;i++)
    {
        phi[i]=i;

    }
    for(int i=2;i<=m;i++)
{
    if(phi[i]==i)
    {
        phi[i]=i-1;
        for(int j=2*i;j<=m;j+=i)
        {
            phi[j]=(phi[j]*(i-1))/i;
        }
    }
}

for(int i=1;i<=m;i++)
{
    cout<<" Euler Totient Phi For "<<i<<"Is : "<<phi[i]<<endl;
}

}
int main(){
eulerPhi(8);
return 0;
}