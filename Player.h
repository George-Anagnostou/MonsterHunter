// Player

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Creature.h"
#include "Potion.h"

class Player : public Creature {
private:
	int m_level {};

public:
	Player(std::string name)
	: Creature{ name, '@', 10, 1, 0 }
	, m_level { 1 }
	{}

	void levelUp() { 
		++m_level; 
		++m_damage;
	}
	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }
	void drinkPotion(const Potion& potion) {
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
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
	out << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";
	return out;
}

#endif