#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
int w,h,n; //breath and hieght of board and n is number of tower
cin>>t;

while(t--)
{
    cin>>w>>h>>n;
 long long int x[n+1],y[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];

    }
    x[n]=w+1;
    y[n]=h+1;
    //sorting
    sort(x,x+n);
    sort(y,y+n);
    //we need to find delta x and delta y
    long long  int dx=x[0];
 long long  int dy=y[0];
    for(int i=1;i<=n;i++)
    {
        dx=max(dx,x[i]-x[i-1]);
        dy=max(dy,y[i]-y[i-1]);
    }
    
    cout<<(dx-1)*(dy-1)<<endl;


}
return 0;
}