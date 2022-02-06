/*How to sort in descending order? 
sort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass the “greater()” function to sort in descending order. This function does a comparison in a way that puts greater elements before. 
*/
/*
Default it sort in accending order

*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    if(a>b)
    {
        return true;
    }
    return false;
}
bool cmp1(int a,int b)
{
    return a>b;
    //it check if a>b true no action perform
    //if a>b false it swap the value
}
bool comp1(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first!=b.first){
    return a.first<b.first;}

       return a.second>b.second;
    
}
/*
bool com(int a,int b)
{
    if(a>b)return true //increase order
    return false
    if(a<b) return true //decrease order
return false;
}
comp1(pair<int,int>a,pair<int,int>)


sort function
for(int i = 0; i <n;i++){
    for(int j=i+1;j<n;j++){
        if(comp(a[i],a[j]))
        {
            swap(a[i],a[j])
        }
    }
}


in inbuilt comparator function if u want to swap return me false



*/
int main(){
    int n;
    cin>>n;
// vector<int>a(n);
// for(int i=0;i<n;i++){
//     cin>>a[i];
// }
// sort(a.begin(),a.end(),greater<int>()); //built in comparator in c++
// for(int i=0;i<n;i++){
//     cout<<a[i]<<" ";
// }
// vector<int>b(n);
// for(int i=0;i<n;i++)
// {
//     cin>>b[i];
// }
// sort(b.begin(),b.end(),cmp1); //self define comparator work when function return false
// for(int i=0;i<n;i++)
// {
//     cout<<b[i]<<" ";
// }
vector<pair<int,int>>p(n);
for(int i=0;i<n;i++)
{
    cin>>p[i].first>>p[i].second;
}
sort(p.begin(),p.end(),comp1);
for(int i=0;i<n;i++)
{
    cout<<p[i].first<<" "<<p[i].second<<endl;
}
return 0;
}