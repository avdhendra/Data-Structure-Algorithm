//The override Base class virtual function
//The Function signature and return must be Exaclty the same
//If they are different then we have redefinition not Overriden
//Redefinition is statically bound
//Overriding is dynamically Bound
//C++11 provide and override specifier to have the compiler ensure overriding]
#include<iostream>
using namespace std;
class Base
{
    public:
    virtual void say_hello() const
    {
        cout<<"Base _class Obj"<<endl;
    }

};
class Derived:public Base{
    public:
    virtual void say_hello() const override  //notice we forget the const so it bind statically
    {
        cout<<"Derived Class obj"<<endl;

    }
};
int main()
{
    Base *p1=new Base();
    p1->say_hello();
    Derived *p2=new Derived();
    p2->say_hello();
    Base *p3=new Derived();
    p3->say_hello();
}