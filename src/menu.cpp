#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "game.cpp"

using namespace std;

class Menu{
public:
	Menu(){}

	~Menu(){}

	void join(){
		cout << "1 новая игра" <<endl;
	}
private:
	Game *game;
}

#endif