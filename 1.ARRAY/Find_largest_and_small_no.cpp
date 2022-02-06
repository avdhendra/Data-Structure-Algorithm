#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main(){
int n,key;
cin>>n;
int a[100];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
//algorithm to find to smallest and largest number
int i;
int max=INT_MIN;
int small=INT_MAX;
for(i=0;i<n;i++)
{                             

                    
    if(a[i]>max)
    {
        max=a[i];
    }
    if(a[i]<small)   2<1,4<1,
    {
        small=a[i];
    }
}
cout<<"smallest number : "<<small<<endl;
cout<<"largest number : "<<max<<endl;
return 0;
}