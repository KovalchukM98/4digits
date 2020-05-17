#include "menu.h"

Menu::Menu()
{
    lenght = 4;
}

Menu::~Menu(){}

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
        if (!is_menu_input_valid(str)) {
            std::cout << "invalid input\n";
            continue;
        }
        key = str[0] - 48;
        switch (key) {
        case 1:
            start();
            break;
        case 2:
            leaderboard.show_leader_board();
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
        if (!is_settings_input_valid(str)) {
            std::cout << "invalid input\n";
        } else {
            in = str[0] - 48;
            is_valid = true;
        }
    }
    lenght = in;
}

bool Menu::is_settings_input_valid(std::string str)
{
    if (str.size() > 1) {
        return false;
    }
    int in = str[0] - 48;
    for (int i = 2; i < 10; ++i) {
        if (in == i) {
            return true;
        }
    }
    return false;
}

bool Menu::is_menu_input_valid(std::string str)
{
    if (str.size() > 1) {
        return false;
    }
    int key = str[0] - 48;
    if (key < 1 || key > 5) {
        return false;
    }
    return true;
}

void Menu::start()
{
    game.set_lenght(lenght);
    int res = game.play();
    leaderboard.compare(res);
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
