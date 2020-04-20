#include <iostream>
#include "leaderboard.h"
#include <fstream>
#include <string>

void Leaderboard::parser()
{
    in.open("src/records.txt");
    int i = 0;
    std::string str;
    while (getline(in, str))
    {
        if (!is_valid(str)) {
            continue;
        }
        records[i].first = str;
        int space = str.find(" ");
        records[i].first.erase(space, str.length());
        str.erase(0, space+1);
        for (unsigned int j = 0; j < str.length(); ++j) {
            records[i].second *= 10;
            records[i].second += str[j] - 48;
        }
        // records[i].second = atoi(str);
        i++;
    }
    in.close();
}
Leaderboard::Leaderboard()
{
    Leaderboard::parser();
}

Leaderboard::~Leaderboard()
{
    std::fstream out;
    out.open("records.txt");
    //
    out.close();
}

void Leaderboard::show_leader_board()
{
    for(int i = 0; i < 10;++i)
    {   
        if(records[i].second == 0){
            break;
        }
        std::cout << i+1 << ") " << records[i].first << " " << records[i].second << std::endl; 
    }
    std::cout << std::endl;
}
bool Leaderboard::is_valid(std::string str)
{
    int space = str.find(" ");
    if(space < 1)
    {
        std::cout << "Invalid input!\n";
        return false;
    }
    for (unsigned int i = space + 1; i < str.length(); ++i)
    {
        if(!isdigit(str[i]))
        {
            std::cout << "Invalid input!\n";
            return false;
        }

    }
    return true;
}


void Leaderboard::compare()
{

}

