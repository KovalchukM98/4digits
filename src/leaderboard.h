#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

class Leaderboard {
public:
    Leaderboard();
    ~Leaderboard();
    void show_leader_board();
    void compare(int turns);
    bool is_data_valid(std::string str);
    void load_from_file(std::string path);
    void clear();
    bool is_name_valid(std::string name);
    std::string get_name();
    void save_to_file(std::string path);
    void insert(std::string name, int turns, int pos);
    std::pair<std::string, int> get_record(int pos);

private:
    std::fstream in;
    std::pair<std::string, int> records[10];
};

#endif