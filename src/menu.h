#ifndef MENU_H
#define MENU_H

#include <string>
#include "game.h"

class Menu{
public:
	Menu();

	~Menu();

	void join();

	bool is_valid(std::string str);

	void start();

	void show_leader_board();

	void about();

private:
	Game *game;
};

#endif