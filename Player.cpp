// Player Implementation

#include "Player.h"

void Player::drinkPotion(const Potion& potion) {
    switch (potion.getType()) {
    case Potion::health:
        m_health += ((potion.getSize() == Potion::large ? 5 : 2));
        break;
    case Potion::strength:
        m_damage += 1;
        break;
    case Potion::poison:
        m_health -= 1;
        break;
    default:
        std::cout << "Invalid state.\n";
        break;
    }
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
	out << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";
	return out;
}
