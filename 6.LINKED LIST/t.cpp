#include<bits/stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
vector<int>vec;
int a;
for(int i=1;i<=n;i++)
{
    cin>>a;
    vec.push_back(a);
}
for(int i=0;i<vec.size();i++)
{
    if(vec[i]==vec[i+1])
    {
        vec.erase(next(vec.begin(),i),next(vec.begin(),i+2));

    }

}
for(auto it=vec.begin();it!=vec.end();it++)
{
    cout<<*it;
}
return 0;
}