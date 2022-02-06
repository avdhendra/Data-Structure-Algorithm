 /*
 Program to implement exception handling with two class 


 */
/*
#include <iostream>
using namespace std;
 
class demo1 {
};
 
class demo2 {
};
 
int main()
{
    for (int i = 1; i <= 2; i++) {
        try {
            if (i == 1)
                throw demo1();
 
            else if (i == 2)
                throw demo2();
        }
 
        catch (demo1 d1) {
            cout << "Caught exception of demo1 class \n";
        }
 
        catch (demo2 d2) {
            cout << "Caught exception of demo2 class \n";
        }
    }
}
*/


/*

Exception handling with inheritance:

Exception handling can also be implemented with the 
help of inheritance. In case of inheritance object 
thrown by derived class is caught by the first catch 
block. 
*/
/*
#include <iostream>
using namespace std;
 
class demo1 {
};
 
class demo2 : public demo1 {
};
 
int main()
{
    for (int i = 1; i <= 2; i++) {
        try {
            if (i == 1)
                throw demo1();
 
            else if (i == 2)
                throw demo2();
        }
 
        catch (demo1 d1) {
            cout << "Caught exception of demo1 class \n";
        }
        catch (demo2 d2) {
            cout << "Caught exception of demo2 class \n";
        }
    }
}
*/
/*
Output: 
 

Caught exception of demo1 class
Caught exception of demo1 class

Explanation: The program is similar 
to previous one but here we have made 
demo2 as derived class for demo1.
Note the catch block for demo1 is written first
.As demo1 is base class for demo2 an object thrown 
of demo2 class will be handled by first catch block







*/



/*
Exception handling with constructor:

Exception handling can also be implemented by
 using constructor. Though we cannot return any 
 value from the constructor but with the help of 
 try and catch block we can.

#include <iostream>
using namespace std;
 
class demo {
    int num;
 
public:
    demo(int x)
    {
        try {
 
            if (x == 0)
                // catch block would be called
                throw "Zero not allowed ";
 
            num = x;
            show();
        }
 
        catch (const char* exp) {
            cout << "Exception caught \n ";
            cout << exp << endl;
        }
    }
 
    void show()
    {
        cout << "Num = " << num << endl;
    }
};
 
int main()
{
 
    // constructor will be called
    demo(0);
    cout << "Again creating object \n";
    demo(1);
}

Explanation: when x = 0 
exception is thrown and catch block is called. 
And when x = 1 no exception is created .


*************************************************
Class Level exception
Exception can also be thrown from within a class

*Method these Work the same way as they do for function as we've seen

*Constructor
*Constructor do not return any value
*throw an exception in the constructor if u cannot initialize an object

*Destructor
Do not throw exception form ur destructor
 









*/