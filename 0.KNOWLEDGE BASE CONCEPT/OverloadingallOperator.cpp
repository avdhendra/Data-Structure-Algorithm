#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
    
    
    
    
    
    private:
    char*str;
    public:
    Mystring():str(nullptr)
    {
      str=new char[1];
      *str='\0';

    }
    Mystring(const char *s):str{nullptr}
    {
        if(str==nullptr)
        {
            str=new char[1];
            *str='\0';
        }
        str=new char[strlen(s)+1];
        strcpy(str,s);

    }
    Mystring(const Mystring&source)
    :str{nullptr}{
        
        str=new char[strlen(source.str)+1];
strcpy(str,source.str);

    }
    Mystring(Mystring&&source)
    :str{source.str}{
        source.str=nullptr;

    }
    ~Mystring()
    {
        delete [] str;
    }
    Mystring &operator=(const Mystring&rhs)
   {if(this==&rhs)
   return *this;
   delete []str;
   str=new char[strlen(rhs.str)+1];
   strcpy(str,rhs.str);
   return *this;
   

    }
    Mystring &operator =(Mystring&&rhs)
    {
        if(this==&rhs)
        return *this;
        delete[]str;
        str=rhs.str;
        rhs.str=nullptr;
        return *this;
    }
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
     friend istream& operator>>(istream &in,Mystring &rhs)
    {
        char*buff=new char[1000];
        in>>buff;
        rhs=Mystring{buff};
        delete [] buff;
        return in;
    }
    friend ostream &operator<<(ostream&os,const Mystring&obj)
    {
       cout<<obj.str;
       return os;
    }
    Mystring operator-()const{
        char*buff=new char[strlen(str)+1];
        strcpy(buff,str);
        for(size_t i=0;i<strlen(str);i++)
        {
     buff[i]=tolower(buff[i]);
        }
        Mystring temp{buff};
        delete [] buff;
        return temp;
    } //Make Lowercase
    Mystring operator+(const Mystring &rhs)const
    {
        char* buff= new char[strlen(str)+strlen(rhs.str)+1];
        strcpy(buff,str);
        strcat(buff,rhs.str);

    }//concatenate
    bool operator==(const Mystring &rhs)
    {
return(strcmp(str,rhs.str)==0);
    }
    //equal
    bool operator!=(const Mystring &rhs)const
    {

    }//not equal
    bool operator<(const Mystring &rhs)const
    {return (strcmp(str,rhs.str)<0);

    }//less than
    bool operator>(const Mystring &rhs)const
    {
return (strcmp(str,rhs.str)>0);
    }//greater than
    Mystring& operator+=(const Mystring &rhs)
    {
      *this = *this +rhs;
return *this;

    }//s1+=s2 concat and assign
    Mystring operator*(int n)
    { Mystring temp;
    for(int i=0;i<n;i++)
    {
        temp=temp+*this;
        return temp;
    }

    }//s1=s2*3 repeat s2 n times
   
    Mystring &operator++()
    {
        for(size_t i=0;i<strlen(str);i++)
        str[i]=toupper(str[i]);
return *this;


    }
    //preincreament ++s1 make string upper case

    Mystring operator++(int )
    {Mystring temp{*this};
    operator++(); //call pre increment make sure u call preincreament
return temp; //return the old value
    }//post increament s++
    
    
};


int main()
{
cout<<boolalpha<<endl;
Mystring a{"frank"};
Mystring b{"frank"};
cout<<(a==b)<<endl; //true;
cout<<(a!=b)<<endl;//false;
b="george";
cout<<(a==b)<<endl;
cout<<(a!=b)<<endl;









}