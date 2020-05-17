#include "game.h"
#include "sequence.h"

Game::Game()
{
    seq_lenght = 4;
    turns = 0;
}

Game::Game(std::vector<char> in_alph, int lenght)
{
    alphabet = in_alph;
    seq_lenght = lenght;
    turns = 0;
}

Game::~Game()
{
}

void Game::set_lenght(int s)
{
    seq_lenght = s;
}

int Game::play()
{
    Sequence sec(alphabet, seq_lenght);

    bool is_game_over = false;
    std::pair<int, int> result;
    std::string input;
    while (!is_game_over) {
        input = get_input();
        turns++;
        result = sec.count_bulls_and_cows(input);
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
    std::cout << "enter " << seq_lenght << " numbers from 0 to 9 \n";
    getline(std::cin, input);
    while (!is_input_valid(input)) {
        std::cout << "invalid input\n";
        input.clear();
        std::cout << "enter " << seq_lenght << " numbers from 0 to 9 \n";
        getline(std::cin, input);
    }
    return input;
}

bool Game::result_show(std::pair<int, int> result, std::string input)
{
    if (result.first < seq_lenght) {
        std::cout << "\n"
                  << "turn : " << turns << "\n";
        std::cout << "	bulls : " << result.first << "\n";
        std::cout << "	cows  :" << result.second << "\n\n";
        return false;
    } else {
        std::cout << "\n 	You win!\n";
        std::cout << input << " is right answer\n";
        std::cout << "your turns : " << turns << "\n\n";
    }
    return true;
}

bool Game::is_input_valid(std::string str)
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
