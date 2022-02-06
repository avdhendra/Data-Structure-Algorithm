/*delagating Constructor
often the code can lead to errors
***
c++ allows delagating constructors
code for one constructor can call another in the initialzation list
avoid duplication
*/
#include<iostream>
#include<string>
using namespace std;
class Player{
    private:
    string name;
    int health;
    int xp;
    public:
    //overloaded constructors
    Player(string name_val,int health_val,int xp_val)
    :name{name_val},health{health_val},xp{xp_val}{
cout<<"Three args constructor"<<endl;
    }
    Player(string name_val)
    :Player{name_val,0,0}{
        cout<<"Two args constructor"<<endl;
    }
    Player():Player{"None",0,0}{
        cout<<"NO args constructor"<<endl;
    }
};

int main()
{
    Player empty;
    Player frank{"Frank"};
    Player villan{"villain",100,55};

    return 0;
}

