#ifndef GAME_H
#define GAME_H

#include "sequence.h"
#include <string>
#include <utility>
class Game {
public:
    Game(int lenght);

    ~Game();

    int join();

private:
    bool is_valid(std::string str);

    std::string get_input();

    bool result_show(std::pair<int, int> result, std::string input);

    std::vector<char> alphabet;
    Sequence* sec;
    int turns;
    int seq_lenght;
};

#endif