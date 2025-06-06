#include <bits/stdc++.h>
#include "pokemon.h"

using namespace std;

pokemon::pokemon(string n, type t, int h, int x, int a, int d)
    : name(n), poke_type(t), hp(h), xp(x), attack(a), defence(d) {

}

type string_to_type(string s) {
    for (auto &c : s) c = tolower(c);

    if (s == "normal") return Normal;
    else if (s == "fire") return Fire;
    else if (s == "water") return Water;
    else if (s == "electric") return Electric;
    else if (s == "grass") return Grass;
    else if (s == "ice") return Ice;
    else if (s == "fighting") return Fighting;
    else if (s == "poison") return Poison;
    else if (s == "ground") return Ground;
    else if (s == "flying") return Flying;
    else if (s == "psychic") return Psychic;
    else if (s == "bug") return Bug;
    else if (s == "rock") return Rock;
    else if (s == "ghost") return Ghost;
    else if (s == "dragon") return Dragon;
    else if (s == "dark") return Dark;
    else if (s == "steel") return Steel;
    else if (s == "fairy") return Fairy;
    else if (s == "stellar") return Stellar;
    else return Unknown;
}

string type_to_string(type t) {
    switch (t) {
        case Normal: return "Normal";
        case Fire: return "Fire";
        case Water: return "Water";
        case Electric: return "Electric";
        case Grass: return "Grass";
        case Ice: return "Ice";
        case Fighting: return "Fighting";
        case Poison: return "Poison";
        case Ground: return "Ground";
        case Flying: return "Flying";
        case Psychic: return "Psychic";
        case Bug: return "Bug";
        case Rock: return "Rock";
        case Ghost: return "Ghost";
        case Dragon: return "Dragon";
        case Dark: return "Dark";
        case Steel: return "Steel";
        case Fairy: return "Fairy";
        case Stellar: return "Stellar";
        default: return "Unknown";
    }
}

double type_effectiveness(type attacker, type defender);

void show_type_help() {
    cout << "Type List:\n";
    cout << " 0. Normal\n 1. Fire\n 2. Water\n 3. Electric\n 4. Grass\n";
    cout << " 5. Ice\n 6. Fighting\n 7. Poison\n 8. Ground\n 9. Flying\n";
    cout << "10. Psychic\n11. Bug\n12. Rock\n13. Ghost\n14. Dragon\n";
    cout << "15. Dark\n16. Steel\n17. Fairy\n18. Stellar\n19. Unknown\n";
}



void pokemon::add_pokemon() {
    cout << "Enter Pokemon Name: ";
    cin >> name;

    cout << "Enter Pokemon Type (name or h for help): ";
    string input;
    cin >> input;

    if (input == "h" || input == "H") {
        show_type_help();
        cout << "Enter Type Again: ";
        cin >> input;
    }
    if(input>="0" && input<="19"){
        int n = stoi(input);
        poke_type = static_cast<type>(n);
    }
    else poke_type = string_to_type(input);

    cout << "Enter HP: ";
    cin >> hp;
    cout << "Enter XP: ";
    cin >> xp;
    cout << "Enter Attack: ";
    cin >> attack;
    cout << "Enter Defence: ";
    cin >> defence;
}

void pokemon::display_pokemon() {
    cout << "----------------------------" << endl;
    cout << "Pokemon Details:" << endl;
    cout << "----------------------------" << endl;

    cout << "Name    : " << name << endl;
    cout << "Type    : "<<type_to_string(poke_type)<<endl;
    cout << "HP      : " << hp << endl;
    cout << "XP      : " << xp << endl;
    cout << "Attack  : " << attack << endl;
    cout << "Defence : " << defence << endl;

    cout << "----------------------------" << endl;
}

pair<pokemon,pokemon> duel(pokemon &a, pokemon &b) {
    double a_damage = a.attack * type_effectiveness(a.poke_type, b.poke_type);
    double b_damage = b.attack * type_effectiveness(b.poke_type, a.poke_type);
    pair<pokemon,pokemon> p;
    if (a_damage > b_damage) {
        a.xp += 10;
        b.xp += 2;
        p=make_pair(a,b);

    }
    else if (b_damage > a_damage) {
        b.xp += 10;
        a.xp += 2;
        p=make_pair(b,a);
    }
    else {
        a.xp += 5;
        b.xp += 5;
        pokemon tie("Tie", Unknown, 0, 0, 0, 0);
        p=make_pair(tie,tie);
    }
    return p;
}

void pokemon::display_winner() {
    cout << name << " won the battle! " << endl;
    cout << "XP increased to: " << xp << endl;
}

void pokemon::display_loser() {
    cout << name << " lost the battle." << endl;
    cout << "XP increased to: " << xp << endl;
}


void display_duel(const pokemon &p1, const pokemon &p2) {
    cout << "   Battle Start!  " << endl;
    cout << "--------------------------------" << endl;
    cout << "     " << p1.name << "  vs  " << p2.name << endl;
    cout << "--------------------------------" << endl;
    cout << "Get ready for an epic showdown!" << endl << endl;
}

void display_duel_end(pokemon &winner,pokemon &loser) {
    if (winner.xp == loser.xp) {
        std::cout << "It's a tie!" << std::endl;
    } 
    else {
        winner.display_winner();
        loser.display_loser();
    }
}


double type_effectiveness(type attacker, type defender) {

    if (attacker == Normal) {
        if (defender == Rock || defender == Steel) return 0.5;
        if (defender == Ghost) return 0.0;
    }
    else if (attacker == Fire) {
        if (defender == Fire || defender == Water || defender == Rock || defender == Dragon) return 0.5;
        if (defender == Grass || defender == Ice || defender == Bug || defender == Steel) return 2.0;
    }
    else if (attacker == Water) {
        if (defender == Water || defender == Grass || defender == Dragon) return 0.5;
        if (defender == Fire || defender == Ground || defender == Rock) return 2.0;
    }
    else if (attacker == Electric) {
        if (defender == Electric || defender == Grass || defender == Dragon) return 0.5;
        if (defender == Water || defender == Flying) return 2.0;
        if (defender == Ground) return 0.0;
    }
    else if (attacker == Grass) {
        if (defender == Fire || defender == Grass || defender == Poison || defender == Flying || defender == Bug || defender == Dragon || defender == Steel) return 0.5;
        if (defender == Water || defender == Ground || defender == Rock) return 2.0;
    }
    else if (attacker == Ice) {
        if (defender == Fire || defender == Water || defender == Ice || defender == Steel) return 0.5;
        if (defender == Grass || defender == Ground || defender == Flying || defender == Dragon) return 2.0;
    }
    else if (attacker == Fighting) {
        if (defender == Poison || defender == Flying || defender == Psychic || defender == Bug || defender == Fairy) return 0.5;
        if (defender == Normal || defender == Ice || defender == Rock || defender == Dark || defender == Steel) return 2.0;
        if (defender == Ghost) return 0.0;
    }
    else if (attacker == Poison) {
        if (defender == Poison || defender == Ground || defender == Rock || defender == Ghost) return 0.5;
        if (defender == Grass || defender == Fairy) return 2.0;
        if (defender == Steel) return 0.0;
    }
    else if (attacker == Ground) {
        if (defender == Grass || defender == Bug) return 0.5;
        if (defender == Fire || defender == Electric || defender == Poison || defender == Rock || defender == Steel) return 2.0;
        if (defender == Flying) return 0.0;
    }
    else if (attacker == Flying) {
        if (defender == Electric || defender == Rock || defender == Steel) return 0.5;
        if (defender == Grass || defender == Fighting || defender == Bug) return 2.0;
    }
    else if (attacker == Psychic) {
        if (defender == Psychic || defender == Steel) return 0.5;
        if (defender == Fighting || defender == Poison) return 2.0;
        if (defender == Dark) return 0.0;
    }
    else if (attacker == Bug) {
        if (defender == Fire || defender == Fighting || defender == Poison || defender == Flying || defender == Ghost || defender == Steel || defender == Fairy) return 0.5;
        if (defender == Grass || defender == Psychic || defender == Dark) return 2.0;
    }
    else if (attacker == Rock) {
        if (defender == Fighting || defender == Ground || defender == Steel) return 0.5;
        if (defender == Fire || defender == Ice || defender == Flying || defender == Bug) return 2.0;
    }
    else if (attacker == Ghost) {
        if (defender == Dark) return 0.5;
        if (defender == Psychic || defender == Ghost) return 2.0;
        if (defender == Normal) return 0.0;
    }
    else if (attacker == Dragon) {
        if (defender == Steel) return 0.5;
        if (defender == Dragon) return 2.0;
        if (defender == Fairy) return 0.0;
    }
    else if (attacker == Dark) {
        if (defender == Fighting || defender == Dark || defender == Fairy) return 0.5;
        if (defender == Psychic || defender == Ghost) return 2.0;
    }
    else if (attacker == Steel) {
        if (defender == Fire || defender == Water || defender == Electric || defender == Steel) return 0.5;
        if (defender == Ice || defender == Rock || defender == Fairy) return 2.0;
    }
    else if (attacker == Fairy) {
        if (defender == Fire || defender == Poison || defender == Steel) return 0.5;
        if (defender == Fighting || defender == Dragon || defender == Dark) return 2.0;
    }


    return 1.0;
}
