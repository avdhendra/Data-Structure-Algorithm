/*
Singleton design pattern is a software design principle that
is used to restrict the instantiation of a class to one object. 
This is useful when exactly one object is needed to coordinate
actions across the system. For example, if you are using a logger,
that writes logs to a file, you can use a singleton class to create
such a logger. 
 namespace can be use as Singleton 
*/
// #include<bits/stdc++.h>
// using namespace std;
// class Singleton{
//     public:
//     static Singleton& Get()
//     {
//         return s_Instance;
//     }
// Singleton(const Singleton& )=delete;  //copy constructor

// void Function(){}

// private:
//  // Private constructor so that no objects can be created.
// Singleton(){}
// static Singleton s_Instance;


// };

// Singleton Singleton::s_Instance;

// int main(){
// Singleton &instance=Singleton::Get(); //this is the Only instance of this class
// //We dont do Singleton instance=Singleton::Get() ; because it will copy this instance to instance and if there is some 
// //data member in class it will also copy and thats what singleton doesnt represent

// //for not doing Singleton instance=Singleton::Get() we can use copy constructor as following

// //Singleton instance=Singleton::Get(); uncomment this and you will see the error

// instance.Function();
// return 0;
// }

/////////////////////////
//they both perform same way but the difference is access specifier

// #include<iostream>
// using namespace std;

// namespace RandomClass{
//     static float s_randomGenerator=0.5f;
    
//     static float  Float(){
//         return s_randomGenerator;
//     }
// }

// int main()
// {
// float number=RandomClass::Float();
// cout<<number<<"\n";

// }
#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}