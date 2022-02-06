/*
This Keyword in C++

To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.

Each object gets its own copy of the data member.

All-access the same function definition as present in the code segment.
Meaning each object gets its own copy of data members and all objects share a single copy of member functions.

Then now question is that if only one copy of each member function exists and is used by multiple objects, 
how are the proper data members are accessed and updated?

The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls 

and is available as a local variable within the body of all nonstatic functions. ‘this’ 
pointer is not available in static member functions as static member functions can be called without any object (with class name).

For a class X, the type of this pointer is ‘X* ‘. 
Also, if a member function of X is declared as const, then the type of this pointer is ‘const X *’ (see this GFact)

In the early version of C++ would let ‘this’ pointer to be changed; by doing so a programmer could change which object a method was working on. This feature was eventually removed, and now this in C++ is an r-value.
C++ lets object destroy themselves by calling the following code :

***delete this;

*/
#include<bits/stdc++.h>
using namespace std;
class Entity{
    public:
    int x,y,z;
Entity(int x,int y,int z)
{//we can do this to avoid this x(x),y(y)
//this is pointer to current instance
//Entity * const e=this; //means we cannot assign this to some other
Entity *e=this;
    e->z=z; //we can do this also both are same thing

   this->x=x;
   this->y=y;
   PrintEntity(this); //we want to pass current instance of the class to the function
}
};
void PrintEntity(Entity*e)
{

}
int main(){

return 0;
}