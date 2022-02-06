/*
Type punning refers to situations in which storage is written
 as one type and read as another type, 
*/
#include<bits/stdc++.h>
using namespace std;
struct Entity
{
    int x,y;
    int *getPosition()
    {
        return&x; //this return the address of x
    }
};
int main(){

/*
This is Implicit conversion

int a=50;
double value=a;
cout<<value<<endl;

but if we want to have explicit conversion

int a=50;
double value=(double)a;
cout<<value<<endl;
*/
/*How we treat memory assign to a as double*/
/*

int a=50;
double& value=*(double*)&a ;


//we take memory address of a and cast it to double pointer
//&a give integer pointer which converted into double pointer and then we derefernce it 
*/


Entity e={5,8};
//we treat struct as interger array here
int *position=(int*)&e; //this point to address if first integer
cout<<position[0]<<" ,"<<position[1]<<endl;
//they both do the same thing because this return int array {x,y}  
int *pos=e.getPosition();
//we dont copy the memory
cout<<pos[0]<<" ,"<<pos[1];
return 0;
}