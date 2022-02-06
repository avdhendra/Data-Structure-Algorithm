#include<iostream>
#include<vector>
using namespace std;
void foreach(const vector<int>&values,void(*func)(int) )
{
    for(int value:values)
    {
        func(value);
    }
}
int main()
{
    vector<int> values= {1,5,6,79,50};
    foreach(values, [](int value)
    {
        cout<<"value"<<value<<endl;
    }
    ); 
    
}
/*
#include<iostream>
#include<vector>
using namespace std;
void foreach(const vector<int>&values,auto func  ) //auto is working
{
    for(int value:values)
    {
        func(value);
    }
}
int main()
{
    vector<int> values= {1,5,6,79,50};
    foreach(values, [](int value)
    {
        cout<<"value"<<value<<endl;
    }
    ); 
    
}*/
