/*
We can also use Base class Reference with dynamic Polymorphism
*useful when we pass object to function that except a base class reference

*/
#include<iostream>
using namespace std;
class Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"In Accout:withdraw"<<endl;
    }
   virtual ~Account()
    {
        cout<<"Account:withdraw"<<endl;
    }
};
class Checking:public Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"Checking ::Destructor"<<endl;
    }
   virtual ~Checking()
    {
        cout<<"Checking::Destructor"<<endl;
    }
};
class Saving:public Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"In saving:withdraw"<<endl;
    }

virtual ~Saving()
{
    cout<<"Saving::Destructor"<<endl;

}

};
class Trust:public Account{
    public:
    virtual void withdraw(double Amount)
    {
        cout<<"In saving :withdraw"<<endl;
    }
    virtual ~Trust()
    {
        cout<<"Saving ::Destructor"<<endl;
    }
};
void do_withdraw(Account &account,double amount)
{
    account.withdraw(amount);
}

int main()
{
Account a;
Account &ref=a;
ref.withdraw(100);
Trust t;
Account &ref1=t;
ref1.withdraw(1000);
Account a1;
Saving a2;
Checking a3;
Trust a4;
do_withdraw(a1,1000);
do_withdraw(a2,2000);
do_withdraw(a3,5000);
do_withdraw(a4,4000);
    

}