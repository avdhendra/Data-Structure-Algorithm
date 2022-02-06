#include<bits/stdc++.h>
using namespace std;
int main(){
int n,key;
cin>>n;
int a[100];
for(int i=0;i<n;i++)
{
    cin>>a[i];

}
cout<<"enter the element to search : ";
cin>>key;
int i;
for(int i=0;i<n;i++)
{
    if(a[i]==key)
    {
        cout<<key<<"Found at"<<i<<"index";
        break;
    }
}
if(i==n)
{
    cout<<key<<"is not present"<<endl;
    
}
return 0;
}