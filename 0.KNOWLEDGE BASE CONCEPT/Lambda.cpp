/*
//syntax 
auto somevar=[](int a,int b)->int{
    //body of the function
}
auto someVar= we want to create a variable called somevar,
and its type is up to the compiler,auto somevar will be something like a function
pointer
[] : capture list(sometimes called closure),the local variable
we want to be able to use within the body of the function
(int a ,int b): parameter list for the Lambda function
->it is optional when the return type is obvious,you dont need to
supply this array nor a return type

int : the return value if the return type is easy to determine this is 
optional along with the arrow thing

*/



#include<iostream>
#include<functional>
using namespace std;
void performance(function<void()>f)
{
    f();
    
}
int main()
{
    auto sayhello=[](){
      cout<<"Hello world"<<endl;
  };  
  sayhello();
  //lambda with parameter
  auto product=[](int x,int y)->int{
      return x*y;
  };
  cout<<"Product is :"<<product(7,10)<<endl;

//That product the lambda is something like a function pointer
//Capture List 
/*By default we can't use any outside variable inside the body of a lamdba
but that exactly what the capture list is for! we can capturespecific variable
by supplying whier names in comma separator list

*/
int a=50;
int b=90;
auto capture=[a,b](int x,int y)->int{
    return a+x+y+b;
/*a=10 is it incorrect*/
};
cout<<"Sum :: "<<capture(10,20)<<endl;
//here we capture the a ,b by value so we cannot change the value of a and b inside 
/*the lambda function*/
auto capture1=[&a ,&b](int x ,int y)->int{
    a=5,b=6;
    return a+x+y+b;
};
cout<<"Sum: "<<capture1(10,30)<<endl;
auto capture2=[=](int x,int y){
    
    return a+b+x+y;
};
/*here[=] means all outside variable will be in function as by value not by reference
 and no value can be change inside it
 */
cout<<"SUM : "<<capture2(2,3)<<endl;
auto capture3=[&](int x,int y)->int
{
    a=10,b=15;
    return x+y+a+b;

};
cout<<"Sum : "<<capture3(2,3)<<endl;
/*here[&] means all outside variable will be in function as by reference so value can be change 
in function */

/*std::function */
int e=100;
auto func=[&](){
e++;
};
performance(func);

cout<<"E :"<<e<<endl;


}