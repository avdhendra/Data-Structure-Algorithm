/***
* Static data member are class members that are declared using static keyword A static member has certain special characteristics These are:

  Only one copy of that member is created for the entire class and is
  shared by all the objects of that class , no matter how many objects are
  created.
* It is initialized to zero when the first object of its class is created .No 
  other initialization is permitted 

* It is visible only within the class,but its lifetime is the entire program

/*
#include <iostream>
using namespace std;
 
class A
{
public:
    A() { cout << "A's Constructor Called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's Constructor Called " << endl; }
};
 
int main()
{
    B b;
    return 0;
}
The above program calls only B’s constructor, it doesn’t call A’s
 constructor. The reason for this is simple, static members are only 
 declared in class declaration, not defined. They must be explicitly defined 
 outside the class using scope resolution operator.

*/
#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
 
A B::a;  // definition of a
 
int main()
{
    B b1, b2, b3;
    A a = b1.getA();
 
    return 0;
}