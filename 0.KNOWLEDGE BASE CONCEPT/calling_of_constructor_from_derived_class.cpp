#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int a;
    int b;
    A(int c)
    {
        a=c;
        cout<<"Inside Base class parameterised constructor "<<endl;
    }
    A(int a,int b)
    {
        this->a=a;
        this->b=b;
        cout<<"Inside Base class parameterised constructor "<<endl;
    }
};
class B:public A{
public:
int c;

B(int c):A(c)
{
    this->c=c;
cout<<"Inside sub class parameterised constructor :";
}
};
int main(){
B ob1(2);
return 0;
}