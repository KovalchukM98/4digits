#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "game.cpp"

using namespace std;

class Menu{
public:
	Menu(){}

	~Menu(){}

	void join(){
		int key = 0;
		bool flag = false;
		while(!flag){
			cout << "1 новая игра" << endl;
			cout << "2 таблица рекордов" << endl;
			cout << "3 о программе" << endl;
			cout << "4 выход" << endl;
			cin >> key;
			switch(key){
				case 1 :
				start();
				break;
				case 2 :
				show_leader_board();
				break;
				case 3:
				about();
				break;
				case 4:
				flag = true;
			}
		}
	}

	void start(){
		game = new Game;
		game.join();
		delete game;
	}

	void show_leader_board(){
		fstream in;
		string str;
		in.open("leaders.txt");
		while(getline(in , str)){
			cout << str <<endl;
    	}
	}

	void about(){}

private:
	Game *game;
};

#endif