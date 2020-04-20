#include <iostream>
#include "leaderboard.h"
#include <fstream>
#include <string>
Leaderboard::Leaderboard()
{
    std::fstream in;
    in.open("records.txt");
    //
    in.close();

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
        std::cout << i+1 << ") " << records[i].first << " " << records[i].second; 
    }
}
bool Leaderboard::is_valid(std::string str)
{
    int space = str.find(" ");
    if(space < 1)
    {
        std::cout << "Invalid input!\n";
        return false;
    }
    for (int i = space + 1; i < str.length(); ++i)
    {
        if(!isdigit(str[i]))
        {
            std::cout << "Invalid input!\n";
            return false;
        }

    }
}
void Leaderboard::compare()
{

}
void Leaderboard::parser(std::fstream in)
{
    int i = 0;
    std::string str;
    while(std::getline(in,str))
    {
        if(!is_valid(str))
        continue;
        records[i].first = str;
        int space = str.find(" ");
        records[i].first.erase(space, str.length());
        records[i].second << str[space+1];
        i++; 
    }
}