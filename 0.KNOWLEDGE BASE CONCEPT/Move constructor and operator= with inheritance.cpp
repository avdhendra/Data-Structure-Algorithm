/*
Copy/Move constructor and overloaded operator=

*Not inherited from the base class
*you may not need to provide ur own
*compiler provided version may be just fine
 
*We can explicitly invoke the base class version from the Derived class

/////////////////////////////////////
Copy/move constructor and overloaded operator=
*often you dont need to provided your own

*if you dont define them in Derived
*then u must invoke the base version explicitly urself


**be careful with raw pointer
*especially if base and derived each have raw pointers
*provided them with deep copy semantics
*/
#include<iostream>
using namespace std;
class Base{
    private:
    int value;
    public:
    Base():value{0}{
        cout<<"Base constructor"<<endl;
    }
    Base(int x):value{x}{
        cout<<"int base constructor"<<endl;
    }
    Base(const Base&other):value{other.value}{
        cout<<"Base copy constructor"<<endl;
    }
    Base&operator =(const Base&rhs)
    {
        cout<<"Base operator="<<endl;
        if(this==&rhs) //address of this means b1 and rhs are same if
        return *this;
        value=rhs.value;
        return *this;
    }
    //
    ~Base()
    {
        cout<<"Base destructor"<<endl;
    }
    
} ;
class Derived:public Base{
    private:
    int doubled_value;
    public:
    Derived():Base{}{
        cout<<"Derived no-args constructor"<<endl;

    }
    Derived(int x):Base{x},doubled_value{x*2}{
        cout<<"int derived constructor"<<endl;

    }
    Derived(const Derived&other)
    :Base(other),doubled_value{other.doubled_value}{
        cout<<"Derived copy constructor"<<endl;
    }
Derived &operator=(const Derived &rhs)

{
    cout<<"Derived Operator="<<endl;
    if(this==&rhs)
    return *this;
    Base::operator=(rhs);
    doubled_value=rhs.doubled_value;
    return *this;
}
~Derived()
{
    cout<<"Derived Destructor"<<endl;
}
};
int main()
{

/*Base b{100};//overloaded constructor
Base b1{b}; //copy constructor
b=b1; //copy assignment
*/
Derived d{100};
Derived d1{d};
d=d1; //copy Assignment

return 0;
}