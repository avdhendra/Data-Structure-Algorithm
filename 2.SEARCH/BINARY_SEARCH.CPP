#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int key,int n)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {   
        int mid=(s+e)/2;


        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}
int main(){
int n,key;
int a[1000];
cout<<"enter of element in array :";
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
cout<<"enter the key to found : ";
cin>>key;
if(binarysearch(a,key,n)!=-1)
{
    cout<<key<<" found at index "<<binarysearch(a,key,n)<<endl;


}
else
{
    cout<<key<<" not found "<<endl;
}

return 0;
}