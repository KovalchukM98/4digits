#ifndef MENU
#define MENU

#include "menu.h"

Menu::Menu()
{
    leaderboard = new Leaderboard;
    lenght = 4;
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
        std::cout << "1 new game\n";
        std::cout << "2 leaders board\n";
        std::cout << "3 about program\n";
        std::cout << "4 settings\n";
        std::cout << "5 exit\n";
        std::getline(std::cin, str);
        if (!is_input_valid(str,1,5)) {
            std::cout << "invalid input\n";
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
            settings();
            break;
        case 5:
            flag = true;
        }
    }
    return 0;
}

void Menu::settings()
{
    std::string str;
    bool is_valid = false;
    int in;
    while (!is_valid) {
        std::cout << "enter new lenght of sequence from 2 to 9\n";
        std::getline(std::cin, str);
        if (!is_input_valid(str,2,9)) {
            std::cout << "invalid input\n";
        } else {
            in = str[0] - 48;
            is_valid = true;
        }
    }
    lenght = in;
}

bool Menu::is_input_valid(std::string str, int minValid, int maxValid)
{
    if (str.size() > 1) {
        return false;
    }
    int key = str[0] - 48;
    if (key < minValid || maxValid > 9) {
        return false;
    }
    return true;
}

void Menu::start()
{
    game = new Game(lenght);
    int res = game->join();
    leaderboard->compare(res);
    delete game;
}

void Menu::about()
{
    std::string line;

    std::ifstream in("data/about.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            std::cout << line << std::endl;
        }
    }
    in.close();
}

#endif
