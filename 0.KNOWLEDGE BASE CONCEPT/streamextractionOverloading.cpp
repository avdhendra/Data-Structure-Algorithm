#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
    //overloaded insertion operator
    friend istream &operator >>(istream& in,Mystring &obj)
    {char*buff=new char[1000];
    cin>>buff;
    obj=Mystring{buff};
    delete[]buff;
    return in;
      


    }
    //Overloading extraction operator
    friend ostream &operator<<(ostream&os,const Mystring&obj)
    {
       cout<<obj.str;
       return os;
    }


    private:
    char* str;
    public:
    Mystring():str(nullptr)
    {
        str=new char[1];
        *str='\0';
    }
    Mystring(const char*s):str{nullptr}
    {
        if(str==nullptr)
        {
            str=new char[1];
            *str='\0';

        }
        
        
        str=new char[strlen(s)+1];
strcpy(str,s);
        

    }
    //Overloading Operator
    Mystring(const Mystring&source)
    :str{nullptr}{
        str=new char[strlen(source.str)+1];
        strcpy(str,source.str);
       
    }
    //copy contructor
    Mystring(Mystring &&source)
    :str{source.str}{
        source.str=nullptr;

    }//move constructor
    ~Mystring()
    {
delete [] str;
    }
    //destructor
    Mystring &operator=(const Mystring &rhs)
    {
if(this ==&rhs)
return *this;
delete[] str;
str=new char[strlen(rhs.str)+1];
strcpy(str,rhs.str);
return *this;
    }
    //Copy assignment
    Mystring &operator =(Mystring &&rhs)
    {
        if(this==&rhs)
        return *this;
        delete[] str;
     str=rhs.str;
     rhs.str=nullptr;
     return *this;

    }
    //Move assignmenet
    void display() const
    {
cout<<get_length()<<endl;
    }
    int get_length()const
    {
        return strlen(str);

    }
    const char*get_str()const
    {
        return str;

    }

};

int main()
{ 
    Mystring larry{"larry"};
    Mystring moe{"Moe"};
    Mystring curly;
    cout<<"Enter the third stooge first name :  ";
    cin>>curly;
    cout<<"The three stooges are "<<larry<<" , "<<moe<<" and "<<curly<<endl;
    
    cout<<"Enter The Three stooges name separated by a space : "<<endl;
    cin>>larry>>moe>>curly;
    cout<<"three stooges are"<<larry<<","<<moe<<"and"<<curly<<endl;
    
}
