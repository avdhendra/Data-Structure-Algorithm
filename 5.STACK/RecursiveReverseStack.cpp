#include<bits/stdc++.h>
using namespace std;
void InsertAtBottom(stack<int>&S1,int x)
{
if(S1.empty())
{
    S1.push(x);
    return ;
}
int y=S1.top();
S1.pop();
InsertAtBottom(S1,x);
S1.push(y);
}
void RecursiveReverseStack(stack<int>&S1)
{
if(S1.empty()==true)
{
    return;
}
int x=S1.top();
S1.pop();
RecursiveReverseStack(S1);
InsertAtBottom(S1,x);
}
int main(){
stack<int>S1;
for(int i=1;i<6;i++)
{
    S1.push(i);
}
RecursiveReverseStack(S1);
while(!S1.empty())
{
    cout<<S1.top()<<endl;
    S1.pop();
}
return 0;
}