 /*
 we created a class of player and iits object is intiallied 
 player her{"hero",10,20};
 void display_player(player p){
     // p is a copy of hero in this example use p
     Destructor for will be created
 }
 Display_Player(hero);


Return object by value
player enemy;
player create_super-enemy(){
    player an_enemy{"Super Enemy",1000,1000};
    return an_enemy; //A copy of an_enemy is returned


}
enemy=create_super_enemy();

/***
 * Copy constructor
 * when object are copied c++ must create a new object from an exisiting object
 * when is a copy of an object made
 * passing object by value as a parameter
 * returning an object from function by value
 * constructing one object based another of the same class
 * 
 * c++ must have a way of accomplishing this so it provide a complier
 * defined copy contructor if you dont
 * 
 * Declaring the copy constructor
 * Type(const Type &Source);
 * 



 */
#include<iostream>
#include<string>
using namespace std;
class player{
    string Name;
    int health;
    int xp;
    public:
    string get_name(){
        return Name;
    }
    int get_health()
    {
        return health;
    }
    int get_xp()
{
    return xp;
}
player(string name_val="none",int health_val=0,int xp_val=0)
{
    Name=name_val;
    health=health_val;
    xp=xp_val;
    
}
player(const player &source)
{
    Name=source.Name;
    health=source.health;
    xp=source.xp;
    cout<<"Copy constructor-made copy of"<<source.Name<<endl;
}
~player(){
    cout<<"Destructor called "<<Name<<endl;
}
};
void display(player p)
{
    cout<<"Name : "<<p.get_name()<<endl;
    cout<<"Health : "<<p.get_health()<<endl;
    cout<<"Xp : "<<p.get_xp()<<endl;
}

int main()
{
    player jio{"xxx",100,50};
    player jio2{jio};

player empty;
display(empty);
}