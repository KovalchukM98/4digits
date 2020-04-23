#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "leaderboard.h"
#include <string>
class Menu {
public:
    Menu();

    ~Menu();

    int join();

    bool is_valid(std::string str);

    void start();

    void about();

private:
    Game* game;
    Leaderboard* leaderboard;
};

#endif