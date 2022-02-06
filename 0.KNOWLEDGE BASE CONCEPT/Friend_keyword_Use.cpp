/*
#include<iostream>
using namespace std;
class A{
    public:
    void showB(B&);
};
class B{
    private:
    int b;
    public:
    B(){
        b=0;

    }
    friend void A::showB(B&x);
   
};
void A::showB(B&x)
{
    //since showB() is friend of B it can 
    //access private member of B
    cout<<"B::b = "<<x.b;
}
int main()
{A a;
B x;
a.showB(x);

}
*/
/*
A friend function of a class is Defined Outside that class Scope but it has the right to access all
private and protected member of class

even though the prototype for friend function appear in the class definition
friends are not member function



Q why we need friend function?
Special case when class private data needs to be accessed directly without using object of that class

*/
#include<bits/stdc++.h>
using namespace std;
class Length
{
    private:
    int meter;
    public:
    Length()
    {
        meter=0;
    }
    void Display()
    {
        cout<<"Length : "<<meter<<endl;
    }
    friend void addvalue(Length &d);
};
void addvalue(Length &d)
{
    d.meter=d.meter+5;
}

int main(){
Length L;
L.Display();
//The friend function call
addvalue(L);
L.Display();
return 0;
}