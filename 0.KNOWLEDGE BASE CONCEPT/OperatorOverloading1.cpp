//Copy assignment operator(=)
/*
s1=s2 two object are equal*/
/*
Default is memberwise assignment(shallow copy)
*if we have raw pointer data member we must deep copy
*/
#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
    private:
    char *str; //pointer to a char that holds a c-style
    public:
    Mystring();
    Mystring(const char*s);         //Overload Constructor
    Mystring(const Mystring &source);//Copy constructor
    Mystring(Mystring &&source);   //Move Constructor
    ~Mystring();                  //Destructor

   Mystring &operator=(const Mystring &rhs); //copy constructor
   Mystring &operator=(Mystring &&rhs); //Move assignment
   void display()const;
   int get_length()const;   //getter
   const char*get_str()const;
};
Mystring::Mystring()
:str(nullptr){
    str=new char[1];
    *str='\0';

}
Mystring::Mystring(const char*s):
str(nullptr)
{
    if(str==nullptr)
    {
        str=new char[1];
        *str='\0';

    }
    else{
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }
}
//Copy Constructor//deep copy
Mystring::Mystring(const Mystring &source)
:str(nullptr){
    str=new char[strlen(source.str)+1];
    strcpy(str,source.str);
}

//Move constructor
Mystring::Mystring(Mystring &&source)
:str(source.str){
    source.str=nullptr;
    cout<<"Move Constructor used : "<<endl;


}
Mystring::~Mystring()
{
    if(str==nullptr)
    {
        cout<<"Calling destructor for mystring : Nullptr"<<endl;
    }
    else{
        cout<<"calling destructor for Mystring : "<<str<<endl;

    }
    delete[]str;
}
//copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    cout<<"Using copy assignment : "<<endl;
    if(this==&rhs)
    return *this;
    delete []str;
    str=new char[strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
Mystring &Mystring ::operator=(Mystring &&rhs)
{
    cout<<"USING MOVE ASSIGNMENT :: "<<endl;
    if(this==&rhs)
     return *this;
     delete []str;
     str=rhs.str;
     rhs.str=nullptr;
     return *this;
    

}
int main()
{
    Mystring a{"hello"}; //Overload constructor
    a=Mystring{"Hola"};  //Overload Constructor then move assignment
    a="Bonjour"; //Overload Constructor then Move assignment

}