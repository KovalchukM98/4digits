#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <utility>
#include <string>
#include <fstream>

class Leaderboard
{
public:
    Leaderboard();
    ~Leaderboard();
    void show_leader_board();
    void compare();
    bool is_valid(std::string str);
    void parser();
private:
    std::fstream in;
    std::pair<std::string, int> records[10];
};

#endif