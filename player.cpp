#include <bits/stdc++.h>
using namespace std;

// This is how we create a class
class Player
{
public:
    // These are attributes (Data)
    string name;
    int health;
    int xp;

    // Methods
    void show_health_xp()
    {
        cout << name << "'s Health: " << health << endl;
        cout << name << "'s XP: " << xp << endl;
    }
};

string fight(Player p1, Player p2)
{
    int power1 = p1.xp * p1.health;
    int power2 = p2.xp * p2.health;

    if (power1 > power2)
        return p1.name;
    else if (power2 > power1)
        return p2.name;
    else
        return "Draw";
}

int main()
{
    Player Jeetu; // Jeetu is an object of Player class

    Player *Hero = new Player(); // Create dynamically allocated object

    Jeetu.name = "Jeetu";
    Jeetu.health = 1000; //(.) dot operator used for accesing attr and object for pointers
    Jeetu.xp = 1000;
    // For pointers we have 2 methods , 1st derefrencing & then . or using this
    (*Hero).name = "Hero"; // derefrencing and using .
    Hero->health = 100;    //(->) This operator used for accesing attr and object for pointers
    Hero->xp = 100;
    // ∴ Jeetu >> Hero  Hence proved

    // Method calling
    Jeetu.show_health_xp();
    Hero->show_health_xp();

    string winner = fight(Jeetu, *Hero); // can pass objects to functions *Hero to derefrence
    cout << "Winner is " << winner << endl;

    delete Hero; // ✅ Must be inside function
    return 0;
}
