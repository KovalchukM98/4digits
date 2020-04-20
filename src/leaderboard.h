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
    void compare(int turns);
    bool is_valid(std::string str);
    void parser();
    bool is_name_valid(std::string name);
private:
    std::fstream in;
    std::pair<std::string, int> records[10];
};

#endif