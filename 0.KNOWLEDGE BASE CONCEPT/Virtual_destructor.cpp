//why we need virtual destructor
/*
Deleting a derived class object
 using a pointer of base class type that 
 has a non-virtual destructor results in 
 undefined behavior. To correct this situation, 
 the base class should be defined with a virtual 
 destructor
 */
#include<iostream>
using namespace std;
class Base{
    public:
    virtual void fun()
    {
        cout<<"Base Fun"<<endl;

    }
    Base()
    {
        cout<<"Base Constructor"<<endl;
    }
  virtual ~Base()
    {
        cout<<"Base Destructor"<<endl;

    }
};
class Derived:public Base {
    public:
    virtual void fun(){
        cout<<"Derived Fun"<<endl;
    }
    Derived()
    {
        cout<<"Derived Constructor"<<endl;
    }
    ~Derived()
    {
        cout<<"Derived Destructor"<<endl;
    }
};
int main()
{
    //on constructor 

    Base *B1=new Base();
    Base *B2=new Derived();
    B1->fun();
    B2->fun();
    delete B1;
    delete B2;

    return 0;
}