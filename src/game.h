#ifndef GAME_H
#define GAME_H

#include "sequence.h"
#include <utility>
#include <string>
class Game {
public:
    Game();

    ~Game();

    int join();

private:
    bool is_valid(std::string str, int lenght);

    bool result_check(std::pair<int, int> result);

    std::vector<char> alphabet;
    Sequence* sec;
    int turns;
};

#endif