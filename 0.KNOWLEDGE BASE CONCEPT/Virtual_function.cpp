/*
Redefined function are bound statically
*overriden function are bound dynamically
*vitrual overriden  function  
*Allow us to treat all object generally as object of base class


//So how we implement it

*Declare the function u want to override as virtual in the base class
* virtual function are virtual all the way down the hierachy from this point
* Dynamic polymorphism only via account class pointer or reference
class Account
{
    public:
    virtual void withdraw(double amount)
    {
        ********
    }
}
*Override the function in the Derived classes
Function signature and return type must match Exaclty
*virtual keyword not required but is best practice
if u dont provide an overriden version it is inherited from it base class


class Checking:Public Account
{
    public:
    virtual void withdraw(double Amount )
}


*/
#include<iostream>
using namespace std;
// the class use dynamic Polymorphism for the withdraw method
class Account
{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"IN ACCOUNT: WITHDRAW"<<endl;
    }
};
class Checking:public Account{
    public:
   virtual void withdraw(double Amount)
    {
        cout<<"In Checking :withdraw"<<endl;
    }
};
class Saving:public Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"In Saving :withdraw"<<endl;
    }
};
class Trust:public Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"In Trust:withdraw"<<endl;
    }
};
int main()

{
Account *ptr1=new Account();
Account *ptr2=new Checking();
Account *ptr3=new Saving();
Account *ptr4=new Trust();
Account *A[]={ptr1,ptr2,ptr3,ptr4};
for(int i=0;i<4;i++)
{
    A[i]->withdraw(400);
}

    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;


return 0;

}
/*
A virtual function is a member function which is declared within a base class
and is re-defined(Overriden) by a derived class. When you refer to a derived class
object using a pointer or a reference to the base class, 
you can call a virtual function for that object and 
execute the derived class’s version of the function. 

******Virtual functions ensure that the correct function is called for an object****
, regardless of the type of reference (or pointer) used for function call.

They are mainly used to achieve Runtime polymorphism

Functions are declared with a virtual keyword in base class.

The resolving of function call is done at Run-time.

Rules for Virtual Functions

**Virtual functions cannot be static.
**A virtual function can be a friend function of another class.
Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
The prototype of virtual functions should be the same in the base as well as derived class.
They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
A class may have virtual destructor but it cannot have a virtual constructor.
Compile-time(early binding) VS run-time(late binding) behavior of Virtual Functions

Consider the following simple program showing run-time behavior of virtual functions.


*/