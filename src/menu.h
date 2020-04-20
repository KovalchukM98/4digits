#ifndef MENU_H
#define MENU_H

#include <string>
#include "game.h"
#include "leaderboard.h"
class Menu{
public:
	Menu();

	~Menu();

	int join();

	bool is_valid(std::string str);

	void start();

	void about();

private:
	Game *game;
	Leaderboard *leaderboard;
};

#endif