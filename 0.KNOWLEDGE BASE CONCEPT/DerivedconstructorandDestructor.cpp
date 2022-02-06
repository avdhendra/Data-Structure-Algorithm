//Destructor
/*
**class Destructor are invoked in the reverse order as constructors
**The Derived part of the Derived class Must be destroyed before the Base class destructor is invoked
**when a derived object is destroyed
//Derived class destructor executes 
then Base class destructor executes
//each destructor should free resources allocated in its own constructors

//Derived class does not inherit
//base class constructor
//base class destructor
//Base class overloaded assignment operators
//Base class friend function
 ////
 however 
 the all can invoke the base-class version

*/
#include<iostream>
using namespace std;
class Base
{
    private:
    int value;
    public:
    Base():value{0}{
        cout<<"Base no-args constructor"<<endl;

    }
    Base(int x):value{x}{
        cout<<"Base(int) overloading constructor"<<endl;

    }
    ~Base()
    {
        cout<<"Base destructor"<<endl;
    }
};
class Derived:public Base{
    private:
    int doubled_value;;
    public:
    Derived():doubled_value{0}{
        cout<<"Derived no-args constructor"<<endl;
    
    }
    Derived(int x):doubled_value{x*2}{
        cout<<"Derived(int) overloaded constructor"<<endl;
        
    }
    ~Derived()
    {
        cout<<"Derived destructor "<<endl;
    }
};


int main()
{
   // Base b{100};

Derived d{1000}; //x value remain 0
//because we not inherit it to derived class
//so how we do that
//we see that in next slide

}