/*Accessible from the base class itself
*Accessible from classes Derived from Base
*Not accessible by object of base or Derived
*/
#include<iostream>
using namespace std;
class Base
{
    //Note friend of base have access to all data member
public:
int a{0};
void display()
{
    cout<<a<<" , "<<b<<" , "<<endl;}
    protected:
    
    int b{0};
    
    private:
    int c{0};
};
class Derived:public Base{
    //Note friends of Derived have access to only what Derived has access to
    //a will be public
    //b will be protected
    //c will not be accessible
    public:
    void access_base_member()
    {
        a=100;//ok
        b=110;//ok
       // c=330; //not accesible
    }

};
int main()
{
cout<<"==Base member access from base Objects==="<<endl;
Base b;
b.a=100; //ok
//b.b=200; //complier error
//b.c=300 ;;//complier error
cout<<"==Base member access from derived objects"<<endl;


}