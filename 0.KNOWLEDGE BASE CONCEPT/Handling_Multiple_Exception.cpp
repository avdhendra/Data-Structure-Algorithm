//Miles Per Gallon-Function-Multiple Exception
#include<iostream>
#include<cstring>
using namespace std;
double calc(int miles,int gallon)
{
    if(gallon==0)
    throw 0;
    if(miles<0||gallon<0)
    throw string("Negative value error");
    return static_cast<double>(miles)/gallon;
}

int main()
{
    int miles;
    int gallon;
    double mile_per_gallon;
    cout<<"Enter the miles : ";
    cin>>miles;
    cout<<"Enter the gallons";
    cin>>gallon;
    try{
        mile_per_gallon=calc(miles,gallon);
        cout<<"result "<<mile_per_gallon<<endl;
    }
    catch(int &ex)
    {
        cerr<<"Tried to divide by zero"<<endl;
    }
    catch(string&ex)
{
    cerr<<ex<<endl;
}
cout<<"Bye"<<endl;
}