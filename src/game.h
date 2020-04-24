#ifndef GAME_H
#define GAME_H

#include "sequence.h"
#include <string>
#include <utility>
class Game {
public:
    Game();

    ~Game();

    int join();

private:
    bool is_valid(std::string str, int lenght);

    std::string get_input(int lenght);

    bool result_show(std::pair<int, int> result, std::string input, int turns);

    std::vector<char> alphabet;
    Sequence* sec;
    int turns;
};

#endif