#ifndef GAME
#define GAME
#include <string>
#include <iostream>
#include <vector>
#include "game.h"
#include "sequence.h"

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

void Game::join()
	{
		bool is_game_over = false;
		int lenght = 4;
		char *input = new char[lenght];
		int *result;
		std::string str;
		while (!is_game_over)
		{
			std::cout << "введите " << lenght << " числа от 0 до 9 " << std::endl;
			getline(std::cin , str);
			if (!is_valid(str, lenght))
			{
				std::cout << "некорректный ввод" << std::endl;
				continue;
			}
			turns++;
			for (int i = 0; i < lenght; ++i)
			{
				input[i] = str[i];
			}
			result = sec->count_bulls_and_cows(input, lenght);
			is_game_over = result_check(result);
			delete[] result;
		}
		std::cout << input << " is right answer" << std::endl;
		std::cout << "your turns : " << turns << "\n" << std::endl;
		//leaders_board.compare(turns);  ????
		delete input;
	}


bool Game::result_check(int *result){
		if( result[0] < 4){
				std::cout << "\n" << "turn : " << turns << std::endl;
				std::cout << "	bulls : " << result[0] << std::endl;
				std::cout << "	cows  :" << result[1] << "\n" << std::endl;
				return false;
		}
		else{
			std::cout << "\n 	You win!" << std::endl;
		}
		return true;
	}

bool Game::is_valid(std::string str, int lenght)
	{	
		if( str.size() != static_cast<unsigned int>(lenght)){
			return false;
		}
		for (int i = 0; i < lenght; ++i)
		{
			bool is_suitable_symbol = false;
			for (int j = i - 1; j >= 0; --j)
			{
				if (str[j] == str[i])
				{
					return false;
				}
			}

			for (int j = 0; j < 10; ++j)
			{
				if (str[i] == alphabet[j])
				{
					is_suitable_symbol = true;
					break;
				}
			}
			if (!is_suitable_symbol)
			{
				return false;
			}
		}
		return true;
	}

#endif