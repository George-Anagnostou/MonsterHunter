#include <iostream>
#include "Creature.h"
#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "Random.h"

std::string getUserName() {
	std::cout << "Enter your name: ";
	std::string name {};
	std::cin >> name;
	return name;
}

void welcome(std::string_view name) {
	std::cout << "Welcome, " << name << '\n';
}

char runOrFight() {
	std::cout << "(r)un or (f)ight: ";
	char action {};
	std::cin >> action;
	return action;
}

void attackMonster(Player& player, Monster& monster) {
	if (player.isDead()) {
		return;
	}
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
	monster.reduceHealth(player.getDamage());
	if (monster.isDead()) {
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(const Monster& monster, Player& player) {
	if (monster.isDead()) {
		return;
	}
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
	player.reduceHealth(monster.getDamage());
}

char getChoice() {
	std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
	char choice {};
	std::cin >> choice;
	return choice;
}

void findPotion(Player& player) {
	auto potion { Potion::getRandomPotion() };
	char choice { getChoice() };
	if (choice == 'y') {
		player.drinkPotion(potion);
		std::cout << "You drank a " << potion.getName() << ".\n";
	}
}

void fightMonster(Player& player) {
	Monster monster { Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
	while (!monster.isDead() && !player.isDead()) {
		char action { runOrFight() };
		if (action == 'f') {
			attackMonster(player, monster);
			attackPlayer(monster, player);
			if (monster.isDead()) {
				constexpr int potionChance { 30 };
				if (Random::get(1, 100) <= potionChance) {
					findPotion(player);
				}
			}
		}
		if (action == 'r') {
			// 50% chance of fleeing successfully
			if (Random::get(1, 2) == 1) {
				std::cout << "You fled successfully.\n";
				return;
			} else {
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
			}
		}
	}
}

int main() {
	Player player { getUserName() };
	welcome(player.getName());

	while (!player.isDead() && !player.hasWon()) {
		fightMonster(player);
	}

	if (player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	} else {
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}
