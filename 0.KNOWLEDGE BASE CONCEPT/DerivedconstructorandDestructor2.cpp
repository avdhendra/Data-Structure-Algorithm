#include<iostream>
using namespace std;

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
    Derived():Base{},doubled_value{0}{
        cout<<"Derived no-args constructor"<<endl;
    
    }
    Derived(int x):Base{x},doubled_value{x*2}{
        cout<<"Derived(int) overloaded constructor"<<endl;
        
    }
    ~Derived()
    {
        cout<<"Derived destructor "<<endl;
    }
};


int main()
{
    Base b1;
    Base b{100};

Derived d1;
Derived d{1000}; //x value remain 0
//because we not inherit it to derived class
//so how we do that


}
