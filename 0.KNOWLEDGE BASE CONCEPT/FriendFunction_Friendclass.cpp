/*
Friend Class A friend class can access
private and protected members of other
class in which it is declared as friend.
It is sometimes useful to allow a particular
class to access private members of other 
class. For example, a LinkedList class may be 
allowed to access private members of Node. 

*/



/*
Friend Function Like friend class, a friend function can be given a special grant to access private and protected members. A friend function can be: 
a) A member of another class 
b) A global function 

*/
#include<bits/stdc++.h>
using namespace std;
class A{
    friend class B;
    private:
    int x;
    public:
    A(int x)
    {
        this->x=x;
    }
};
class B{
    public:
    void ShowData(A obj)
    {
        cout<<"X value is : "<<obj.x<<endl;
    }
};
int main(){
A obj1(5);
B obj2;
obj2.ShowData(obj1);
return 0;
}