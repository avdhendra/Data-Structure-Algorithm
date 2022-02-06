/*
Threads 
*/
/*
std::thread is the thread class that represents a single thread in C++.
To start a thread we simply need to create a new thread object and pass 
the executing code to be called (i.e, a callable object) into the
constructor of the object. Once the object is created a new thread is 
launched which will execute the code specified in callable.

A callable can be either of the three

    A function pointer
    A function object
    A lambda expression

***Launching thread using function pointer
The following code snippet demonstrates how this is done

void foo(param)
{
    // Do something
}
  
// The parameters to the function are put after the comma
std::thread thread_obj(foo, params);

***Launching thread using lambda expression

The following code snippet demonstrates how this is done
// Define a lamda expression
auto f = [](params) {
    // Do Something
};
  
// Pass f and its parameters to thread 
// object constructor as
std::thread thread_object(f, params);

***Launching threads using function objects

The following code snippet demonstrates how this is done
// Define the class of function object
class fn_object_class {
    // Overload () operator
    void operator()(params)
    {
        // Do Something
    }
}
  
// Create thread object
std::thread thread_object(fn_class_object(), params)

///////////////////////////////////////////////////////////


Waiting for threads to finish

Once a thread has started we may need to wait for the 
thread to finish before we can take some action. 
For instance, if we allocate the task of initializing the GUI of an 
application to a thread, we need to wait for the thread to finish to 
ensure that the GUI has loaded properly.

To wait for a thread use the std::thread::join() function. 
This function makes the current thread wait until the thread 
identified by *this has finished executing.

int main()
{
    // Start thread t1
    std::thread t1(callable);
  
    // Wait for t1 to finish
    t1.join();
  
    // t1 has finished do other stuff
  
    ...
}

*/

#include<bits/stdc++.h>
#include<thread>
using namespace std;

//a Dummy Function
void Foo(int z)
{
    for(int i=0;i<z;i++)
    {
        cout<<"Thread Using function Pointer as Callable\n";
    }
}
//A callable Object
class thread_obj{
    public:
    void operator()(int x)
    {
        for(int i=0;i<x;i++)
        {
            cout<<"Thread Using function object as Callable\n";
        }
    }
};

int main()
{
cout<<"Thread 1 and 2 and 3 Operating Independently"<<endl;
//This Thread is lauched by using \
//Function pointer as Callable
thread th1(Foo,3);    

}