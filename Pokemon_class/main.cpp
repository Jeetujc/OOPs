#include"pokemon.h"

int main() {
    
    pokemon p1("Charmander", Fire);
    pokemon p2;
    p2.add_pokemon();

    p1.display_pokemon();
    p2.display_pokemon();

    display_duel(p1,p2);
    pair<pokemon, pokemon> result = duel(p1, p2);
    display_duel_end(result.first, result.second);

    return 0;
}
