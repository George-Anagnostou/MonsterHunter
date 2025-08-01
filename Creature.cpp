// Creature Implementation

#include <iostream>
#include "Creature.h"

void Creature::displayStatus() const {
    std::cout << '\t' << "Health: " << getHealth() << '\n';
    std::cout << '\t' << "Damage: " << getDamage() << '\n';
}