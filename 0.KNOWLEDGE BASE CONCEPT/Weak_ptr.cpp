/*

Weak_ptr
*Providing a non Owning weak reference
*weak ptr<t>
Point to an object of type T on the Heap
Doesnot Participate in owning relationship
Always created from a shared_ptr
Does not increment or decrement reference use count
*used to prevent strong reference cycle which could prevent object from being deleted




shared_ptr have strong ownership 
A refer to B
B refer to A
 **have memory leak
 Shared Strong ownership prevent heap deallocation


but weak-ptr
solution make one of the Pointer non owning or weak
now heap storage is deallocated properly


*//*
#include<iostream>
#include<memory>
using namespace std;
class B;
class A{
    shared_ptr<B> b_ptr;
    public:
    void set_B(shared_ptr<B>&b)
    {
        b_ptr=b;
    }
    A(){
        cout<<"A constructor"<<endl;
    }
    ~A()
    {
        cout<<"A destructor"<<endl;
    }
};

class B{
  //  shared_ptr<A>a_ptr; //Make weak to break the Strong circular reference
   weak_ptr<A>a_ptr;
    public:
    void set_A(shared_ptr<A>&a)
    {
        a_ptr=a;
    }
    B()
    {
        cout<<"B constructor"<<endl;
    }
    ~B()
    {
        cout<<"B Destructor"<<endl;
    }
};
int main()
{
    shared_ptr<A>a=make_shared<A>();
    shared_ptr<B>b=make_shared<B>();
    a->set_B(b);
    b->set_A(a);


/*
    a---A(use count :1)
    b----B(use count :1)  both are connected to each other so when destructor called 
    so when a and b goes out off scope it goes to destroyed A and B but both are reference to each other
    so a and b get destroyed  we still have memory allocation but we dont have access to it so basically it goes memory leak



}
*/
#include<bits/stdc++.h>
using namespace std;
class Entity{
    public:
    Entity()
    {
        std::cout<<"Created Entity ! "<<std::endl;
    }
    ~Entity()
    {
        std::cout<<"Destroyed Entity !"<<std::endl;
    }
    void Print()
    {

    }
};
int main(){
//Smart Pointer-->Unique Pointer
{
  //  std::unique_ptr<Entity>entity(new Entity());
    
    //we cannot do the entity=new Entity()
    unique_ptr<Entity>entity=make_unique<Entity>();
    entity->Print();
    //when it goes out of scope it got delete

}

{
    shared_ptr<Entity>e0;
    {
        shared_ptr<Entity> sharedEntity=make_shared<Entity>();
      e0=sharedEntity;
    //when shared entity goes out of this scope destory entity not called because we still have one pointer left
    //e0 which points to same address
    }
    //when it goes out of this scope it called Destructor
}

{
    weak_ptr<Entity>e0;
    {
        shared_ptr<Entity> sharedEntity=make_shared<Entity>();
      e0=sharedEntity;
    //when shared entity goes out of this scope destory entity  called 
   
    }
  
    
}


return 0;
}

/*
A weak_ptr is created as a copy of shared_ptr. 
It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting.
 The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies.
  It is required in some cases to break circular references between shared_ptr instances.



*/