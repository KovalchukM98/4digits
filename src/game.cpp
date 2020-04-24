#ifndef GAME
#define GAME
#include "game.h"
#include "sequence.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

Game::Game()
{
    alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    sec = new Sequence(alphabet);
    turns = 0;
}

Game::~Game()
{
    delete sec;
}

int Game::join()
{
    bool is_game_over = false;
    int lenght = 4;
    std::pair<int, int> result;
    std::string input;
    while (!is_game_over) {
        input = get_input(lenght);
        if (input.size() == 0) {
            continue;
        }
        input.erase(lenght, input.size());
        turns++;
        result = sec->count_bulls_and_cows(input, lenght);
        is_game_over = result_show(result, input, turns);
    }
    return turns;
}

std::string Game::get_input(int lenght)
{
    std::cout << "enter " << lenght << " numbers from 0 to 9 " << std::endl;
    std::string input;
    getline(std::cin, input);
    if (!is_valid(input, lenght)) {
        std::cout << "invalid input" << std::endl;
        input.clear();
    }
    return input;
}

bool Game::result_show(std::pair<int, int> result, std::string input, int turns)
{
    if (result.first < 4) {
        std::cout << "\n"
                  << "turn : " << turns << std::endl;
        std::cout << "	bulls : " << result.first << std::endl;
        std::cout << "	cows  :" << result.second << "\n" << std::endl;
        return false;
    } else {
        std::cout << "\n 	You win!" << std::endl;
        std::cout << input << " is right answer" << std::endl;
        std::cout << "your turns : " << turns << "\n" << std::endl;
    }
    return true;
}

bool Game::is_valid(std::string str, int lenght)
{
    if (str.size() != static_cast<unsigned int>(lenght)) {
        return false;
    }
    for (int i = 0; i < lenght; ++i) {
        bool is_suitable_symbol = false;
        for (int j = i - 1; j >= 0; --j) {
            if (str[j] == str[i]) {
                return false;
            }
        }

        for (int j = 0; j < 10; ++j) {
            if (str[i] == alphabet[j]) {
                is_suitable_symbol = true;
                break;
            }
        }
        if (!is_suitable_symbol) {
            return false;
        }
    }
    return true;
}

#endif