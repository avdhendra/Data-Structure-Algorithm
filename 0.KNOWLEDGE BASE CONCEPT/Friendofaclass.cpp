/*Friends of a class
*Friend 
A function or class that has access to priavte class member

and that function of or class is not a member of the class it is acessing 
*
function 
can be regular non-member functions
can be member methods of another class

*class
Another class can have access to private class member


*Friendship must be granted Not Taken 
*Declared explicity in the class that is granting friendship
*Declared in the function prototype with the keyword friend

*Friendship is not Symmetric
*must be explicitly granted
*if A is a friend B
*B is Not a friend of A

*Friendship is not Transitive
*Must be explicitly granted
*if A is a friend B and
*B is a friend of C
*Then A is not a friend of C


 Friend Class A friend class can access private and
 protected members of other class in which it is 
 declared as friend. It is sometimes useful to allow 
 a particular class to access private members of 
 other class


1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited (See this for more details)
4) The concept of friends is not there in Java. 
*/
#include<iostream>
using namespace std;
class A{
    private:
    int a;
    public:
    A(){
        a=0;

    }
    friend class B; //friend class
};
class B{
    private:
    int b;
    public:
    void showA(A &x)
    {
        //since B is friend of A  it can access 
        //private memeber of A
        cout<<"A::a"<<x.a;
    }
};
int main()
{
A a;
B b;
b.showA(a);
}
