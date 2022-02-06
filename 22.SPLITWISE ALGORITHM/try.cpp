#include<bits/stdc++.h>
using namespace std;
int main(){
vector<string>st;
string s;
cin>>s;
st.push_back(s);

int n=s.length();

for(int i=n-1;i>=0;i--)
{
    
    char c=s.at(i);
  if(isalpha(c))
  {
      int size=st.size();
      
      while(size--)
       {
           string s1=st.front();
           
          string left=s1.substr(0,i);
          
         string right=s1.substr(i+1,n);
         char l=tolower(c);
         char u=toupper(c);
           st.push_back(left+l+right);
             st.push_back(left+u+right);
       }
  }
    
}
for(auto i:st)
{
  cout<<i<<" ";
}
cout<<endl;
set<string>res;

for(auto i:st)
{
  res.insert(i);
}
for(auto it:res)
{
  cout<<it<<" ";
}
return 0;
}