#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
class MyString{
    public:
    char str1[25];

  
    MyString(char a[] )
    {
        strcpy(str1,a);
    }
int operator <=(const MyString &A)
{
    if(strlen(str1)<=strlen(A.str1))
    {
        return 1;
    }
    else
    return 0;
}
int operator >=(const MyString &i)
{
    if(strlen(str1)>=strlen(i.str1))
    { 
        return 1;
    }
    else
    return 0;

}
int operator==(const MyString &s2)
{
    if(strcmp(str1,s2.str1)==0)
    return 1;
    else
    return 0;
}
};
int main()
{
    char s[]="Hello";
    char h[]="king";
    MyString mS1(s),mS2(h);
    if(mS1==mS2)
    {
cout<<mS1.str1<<"is equal to "<<mS2.str1<<endl;
    }
    
  else if(mS1>=mS2)
    {
        cout<<mS1.str1<<"is greater than"<<mS2.str1<<endl;
    }
    else if(mS2>=mS1)
    {
        cout<<mS2.str1<<"is greater than"<<mS1.str1<<endl;

    }
    else
    {
        cout<<"both are not equal"<<endl;
    }
    

}

