#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    vector<int>x;
    public:
    //to insert data at stack
    void Push(int data)
    {
        x.push_back(data);

    }
    //isEmpty
    bool empty()
    {
        return x.size()==0;
    }
    //pop Function
    void pop()
    {
        //if stack is not empty
        if(!empty())
        {
            x.pop_back();
        }
    }
    //Peek or Top
    int top()
    {
        return x[x.size()-1];
    }
};
int main(){
Stack s1;
for(int i=1;i<=5;i++)
{
    s1.Push(i);
}

//Display 
while(!s1.empty())
{
    cout<<s1.top()<<endl;
    //remove element one by one
    s1.pop();
}
return 0;
}