#include<bits/stdc++.h>
using namespace std;
void Transfer(stack<int>&S1,stack<int>&S2,int n)
{
    for(int i=0;i<n;i++)
    {
        S2.push(S1.top());
        S1.pop();
    }
}
void reverse(stack<int>&S1)
{
stack<int>S2;
int n=S1.size();
for(int i=0;i<S1.size();i++)
{
    int x=S1.top();
    
    S1.pop();
    Transfer(S1,S2,n-i-1); //here S1 value transfer to S2 i is setvalue
S1.push(x);
Transfer(S2,S1,n-i-1);
}
}
int main(){
stack<int> S1;
for(int i=1;i<6;i++)
{
    S1.push(i);
} 
reverse(S1);
while(!S1.empty())
{
    cout<<S1.top()<<endl;
    S1.pop();
}
return 0;

}