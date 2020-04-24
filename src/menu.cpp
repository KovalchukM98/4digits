#ifndef MENU
#define MENU

#include "menu.h"
#include "game.h"
#include "leaderboard.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

Menu::Menu()
{
    leaderboard = new Leaderboard;
}

Menu::~Menu()
{
    delete leaderboard;
}

int Menu::join()
{
    int key = 0;
    std::string str;
    bool flag = false;
    while (!flag) {
        std::cout << "1 new game" << std::endl;
        std::cout << "2 leaders board" << std::endl;
        std::cout << "3 about program" << std::endl;
        std::cout << "4 exit" << std::endl;
        std::getline(std::cin, str);
        if (!is_valid(str)) {
            std::cout << "invalid input" << std::endl;
            continue;
        }
        key = str[0] - 48;
        switch (key) {
        case 1:
            start();
            break;
        case 2:
            leaderboard->show_leader_board();
            break;
        case 3:
            about();
            break;
        case 4:
            flag = true;
        }
    }
    return 0;
}

bool Menu::is_valid(std::string str)
{
    if (str.size() > 1) {
        return false;
    }
    int key = str[0] - 48;
    if (key < 1 || key > 4) {
        return false;
    }
    return true;
}

void Menu::start()
{
    game = new Game;
    int res = game->join();
    leaderboard->compare(res);
    delete game;
}

void Menu::about()
{
}

#endif