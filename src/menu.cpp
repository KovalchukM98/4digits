#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "game.h"

using namespace std;

Menu::Menu(){}

Menu::~Menu(){}

void Menu::join(){
		int key = 0;
		std::string str;
		bool flag = false;
		while(!flag){
			std::cout << "1 новая игра" << std::endl;
			std::cout << "2 таблица рекордов" << std::endl;
			std::cout << "3 о программе" << std::endl;
			std::cout << "4 выход" << std::endl;
			std::getline(std::cin , str);
			if(!is_valid(str)){
				std::cout << "некорректный ввод" << std::endl;
				continue;
			}
			key = str[0] - 48;
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

bool Menu::is_valid(string str){
		if(str.size() > 1){
			return false;
		}
		int key = str[0] - 48;
		if(key < 1 || key > 4){
			return false;
		}
		return true;
	}

void Menu::start(){
		game = new Game;
		game->join();
		delete game;
	}

void Menu::show_leader_board(){
		fstream in;
		string str;
		in.open("leaders.txt");
		while(std::getline(in , str)){
			std::cout << str << std::endl;
    	}
	}

void Menu::about(){}

#endif