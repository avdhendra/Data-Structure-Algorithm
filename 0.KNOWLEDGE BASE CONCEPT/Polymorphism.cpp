//Polymorphism
/*
*compile time /early binding/static binding*
*run time /late binding/ dynamic binding

runtime polymorphism
*being able to assign different meaning to the same function at run time

Not the default in c++ run time polymorphism is achieved via
inheritance
*Base class pointer or reference
*virtual function
*/
#include<iostream>
#include<memory>
using namespace std;
class Base{
    public:
    void say_hello()const{
        cout<<"Hello-Base class object"<<endl;

    }
    
} ;
class Derived:public Base{
    public:
    void say_hello()
    {
        cout<<"Hello-I'am Derived class object"<<endl;
    }
};
void greeting(const Base&obj)
{
    cout<<"Greeting"<<endl;
    obj.say_hello();
}
int main()
{
Base b;
b.say_hello();
Derived d;
d.say_hello();
greeting(b); //static binding by default
greeting(d);
Base*ptr=new Derived();
ptr->say_hello(); //Derived is object of base class ptr point to the base class object derived
//but due to static binding complier know ptr object of base so it call base function
unique_ptr<Base> ptr1=make_unique<Derived>();
//unique pointer take it self dont need to deallocate memory explicitly
delete ptr;

}

