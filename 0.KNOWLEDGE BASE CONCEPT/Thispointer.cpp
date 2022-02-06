/*this is a reserved keyword
*contain the address of the project -so its a pointer to the object
* can only be used in class scope
*all member access via done via  the this pointer

**sometimes its useful to know if two object are the same object 
int Account::compare_balance(const Account &other){
    if(this==&other)
    cout<<"the same objects"<<endl;
}


**Some interesting facts about static member function in c++

1) static member function do not have this pointer

2) A static member function cannot be virtual

3) member function declaration with the same name and the name

A static member function can not be declared const, volatile, or const volatile. 

*/
//1..
/*
#include<iostream>
class Test {
   static void fun() {}
   void fun() {} // compiler error
};
  
int main()
{
   getchar();
   return 0;
}
*/
//.4
/*
#include<iostream>
class Test {     
   static void fun() const { // compiler error
     return;
   }
};
  
int main()
{
   getchar();
   return 0;
}
*/


