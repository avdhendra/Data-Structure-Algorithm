#include<iostream>
using namespace std;
class Account
{
    friend ostream& operator <<(ostream&os,const Account&account)
    {
        os<<"Account Balance : "<<account.balance;
        return os;

    }
    protected:
    double balance;
    public:
    Account()
    :Account(0.0){ //delagating constructor

    }
    Account(double balance):balance(balance)
{

}
void deposit(double amount)
{balance+=amount;

}
void withdraw(double amount)
{
    if(balance-amount>=0)
    balance-=amount;
    else
    cout<<"Insufficient Funds"<<endl;

}

};
class Saving_Account:public Account
{
friend ostream&operator <<(ostream &os,const Saving_Account&account)
{
    os<<"saving account Balance : "<<account.balance<<"Intrest rate : "<<account.int_rate<<endl;
    return os;

}
protected:
double int_rate;
public:
Saving_Account():Saving_Account(0.0,0.0)
{

}
Saving_Account(double balance,double int_rate):Account(balance),int_rate(int_rate)
{

}
void deposit(double amount)
{amount=amount+(amount+int_rate/100);
Account::deposit(amount);

}
//withdraw is inhertied


};
int main()
{
cout<<"====Account Class========="<<endl;
Account a1{1000.0};
cout<<a1<<endl;
a1.deposit(500.0);
cout<<a1<<endl;
a1.withdraw(10.0);
cout<<a1<<endl;
cout<<"====Saving Account Class======="<<endl;
Saving_Account s1{100,5.0};
cout<<s1<<endl;
s1.deposit(1000);
cout<<s1<<endl;
s1.withdraw(2000);
cout<<s1<<endl;
s1.withdraw(4000);
cout<<s1<<endl;
}