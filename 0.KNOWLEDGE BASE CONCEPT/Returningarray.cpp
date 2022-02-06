#include<iostream>
using namespace std;
int* function()
{
 static /*not only int */int arr[3]={1,2,3}; //local array which can not accesible outside of function

    return arr;
}
int main()
{
    int *arr=function();
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
}
//or create array dynamically
/*
#include<iostream>
using namespace std;
int *function()
[
    int *arr=new int[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    return arr;
]
int main()
{
    int *arr=function();
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;

}
static varibale cannot destroyed memory until the end
*/