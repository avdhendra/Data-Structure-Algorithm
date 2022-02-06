#include<iostream>
#include<vector>
using namespace std;
void Printvalue(int value)
{
    cout<<"values : "<<value<<endl;
}
void foreach(const vector<int>&values,void(*func)(int))
{
    for(int value:values)
    func(value);
}

int main()
{
    vector<int>values={1,5,4,2,8};
    foreach(values,Printvalue);
}