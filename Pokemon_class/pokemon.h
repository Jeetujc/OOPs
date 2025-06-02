#pragma once

#include <bits/stdc++.h>
using namespace std;

enum type {Normal, Fire, Water, Electric, Grass, Ice, Fighting, Poison, Ground, Flying, Psychic, Bug, Rock, Ghost, Dragon, Dark, Steel, Fairy,Stellar,Unknown };

class pokemon
{
private:
    string name;
    type poke_type;
    int hp;
    int xp;
    int attack;
    int defence;
public:
    pokemon(string name="none",type type=Unknown,int hp=100,int xp=3,int attack=50,int defence=50);
    void add_pokemon();
    void display_pokemon();
    void display_winner();
    void display_loser();
    
    friend void display_duel (const pokemon &p1,const pokemon &p2); 
    friend void display_duel_end (pokemon &p1,pokemon &p2); 
    friend pair<pokemon,pokemon> duel(pokemon &a,pokemon &b);
};


