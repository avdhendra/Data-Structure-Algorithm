//throw exception from function
#include<iostream>
using namespace std;
double Calc(int miles,int gallon)
{
    if(gallon==0)
    throw 0;
    return static_cast<double>(miles)/gallon;
}
int main()
{
    int miles;
    int gallon;
    double miles_per_gallon;
    cout<<"Enter the miles";
    cin>>miles;
    cout<<"Enter the gallons";
    cin>>gallon;
    try{
    miles_per_gallon=Calc(miles,gallon);
    cout<<"result"<<miles_per_gallon<<endl;
    }
    catch(int &ex)
    {
        cerr<<"try again"<<endl;
    }
    cout<<"Bye"<<endl;

return 0;
}
