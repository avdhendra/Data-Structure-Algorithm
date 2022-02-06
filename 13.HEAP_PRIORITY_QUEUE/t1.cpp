#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--){
    int N;
    cin>>N;
    int x;
   vector<pair<int,int>>B;
   for(int i=1;i<=N;i++){
       cin>>x;
       B.push_back(make_pair(x,i)); //we push the element as well as the index

   }
   int k=0;
   sort(B.begin(),B.end(),greater<pair<int,int>>());
  vector<int>a(N+1);
  int want=1;
  for(auto bi:B)
  {
      if(want<=bi.first)
      {
          a[bi.second]=want;
          want++;
      }
      
  }
  for(int i=1;i<=N;i++){
      cout<<a[i]<<" ";
  }
cout<<"\n";
}

return 0;
}