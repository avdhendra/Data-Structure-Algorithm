/*
**Raw Pointer
*C++ Provided absolute flxibilty with memory managemenet
**Allocation
**Deallocation
**Lifetime Managemenet

**Some Pontential serious Problem
*Unintialized pointer
*Memory Leaks
*Dangling Pointer
*Not Exception Safe
**OwnerShip
*Who own the Pointer
*When Should a Pointer Be Deleted

**Smart Pointer
*Objects
*can only Point to Heap-Allocated memory
*Automatically call delete when no longer needed
**Adhere to RAII Principle
C++ Smart Pointer
*Unique Pointer(unique_ptr)
*Shared Pointer(Shared_ptr)
*Weak Pointer(weak_ptr) 

***We cannot do pointer arithmeatic pointer to smart pointer
 *Can have custom deleters



 //RAII-Resource Acquisition Is Initialization

*/


/*Unique Pointer*/
/*
**Points to an object of type T on the Heap

**It is Unique -there can only be one Unique_ptr<T> pointing to the Object on the Heap

**Own what it Point to 

**Cannot Be Assigned or Copied

**Can be Moved

**When the Pointer is Destroyed What it Point to is Automatically Destroyed


**Unique_ptr<int>p1{new int{100}};
cout<<p1.get()<<endl;
p1.reset(); //p1 is now nullptr
if(p1)
{
    cout<<*p1<<endl; //no execute as p1 is null
}
//automatically deleted as out of scope



vector<unique_ptr<int>>vec;
unique_ptr<int>ptr{new int{100}};
vec.push_back(ptr); //Error -copy not allowed


vec.push_back(move(ptr)); dont get error


//Make Unique ptr(c++14)
unique_ptr<int>p1=make_unique<int>(100);
unique_ptr<Account>p2=make_unique<Account>("curly",500);
auto p3=make_Unique<Player>("Hero",100,100);

//More Efficient no call to new or delete



we make a vector or unique pointer to Account
vector<unique_ptr<Account>>Account;
Account.push_back(make_unique<Checking_Account>("James",100))
Account.push_back(make_unique<Saving_Account>("Bily",400,5.2));
Account.psuh_back(make_unique<Trust_Account>("Bobby",500,4.5));
for(auto acc:Account)
{
    cout<<*acc<<endl;
} //we get error because we copy each element of Account to Acc which can not be allowed
//we have to pass it by reference
for(const auto&acc:Account)
{
    cout<<*acc<<endl;
}



***/


