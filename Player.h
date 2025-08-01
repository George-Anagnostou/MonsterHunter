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
	void drinkPotion(const Potion& potion);
};

#endif