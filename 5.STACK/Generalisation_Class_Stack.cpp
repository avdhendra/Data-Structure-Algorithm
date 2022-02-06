#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack{
    public:
    vector<T>x;
void push(T data)
{
x.push_back(data);    
}
bool empty()
{
    return x.size()==0;
}
void pop()
{
    if(!empty())
     x.pop_back(); 
}
T top()
{
    return x[x.size()-1];
}
};
int main(){
Stack<char> S1;
for(int i=65;i<=70;i++)
{
    S1.push(i);
}
while(!S1.empty())
{
    cout<<S1.top()<<endl;
    S1.pop();
}
return 0;
}