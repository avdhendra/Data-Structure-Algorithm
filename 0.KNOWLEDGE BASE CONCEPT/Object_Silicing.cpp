//Object Slicing -happen when a derived classs object is assign
/* to a base class object, addition attritbute of a derived 
class object are sliced off to from the base class
object*/
#include <iostream>
using namespace std;
  
class Base
{
protected:
    int i;
public:
    Base(int a)     { i = a; }
    virtual void display()
    { cout << "I am Base class object, i = " << i << endl; }
};
  
class Derived : public Base
{
    int j;
public:
    Derived(int a, int b) : Base(a) { j = b; }
    virtual void display()
    { cout << "I am Derived class object, i = "
           << i << ", j = " << j << endl;  }
};
  
// Global method, Base class object is passed by value
void somefunc (Base obj)
{
    obj.display();
}
  
int main()
{
    Base b(33);
    Derived d(45, 54);
    somefunc(b);
    somefunc(d);  // Object Slicing, the member j of d is sliced off
    return 0;
}
/*We can avoid above unexpected behavior with the use of 
pointers or references. Object slicing doesn’t occur 
when pointers or references to objects are passed as 
function arguments since a pointer or reference of 
any type takes same amount of memory.

// rest of code is similar to above
void somefunc (Base *objp)
{
    objp->display();
}
  
int main()
{
    Base *bp = new Base(33) ;
    Derived *dp = new Derived(45, 54);
    somefunc(bp);
    somefunc(dp);  // No Object Slicing
    return 0;
}
I am Base class object, i = 33
I am Derived class object, i = 45, j = 54


                

*/