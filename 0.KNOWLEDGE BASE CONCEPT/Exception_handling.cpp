/*
in Exception handling three keyword is used
1.throw
throw an exception 
followed by an argument

2.Try {code that may throw and exception}
u place code that may throw an exception 
if the code throw the exception the try block is excited
the throw exception is handled by catch handler
if no catch handler exists the program terminates

catch (exception ex)
code that handles the exception
can have multiple catch handler
may or may not cause the program to terminate

//cerr is output stream for error to output


*/
#include<iostream>
using namespace std;
int main()
{
    int miles;
    int gallon;
    double miles_per_gallon;
    cout<<"Enter the miles drive : ";
    cin>>miles;
    cout<<"Enter the gallon used : ";
    cin>>gallon;
    try{
        if(gallon==0)
        throw 0;  //we can throw any thing in it integer object char
        miles_per_gallon=static_cast<double>(miles)/gallon;
        cout<<"Result ; "<<miles_per_gallon<<endl;


    }
    catch(int &ex ) //since we throw an interger catch it as integer 
    {
        cerr<<"Soryy u can't divide by zero"<<endl;
    }
    cout<<"Bye"<<endl;
    return 0;
    
}