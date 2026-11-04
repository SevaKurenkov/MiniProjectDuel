#include "Game.h"
#include <iostream>
#include <string>
// TODO: конструктор, printState(), run().
// Читайте строки через std::getline(std::cin, command).
Game::Game() : hero_(20), enemy_(24), potions_(2){}

void Game::printState() const {
	std::cout << "STATE " << hero_.hp() << " " << enemy_.hp() << " " << potions_ << std::endl;
}

void Game::run() {
	std::string command;
	while (std::getline(std::cin, command)) {
		if (command == "QUIT") { std::cout << "BYE"; return; }
		else if (command == "STATUS") { printState(); }
		else if (command == "HEAL") 
		{
			if (potions_ == 0) { std::cout << "NO_POTIONS" << std::endl; }
			else if (potions_ > 0) { 
				potions_--;
				hero_.heal(8);
				hero_.takeDamage(5);
				if (!hero_.alive()) { std::cout << "LOSE"; return; }
				else { printState(); } 
			}
		}
		else if (command == "ATTACK")
		{
			enemy_.takeDamage(6);
			if (!enemy_.alive()) { std::cout << "WIN"; return; } 
			else { hero_.takeDamage(5); if (!hero_.alive()) { std::cout << "LOSE"; return; }
			else { printState(); }
			}
		}
	}
}