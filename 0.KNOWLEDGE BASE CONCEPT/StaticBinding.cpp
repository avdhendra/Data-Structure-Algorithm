//C++ program to illustrate the concept of static binding

#include<bits/stdc++.h>
using namespace std;
class ComputeSum{
    public:
    int sum(int x,int y){
        return x+y;
    }
    int sum(int x,int y,int z){
        return x+y+z;
    }
};

int main(){
ComputeSum  obj;
cout<<"Sum is "<<obj.sum(10,20)<<endl;
cout<<"Sum is "<<obj.sum(10,20,30)<<endl;
return 0;
}
/*
Static Binding
1. Static binding happens at the compile time hence this is early binding

2. In Static binding the function definition and the function call are linked
during the compile time .

3.Static binding happens when all information needed to call a function is available
at the compile time

4.Static binding can be achieved using the normal function calls function overloading and
operator overloading  

5.Since all information needed to call a function is available before runtime static binding
results in faster execution of a program






*/