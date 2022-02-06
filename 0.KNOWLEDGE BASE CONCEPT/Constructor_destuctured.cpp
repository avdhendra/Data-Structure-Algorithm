//It is possible to call constructor and destructor by your self
#include<bits/stdc++.h>
using namespace std;
class Base{
    int A;
    public:
    Base()
    {
        cout<<"Constructor is called"<<endl;
    }
    ~Base()
    {
        cout<<"Destructor is called"<<endl;
    }
    
};
int main(){
    Base(); //temporay object;
cout<<"something"<<endl;
Base Ob1; //parmanent object

cout<<"something"<<endl;

return 0;
}
/* Note :if constructor is called from main then together with it destructor is also called 
but if obj of base class is created then constructor called and when object get out of scope it call destructor
/*
Explicit call to destructor is only necessary when 
object is placed at particular location in memory by 
using placement new. Destructor should not be called 
explicitly when the object is dynamically allocated 
because delete operator automatically calls 
destructor.
*/
