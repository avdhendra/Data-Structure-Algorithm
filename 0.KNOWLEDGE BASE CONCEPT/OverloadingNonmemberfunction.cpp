//Overloading operator as non-member(global) methods


#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
    private:
    char*str;
    public:
friend bool operator==(const Mystring &lhs,const Mystring &rhs)
{
    return (strcmp(lhs.str,rhs.str)==0);

}
friend Mystring operator-(const Mystring&obj)
{
char*buff=new char[strlen(obj.str)+1];
strcpy(buff,obj.str);
for(size_t i=0;i<strlen(obj.str);i++)
buff[i]=tolower(buff[i]);
Mystring temp{buff};
delete [] buff;
return temp;
}
friend Mystring operator+(const Mystring&lhs,const Mystring&rhs)
{
    char*buff=new char[strlen(lhs.str)+strlen(rhs.str)+1];
    strcpy(buff,lhs.str);
    strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
return temp;

}

    Mystring():str(nullptr)
{
    str=new char[1];
    *str='\0';
}
    //
    Mystring(const char*s):str(nullptr)
    {
        if(str==nullptr)
        {
            str=new char[1];
            str='\0';
        }
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }//overloading constructor
    Mystring(const Mystring&source) //copy constructor
    :str(nullptr){
        str=new char[strlen(source.str)+1];
        strcpy(str,source.str);

    }
    //move constructior
    Mystring(Mystring &&source):str(source.str)
    {
        source.str=nullptr;
    }
    ~Mystring()
    {
        delete [] str;

    }
    Mystring&operator=(const Mystring&rhs)//copy assignment
    {if(this==&rhs)
    return *this;
    delete []str;
    str=new char[strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;

    }
    Mystring&operator=(Mystring&&rhs)//move assignment
    {
       if(this==&rhs)
       return *this;
       delete[]str;
       str=rhs.str;
       rhs.str=nullptr;
       return *this; 
    }
    void display()const
    {
        cout<<str<<" : "<<get_length()<<endl; 
    }
    int get_length()const
    {
        return strlen(str);


    }
    const char*get_str() const
    {
        return str;
    }
};
int main()
{
    cout<<boolalpha<<endl;
Mystring larry{"LARRY"};
larry.display();
larry=-larry;
larry.display();
Mystring moe{"MOE"};
Mystring stooge=larry;
stooge.display();
cout<<(larry==moe)<<endl;
cout<<(larry==stooge)<<endl;
stooge=larry+moe;
stooge.display();
}
