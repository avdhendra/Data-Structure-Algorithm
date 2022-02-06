/*
Move Constructor
*Sometimes when we execute code the compiler create unamed temporary values
int total{0};
total=100+200;
100+200 is evaluated and 300 stored in an unamed temp value
*the 300 is then stored in the variable total
then the temp value is discarded
the same happen with object as well

Sometimes copy constructor are called many times automatically due to the copy
semantics of c++
 * Copy constructor doing deep copying can have a signifiacant performance
 * C++ introduced move semantices and the move constructor 
 * Move constructor move an object rather than copy it
 * 
 * optional but recommended when u have a raw pointer
 * 
 * Copy elision c++ may optimize copying away completely {RVO-return value optimization}



**
*/
/*
L-value;
* values that have names and are addressable 
*modifiable if they are not constants
int x{100};  //x is an l-values
x=100;
x=1000+20;
string name; //name is an l-value
name="frank";

**
*r-value (non addressable and non assignable )
* A value that not an l-value
*on the right hand side of an assignment expression 
* a literal
* a temporary which is intended to be non modifiable

int x{400}; //100 is an r-value
int y=x+3+2; //(x+3+2) is an r value
l-value reference 
the reference we've used are l-value references 
* because we are reference l-value

int x{100};
int &ref=x;
ref1=100;  //ref1 is reference to l-value
int &ref=400;
//error 400 is an r-value

// r-value reference
int x{100};
int &l_ref=x //l-value reference 
change to x to 10
int &&r_REF=200; //r-value ref
r_ref=300; //change r_ref to 300
int &&x_ref=x; //compiler error

int x{100};
void func(int &num);//A
func(x); //call A-x is an l-value
func(200);

l-value and r-value reference parameter
int x{100}; //x is an l-value
void func(int &num); //A
void func(int &&num);
func(X);
func(200); //calls B-200 is an r-value



*/



#include<bits/stdc++.h>

using namespace std;
class Move{
    private:
    int *data;
    public:
    void set_data_value(int d){
        *data=d;
    }
    int get_data_value(){
        return *data;
    }
   Move(int d){
       data=new int;
       *data=d;
       cout<<"Constructor For : "<<d<<endl;
   }
   //copy constructor
   Move(const Move &source) //l-value reference &
   {
       Move(*source.data);
       cout<<"Copy constructor--deep copy for : "<<*data<<endl;
   }
   //move constructor
   Move(Move &&source)noexcept  //r-value reference &&
   :data{source.data}{
       
       source.data=nullptr;
       cout<<"Move constructor -Moving resource : "<<*data<<endl;
   }
    ~Move()
    {
        if(data!=nullptr)
        {
            cout<<"Destructor freeing data"<<*data<<endl;

        }
        else
        {
            cout<<"Destructor freeing data for nullptr"<<endl;
        }
        delete data;
    }
};
int main()
{
 vector<Move>vec;   
 vec.push_back(Move{10});
 vec.push_back(Move{20});
 vec.push_back(Move{30});
 vec.push_back(Move{40});
}