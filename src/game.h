#ifndef GAME_H
#define GAME_H

#include "sequence.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
class Game {
public:
    Game();

    Game(std::vector<char> alphabet, int lenght);

    ~Game();

    int play();

    void set_lenght(int s);

    bool is_valid(std::string str);

    std::string get_input();

    bool result_show(std::pair<int, int> result, std::string input);

private:
    std::vector<char> alphabet;
    // Sequence* sec;
    int turns;
    int seq_lenght;
};

#endif