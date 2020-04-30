#ifndef GAME
#define GAME
#include "game.h"
#include "sequence.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

Game::Game(int lenght)
{
    seq_lenght = lenght;
    alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    sec = new Sequence(alphabet, seq_lenght);
    turns = 0;
}

Game::~Game()
{
    delete sec;
}

int Game::join()
{
    bool is_game_over = false;
    std::pair<int, int> result;
    std::string input;
    while (!is_game_over) {
        std::cout << "true = " << sec->get_answer() << std::endl;
        input = get_input();
        turns++;
        result = sec->count_bulls_and_cows(input);
        result_show(result, input);
        if (result.first == seq_lenght) {
            is_game_over = true;
        }
    }
    return turns;
}

std::string Game::get_input()
{
    std::string input;
    std::cout << "enter " << seq_lenght << " numbers from 0 to 9 " << std::endl;
    getline(std::cin, input);
    while (!is_valid(input)) {
        std::cout << "invalid input" << std::endl;
        input.clear();
        std::cout << "enter " << seq_lenght << " numbers from 0 to 9 "
                  << std::endl;
        getline(std::cin, input);
    }
    return input;
}

bool Game::result_show(std::pair<int, int> result, std::string input)
{
    if (result.first < seq_lenght) {
        std::cout << "\n"
                  << "turn : " << turns << std::endl;
        std::cout << "	bulls : " << result.first << std::endl;
        std::cout << "	cows  :" << result.second << "\n" << std::endl;
        return false;
    } else {
        std::cout << "\n 	You win!" << std::endl;
        std::cout << "your turns : " << turns << "\n" << std::endl;
    }
    return true;
}

bool Game::is_valid(std::string str)
{
    if (str.size() != static_cast<unsigned int>(seq_lenght)) {
        return false;
    }
    for (int i = 0; i < seq_lenght; ++i) {
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