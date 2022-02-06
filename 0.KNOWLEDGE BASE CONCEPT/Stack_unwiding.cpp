/*Stack undwinding



The process of removing function entries from 
function call stack at run time is called Stack 
Unwinding. Stack Unwinding is generally related to 
Exception Handling. In C++, when an exception occurs,
 the function call stack is linearly searched for the
  exception handler, and all the entries before the 
  function with exception handler are removed from 
  the function call stack. So exception handling 
  involves Stack Unwinding if exception is not 
  handled in same function (where it is thrown).
*/
#include<iostream>
using namespace std;
void func_B();
void func_C();
void func_A()
{
    cout<<"Starting Func_A"<<endl;
    func_B();
    cout<<"Finishing Func_A"<<endl;  //executed
}
void func_B()
{
    cout<<"Starting func_B"<<endl;
    try{
        func_C();
    }
    catch(int &ex)
    {
        cout<<"catching error in func_B"<<endl;
    }
    cout<<"Ending fuc_b"<<endl; //executed
}
void func_C()
{
    cout<<"starting func_C"<<endl;
    throw 100;
    cout<<"Ending func_C"<<endl;  //this code is not execute
}
int main()
{
    cout<<"Starting main"<<endl;
    func_A();
    cout<<"Finishing main"<<endl;

}